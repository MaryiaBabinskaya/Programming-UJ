//Maryia Babinskaya
#include <iostream>
#include <cstdlib>
using namespace std;
int main(){
	
	int N;       //skolko stroczek
	cin >> N;
	
	 int *tab1=(int*)malloc(N*sizeof(int));   //create pomocnicza 1D there we save our kol-vo elemntow w stroczke
	 int **tab2=(int**)malloc(N*sizeof(int*)); //create 2D tablice
	
	  for(int i=0;i<N;i++){
	      int dlugoscwierszy;
	        cin >> dlugoscwierszy;
	        *(tab1+i)=dlugoscwierszy;
            *(tab2+i)=(int*)malloc(dlugoscwierszy*sizeof(int));
         
	          for(int j=0;j<dlugoscwierszy;j++){
			    cin>>*(*(tab2+i)+j);               //zapolniaem 2D tablicu
		      }
      }
           
    char litera; 
                          
   while(litera!='E'){   //E-koniec działania programu
		cin>> litera;  



    	//P                       wypisanie aktualnej zawartości tablicy na standardowe wyjście
      if(litera == 'P'){	
        for (int i = 0; i < N; i++) {
         for(int j=0;j<*(tab1+i);j++){
		       cout<<*(*(tab2+i)+j)<<" ";
		 }      
         cout<<endl;
        }  
       cout<<endl;     
      }
    
  
   
     //R                   R n - usunięcie wiersza o numerze n
    if(litera == 'R'){	
         int n;
         cin >> n;
         //free(*(tab2+n));        ??? zaczem    2D tablica freekajetsia s pomocy for()...
         
       for(int k=n;k<=N-1;k++){   //perepis elementow
		*(tab2+k)=*(tab2+k+1);
       }	   
         
       for(int j=n; j<=N-1 ; j++){
	    *(tab1+j)=*(tab1+(j+1));	   
       }	

   (tab1)=(int*)realloc((tab1),(N-1)*sizeof(int)); //delete ostatni rzad
   (tab2)=(int**)realloc((tab2),(N-1)*sizeof(int*));
	N = N - 1;
    }    

        
      //S
    if(litera == 'S'){	   //S n m - zamiana miejscami wierszy o numerach n i m.
         int n,m;
         cin >> n >> m;
         
         int *tabS0=*(tab2+n);    //swap dla 2D
         *(tab2+n)=*(tab2+m);
         *(tab2+m)= tabS0;
    
    int tabS00 = *(tab1+n);       //swap dla 3D
    *(tab1+n)=*(tab1+m);
    *(tab1+m)=tabS00;

    }   
         
     //D              D n - podwojenie wiersza o numerze n
    if(litera == 'D'){	
     int n;
     cin >> n;
     int ile_elementow=*(tab1+n);
     *(tab2+n)=(int*)realloc(*(tab2+n),ile_elementow * 2 *sizeof(int));
        for(int i=0;i<ile_elementow;i++){
		  *(*(tab2+n) + i + ile_elementow)=*(*(tab2+n) + i); //pozycja n wiersza zostaje, a i zmiena(idziemy po kolumnach)     
		}
	 *(tab1+n)=*(tab1+n)*2;//zmienili tab1
    }      
     
   //A                     A n - dodanie na końcu tablicy nowego wiersza będącego kopią wiersza o numerze n.
    if(litera == 'A'){	
     int n;
     cin >> n;
     
        tab2=(int**)realloc(tab2,(N+1)*sizeof(int*));  
        tab1=(int*)realloc(tab1,(N+1)*sizeof(int)); 
     *(tab1+N)=*(tab1+n);
	 *(tab2+N)=(int*)malloc(*(tab1+n)*sizeof(int)); //w konce(pomnim czto sczet s 0) N malloc pod rozmiar wybrannogo wiersza

     for(int i=0; i<*(tab1+n);i++){
		*(*(tab2+N)+i)=*(*(tab2+n)+i);//perepis znaczenij
     }    
     N =N + 1;
    
      }
      
       /*     //I     I n m k - zawartość wiersza o numerze n zostaje wstawiona do wiersza o numerze m poczynając od pozycji k
     
     if(litera == 'I'){	
         int n,m,k;
         cin >> n >> m >> k;
            *(tab2+m)=(int*)realloc(*(tab2+m),(*(tab1+n)+(*tab1+m))*sizeof(int));
            *(tab1+m)=*(tab1+m)+*(tab1+n);
                for(int i=0;i<*(tab1+m);i++){
		          *(*(tab2+m)+(i+k)+*(tab1+n))=*(*(tab2+m)+(i+k));
                 }       
                for(int i=0;i<*(tab1+n);i++){
		          *(*(tab2+m)+(i+k))=*(*(tab2+n)+i);	
                }   
           ??? free(*(tab2+n)); ??? zaczem, ty tak nie udalisz
            * 
                for(int i=n; i<N-1; i++){   ?????????
		          *(tab1+i)=*(tab1+i+1);    ?????????
		          *(tab2+i)=*(tab2+i+1);	????????? 
                }
     tab2=(int**)realloc(tab2,(N-1)*sizeof(int*));
     tab1=(int*)realloc(tab1,(N-1)*sizeof(int));

         N=N-1; 
    }
 */        
        
    }
    
   free(tab1);
   for(int i=0;i<N;i++){
      free (*(tab2+i));
   }
   free(tab2);
   
} 

    
    
  
    
    

