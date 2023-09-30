#include <iostream>
#include <cstdlib>
using namespace std;
int main(){
	int n;
	cin>>n;

	int *tab1=(int*)malloc(n*sizeof(int));  

	for(int i=0;i<n;i++){    
	  int r=rand()%10+1;
	  tab1[i]=r;
	}

	int **tab2=(int**)malloc(n*sizeof(int*));   
	  
	for(int i=0;i<n;i++){
	  tab2[i]=(int*)malloc(tab1[i]*sizeof(int));
	}  
	  
	for(int i=0;i<n;i++){             
		for(int j=0;j<tab1[i];j++){
			tab2[i][j]=10*i+j;
			cout<<tab2[i][j]<<" ";
	  }
	  cout<<endl;
	}
	  
	  cout<<endl;
	  
	int minr, minc, maxr, maxc;
	cin >> minr >> minc >> maxr >> maxc;
	
	int promezhutok = maxc-minc+1;
	
	for(int i=minr;i<=maxr;i++){             
		for(int j=minc;j+maxc<tab1[i];j++){  
			tab2[i][j]=tab2[i][promezhutok+j];	
		}
		
		///////////////
		if(tab1[i]<minc){
		  tab1[i]=tab1[i];
	    }
	    else if(tab1[i]<=maxc){
		  tab1[i]=minc;
	    }
		else if(minc==tab1[i] && tab1[i]<minc){ //вообще не трогает
			tab1[i]=tab1[i];
		     }
		else { //if(tab1[i]>maxc)
		  tab1[i]=tab1[i]-(maxc-minc+1);
		}
		////////////////////
	}
	
	int liczba0=0;
	
	for(int i=0;i<n;i++){
		if(tab1[i]<=0){
			liczba0++;
		}
	}
                                                                                                                                                                                                                                                                                                                                                                           
	int wysokosc=n-liczba0;
	
	for(int i=0; i<wysokosc;i++){
		if(tab1[i]<=0){
			
		 int index=0;
		 
			for(int j=i+1;j<n;j++){
				if(tab1[j]>0){
					index=j;
					break;
				}
			}
		   if(index!=0){
			 for(int k=0;k+index<n;k++){
				tab1[i+k]=tab1[index+k];
				 tab2[i+k]=(int*)realloc(tab2[i+k],tab1[i+k]*sizeof(int));
				
			     for(int j=0;j<tab1[i+k];j++){
					tab2[i+k][j]=tab2[index+k][j];
			     }

             }				
           }
		}
	}
	
	  for(int i=wysokosc;i<n;i++){
		free(tab2[i]);
	  }
		
	  for(int i=0;i<wysokosc;i++){            
		for(int j=0; j<tab1[i];j++){
			cout<<tab2[i][j]<<" ";
	    }
	    cout<<endl;
	  }

	   free(tab1);            
	  for(int i=0;i<n;i++){
	   free(tab2[i]);
	  }
	   free(tab2);

  }
