//Maria Babinska
#include <iostream>
using namespace std;
int main(){
	int N;
	cin >> N;
	
	for(int i=0; i<N; i++){
	int m1, m2, m3, m4, m5, m6;
	float P;
	int L;
    cin >> L >> m1 >> m2 >> m3 >> m4 >> m5 >> m6;
    P=(m1+m2+m3+m4+m5+m6)/6.0;
    if(P>=0 && P<=50){
		cout << L << ":" << " " << "ndst" << endl; 
		}
    if(P>50 && P<=60){
		cout << L << ":" << " " << "dst" << endl; 
		}
    if(P>60 && P<=70){
		cout << L << ":" << " " << "dst+" << endl; 
		}
    if(P>70 && P<=80){
		cout << L << ":" << " " << "db" << endl; 
		}
	if(P>80 && P<=90){
		cout << L << ":" << " " << "db+" << endl; 
		}	
	if(P>90 && P<=100){
		cout << L << ":" << " " << "bdb" << endl; 
		}	

    }
	}
