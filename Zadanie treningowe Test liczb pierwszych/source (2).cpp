// Maria Babinska
#include <iostream>
using namespace std;
int main(){
	int n, liczba;
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >> liczba;
		if(liczba==2){
			cout<<"TAK"<<endl;
			}
		if(liczba==1){
			cout<<"NIE"<<endl;
			}
			
		if(liczba!=1 && liczba!=2){	
		for(int k=2;k<=(liczba-1);k++){
		if( (liczba%k)==0 ){
			cout << "NIE" <<endl;
			break;
			}
			if ((liczba%k)!=0 && k==liczba-1) {
				cout<<"TAK"<<endl;
				break;
			}}}
			}
	}
