//Maria Babinska
#include <iostream>
#include <cstring>
using namespace std;
int main(){
	int N;
	cin >> N;
	for(int j=0;j<N;j++){	
	string s;
    cin >> s;
    string obratno(s.rbegin(), s.rend());
    cout << obratno << endl;

	}
	}

