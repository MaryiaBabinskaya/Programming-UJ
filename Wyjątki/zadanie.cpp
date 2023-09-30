#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdexcept>
#include <vector>

// Klasa udaje rozmowę z serwerem
class ServerCommunication{
public:
    ServerCommunication(const std::string &hostname): hostname(hostname), connected(false) {}

    void connect();
    void send_message(int msg);
    std::string get_hostname(){
        return hostname;
    }

private:
    std::string hostname;
    bool connected;
};


void ServerCommunication::connect(){
    srand((unsigned)time(NULL));
    if(rand() % 5 == 0) throw std::runtime_error("Connection refused");
    connected = true;
}

void ServerCommunication::send_message(int msg){
    // Dopisać tu rzucanie wyjątku runtime_error("Cannot send message to unconnected server") jeśli connected == false
    if(!connected){
            throw std::runtime_error("Cannot send message to unconnected server");
    }
    if(msg % 2 == 1){
        connected = false;
        throw std::runtime_error("I like only even numbers!");
    }
    else{
        srand((unsigned)time(NULL));
        if(rand() % 5 == 0){
            connected = false;
            throw std::runtime_error("Sometimes I don't even like even numbers!");
        }
    }
}

class Client{
public:
    void add_authorized_server(const std::string &hostname){
        authorized_servers.emplace_back(hostname);
    }
    // Jeśli hostname nie jest zautoryzowany, to rzuca wyjątek runtime_error("Server not authorized")
    // Jeśli hostname jest zautoryzowany, to próbuje użyć connect z ServerCommunication
    // dopóki połączenie nie będzie bez wyjątków lub dopóki liczba prób nie będzie równa
    // num_of_reconnects. W drugim wypadku rzuca runtime_error("Could not connect with server")
    void connect_to_server(const std::string &hostname, int num_of_reconnects=1);
    // Jeśli hostname nie jest zautoryzowany, to rzuca wyjątek runtime_error("Server not authorized")
    // Wywołuje send_message z ServerCommunication. W przypadku nieudanego wysłania
    // próbujemy połączyć się ponownie z serwerem poprzez connect maksymalnie num_of_reconnects
    // razy, jeśli się nie uda to rzuca runtime_error("Server connection lost").
    // Jeśli się uda połączyć ponownie, to próbujemy wysłać wiadomość jeszcze raz (maksymalnie num_of_trials razy),
    // w przypadku porażki postępując jak wyżej. Jeśli nie uda się po num_of_trials razy,
    // to rzucamy runtime_error("Cannot send this message")
    void send_message_to_server(int msg, const std::string &hostname, int num_of_trials=1, int num_of_reconnects=1);

private:
    std::vector<ServerCommunication> authorized_servers;
};

void Client :: connect_to_server (const std::string &hostname, int num_of_reconnects){
    bool czy_authoryzowany = false;
    for(ServerCommunication i: authorized_servers){
        if(i.get_hostname() == hostname){
            czy_authoryzowany = true;
            for ( int k = 1; k <= num_of_reconnects; k++ ){
                if(k != num_of_reconnects){
                    try {
                        i.connect();
                    }
                    catch (...) {
                        continue;
                    }
                }
                if(k == num_of_reconnects){
                    try {
                        i.connect();
                    }
                    catch (...) {
                        throw std::runtime_error("Could not connect with server");
                    }
                }
                break;
            }
            break;
        }
    }
    if(!czy_authoryzowany){
        throw std::runtime_error("Server not authorized");
    }
}
void Client :: send_message_to_server(int msg, const std::string &hostname, int num_of_trials, int num_of_reconnects){
    bool czy_authoryzowany = false;
    for (ServerCommunication i: authorized_servers){
        if (i.get_hostname() == hostname){
            czy_authoryzowany = true;
            try{
                i.send_message(msg);
            }
            catch (...){
                bool czy_udalo_poloczyc = false;
                for (int k = 1; k <= num_of_reconnects; k++) {
                    if (k != num_of_reconnects)
                        try {
                          i.connect();
                        }
                        catch (...) {
                          continue;
                        }
                    if (k == num_of_reconnects){      
                        try {
                            i.connect();
                        }
                        catch (...) {
                            throw std::runtime_error("Server connection lost");
                        }
                    }
                    czy_udalo_poloczyc=true;
                    break;
                }
                if(czy_udalo_poloczyc){
                    for (int k = 1; k <= num_of_trials; k++){
                        if (k != num_of_trials) {
                            try {
                                i.send_message(msg);
                            }
                            catch (...) {
                                continue;
                            }
                        }else{     
                            try {
                                i.send_message(msg);
                            }
                            catch (...){
                                throw std::runtime_error("Cannot send this message");
                            }
                        }
                        break;      //jezeli wiadomsc to stop
                    }
                }
            }
            break;
        }
    }
    if(!czy_authoryzowany){
        throw std::runtime_error("Server not authorized");
    }
}
int main(){
    Client c;
    c.add_authorized_server("a");
    c.send_message_to_server( 2, "a"); // tu spodziewamy się wyjątku, bo nie połączyliśmy się z serwerem
    c.connect_to_server("a"); // tu może być wyjątek
    c.send_message_to_server(2, "a"); // tu może być wyjątek
    c.send_message_to_server(2, "b"); // tu spodziewamy się wyjątku, bo nie ma serwera b
    c.send_message_to_server(1, "a"); // tu spodziewamy się wyjątku, bo nasz serwer nie lubi liczb nieparzystych
}
