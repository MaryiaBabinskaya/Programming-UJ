//Maryia Babinskaya
#include <cstdarg>
#include <cstdio>
////////////////////////////////////////////////////////////////////////
char przeksztalc(char *s, char (*f)(char)){  //Zadaniem funkcji przeksztalc jest zamiana każdego 
	                                         //znaku napisu s na wartość funkcji f obliczonej dla tego znaku.
	if(f==0){return 0;}
	if(s==0){return 0;}
	else{
	while(*s){                         //do konca linii(Nazwa tablicy jest wskaźnikiem i służy do przejscia przez wszystkie elementy.
                                       //Gdy tylko wyrażenie w nawiasach stanie fałszywe, pętla się zatrzyma.)
		*s=f(*s);
		s++;                           //przesuwam wskaznik na nastepny element
		}
		return *s;
    }
}
////////////////////////////////////////////////////////////////////////
char filtruj(char *s, bool(*f)(char)){     //Zadaniem funkcji filtruj jest usunięcie z napisu tych znaków, 
	                                       //dla których funkcja f zwraca true. Usunięcie znaku oznacza, 
	                                       //ze następujące po nim znaki są przesuwane w lewo o jedną pozycję.
	if(f==0) return 0;
	if(s==0){return 0;}
	char *dopolnitelno= new char;
	dopolnitelno = s;
	while(*dopolnitelno){
		if(f(*dopolnitelno)==false){      //zappolniajem s nuzhnymi elementami
		*s = *dopolnitelno;
		s++;
		}
	dopolnitelno++;
	}
	while(*s){     //cut nienuzhne litery w koncu lamakotaota->lamakota
		*s = '\0';
		s++;
		}
	
	return *s; 
}
////////////////////////////////////////////////////////////////////////
char filtruj(char *s, char *k){ //Zadaniem funkcji filtruj jest usunięcie z napisu s wszystkich znaków, które występują w napisie k.
	if(s==0){return 0;}
	if(k==0){return 0;}
 while (*k){
	 char *dopolnitelno= new char;  //nowy arr       
	 dopolnitelno = s;
	 float sczetczik=0;
	   while(*dopolnitelno){
		if(*k!=*dopolnitelno){   //perepisywajet tolko nuzhnoe
		*s = *dopolnitelno;
		s++;
	    sczetczik+=1;
		}
	    dopolnitelno++;
	   }
     while(*s){     //obrezajet Al m kttata->Al m kt
		*s = '\0';
		s++;
	 }  
	 while(sczetczik){ //wsk znow na napisie na poczatku
		s--;           //przesuwam wskaznik na poprzedni element
		sczetczik-=1;
     }
		k++;	
 }
   return *s;
}
////////////////////////////////////////////////////////////////////////
bool filtruj(char **b, char **e, bool(*f)(char)){
   if(f==0){return false;}
   if(b==0){return false;}
   if(e==0){return false;}
   
   bool ostateczna = false;
   char *b1 = *b;
   while(b1!=*e){ 
	   
	   char *dopolnitelno=b1;
	   while(*dopolnitelno){
		   
		   if(f(*dopolnitelno))
		   ostateczna=true;
		   
		   else{
			   *b1=*dopolnitelno;
			   b1++;
			   } 
			   
		   dopolnitelno++; 
	   }
	    
	   *b1='\0';           //obrezali bukwy w konce
	   b++;
	   b1=*b;
   }
 
    return ostateczna;
    
}
		
		

bool zostawMalaLitere(char c){
  return (c<'a' or c>'z');
}

int main(){
  char s1[] = "Ala ma kota!";
  char s2[] = "Kot ma Ale?";
  char* s[] = {s1,s2};
  int d = filtruj(s,s+2,zostawMalaLitere);
  printf("%s, %s, %d\n",s[0],s[1],d);
  return 0;
}
