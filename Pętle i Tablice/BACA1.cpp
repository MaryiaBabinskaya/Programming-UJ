// Maria Babinska
#include <iostream>
using namespace std;
int main(){
	
	int M;                 //określenie początkowego rozmiaru tablicy                    
	cin >> M;              //M*M rozmiar planszy
	
	int static t[1024][1024]; 
    int sum=0;             //poczatkowa suma
 


    for (int i = 0; i < M; i++){    //wstawiamy 0 na all positions in our pole
	  for (int j = 0; j < M; ++j){
	    t[i][j] = 0;                   
	  }
	}

	
    char litera_1;                       
	while(litera_1!='K'){    //while nie K, bo K ostanowie gre
	  cin>> litera_1;        //wwodim naszu literu


	//C
    if(litera_1 == 'C'){   //Operacja ta ma za zadanie wczytać ze standardowego wejścia nową planszę gry. 
		                   //Jej rozmiar jest podany jako parametr M.
		                   //Po nim następuje M2 liczb oddzielonych spacjami, które należy wczytać do kolejnych wierszy planszy
		
	  cin >> M;
	
       for (int i = 0; i < M; i++) {
           for (int j = 0; j < M; j++) {
              cin >> t[i][j]; 
           }
       }  
   }

    //L                                   wykonuje operację przesunięcia w lewo wszystkich elementów na planszy
    if(litera_1 == 'L'){             
	 for(int all=0;all<M;all++){
			
          for(int i=0;i<M;i++){          //0 na koniec
            for(int j=0;j<M;j++){ 
               for(int l=j+1;l<M;){ 
                    if(t[i][j]==0 && t[i][l]!=0){ 
                         t[i][j]=t[i][l]; 
                         t[i][l]=0; 
                    } 
                    else l++; 
          }}} 
      
         for(int i=0;i<M;i++){           // skladywalo
           for(int j=0;j<M;j++){ 
             if(t[i][j]==t[i][j+1]){ 
                t[i][j]=t[i][j]+t[i][j+1]; 
                t[i][j+1]=0; 
         }}}
      }
     }
 
	//S                                należy wypisać na standardowe wyjście sumę wszystkich liczb znajdujących się aktualnie na planszy
	if (litera_1 == 'S'){
	 for (int i = 0; i < M; i++){
	  for (int j = 0; j < M; j++){ 
	    sum=sum+t[i][j];                        
	  }
	 }
	 cout<<sum<<endl;
	 sum=0;
	}
	
	//N       N x y w, gdzie x, y to liczby naturalne mniejsze niż M,
    //        natomiast w jest pewną liczbą naturalną nie większą niż 216.
    //        Polecenie to wstawia wartość w na pozycję (x,y) w planszy
	if(litera_1 == 'N'){
	   int x,y;
	   long int w;
	   cin >> x >> y >> w;
	   t[x][y]=w;
	}                     
 
    //P                         wykonuje operację przesunięcia w prawo wszystkich elementów na planszy(analogicznie jak L)
  if(litera_1 == 'P'){ 
	for(int all=0;all<M;all++){    
            for(int i=0;i<M;i++){ 
              for(int j=M-1;j>=0;j--){ 
                 for(int l=j-1;l>=0;){ 
                   if(t[i][j]==0 && t[i][l]!=0){ 
                     t[i][j]=t[i][l]; 
                     t[i][l]=0; 
                   } 
                   else l--; 
            }}} 
            
            for(int i=0;i<M;i++){ 
              for(int j=M-1;j>=0;j--){ 
                if(t[i][j]==t[i][j-1]){ 
                 t[i][j]=t[i][j]+t[i][j-1]; 
                 t[i][j-1]=0; 
            }}}
    }
  }

    //G                               wykonuje operację przesunięcia w górę wszystkich elementów na planszy
    if(litera_1 == 'G'){
		for(int all=0;all<M;all++){ 
			
            for(int i=0;i<M;i++){ 
               for(int j=0;j<M;j++){ 
                 for(int l=i+1;l<M;){ 
                    if(t[i][j]==0 && t[l][j]!=0){ 
                    t[i][j]=t[l][j]; 
                    t[l][j]=0; 
                    } 
                    else l++; 
            }}} 
      
            for(int i=0;i<M;i++){ 
              for(int j=0;j<M;j++){ 
                if(t[i][j]==t[i+1][j]){ 
                t[i][j]=t[i][j]+t[i+1][j]; 
                t[i+1][j]=0; 
            }}}
        }
     }

    //D                          wykonuje operację przesunięcia w dół wszystkich elementów na planszy
    if(litera_1 == 'D'){   
		         for(int all=0;all<M;all++){
					 
                     for(int i=M-1;i>=0;i--){ 
                       for(int j=0;j<M;j++){ 
                         for(int l=i-1;l>=0;){ 
                            if(t[i][j]==0 && t[l][j]!=0){ 
                            t[i][j]=t[l][j]; 
                            t[l][j]=0; 
                            } 
                            else l--; 
                     }}} 
      
                     for(int i=M-1;i>=0;i--){ 
                       for(int j=0;j<M;j++){ 
                         if(t[i][j]==t[i-1][j]){ 
                         t[i][j]=t[i][j]+t[i-1][j]; 
                         t[i-1][j]=0; 
                     }}}
                 }
     }

    //W                              należy wypisać na standardowe wyjście aktualny stan planszy
      if(litera_1 == 'W'){ 
		   for (int i = 0; i < M; i++){                                                                                       
            for (int j = 0; j < M; j++){                
             cout << t[i][j] << " ";   
                       
             if (j == M-1)
             cout << endl; 
            }
           }
      }                          

	//K               po napotkaniu tego polecenia należy wydrukować na standardowe wyjście sumę 
	//                wszystkich liczb znajdujących się aktualnie na planszy, a po niej znak końca linii
	//                oraz zakończyć działanie programu
    if(litera_1 == 'K'){
	    for (int i = 0; i < M; i++){
	      for (int j = 0; j < M; ++j){ 
	        sum=sum+t[i][j];                        
	    }}
	  cout<<sum<<endl;
	}


}
}







