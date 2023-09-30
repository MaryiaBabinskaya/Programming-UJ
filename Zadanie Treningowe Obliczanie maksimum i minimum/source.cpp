//Maria babinska


#include <iostream> 
using namespace std;
int main(){
	int n,a,b,c;
	int max;
	int min;
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>a>>b>>c;
	
		
   if(a>=b && a>=c){
		 max=a;
		 }
   if(b>=a && b>=c){
		 max=b;
		 }
   if(c>=b && c>=a){
		 max=c;
		 }
		 
    if(b>=a && c>=a){
		 min=a;
		 }
	if(a>=b && c>=b){
		 min=b;
		 }
    if(b>=c && a>=c){
		 min=c;
		 }	
		 cout<<min<<" "<<max <<endl;  
	}	 
	 
	  
	 }
