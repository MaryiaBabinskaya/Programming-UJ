//Maryia Babinskaya
#include "Morfologia.h"
#include <iostream> 
#include <vector>
using namespace std;
class BitmapaExt : public Bitmapa {
	public:
	   unsigned x, y, z;
	   bool ***tab;
	    BitmapaExt(unsigned zakresX, unsigned zakresY, unsigned zakresZ); //konstruktor ktory tworzy bitmape (bialy color)
	   ~BitmapaExt(); 
	   unsigned sx() const;
	   unsigned sy() const;
	   unsigned sz() const;
	   BitmapaExt (const BitmapaExt& b); //kopiujacy
	   BitmapaExt& operator=(const BitmapaExt& b); //przypisania
	   bool& operator()(unsigned x, unsigned y, unsigned z);
       bool operator()(unsigned x, unsigned y, unsigned z) const;
};	   
	   BitmapaExt::BitmapaExt(unsigned zakresX, unsigned zakresY, unsigned zakresZ){ //konstruktor ktory tworzy bitmape (bialy color)
		   x = zakresX;
		   y = zakresY;
		   z = zakresZ;
		   tab = new bool **[x];
		   for(unsigned q0 = 0; q0 < x; q0++){
			   tab[q0]=new bool *[y];
			   for (unsigned q1 = 0; q1 < y; q1++){
				   tab[q0][q1]=new bool[z];
				   for (unsigned q2 = 0; q2 < z; q2++){
					   tab[q0][q1][q2] = false; 
				   }
			   }
		   }
	  } 
	BitmapaExt::BitmapaExt(const BitmapaExt& b) : //konstruktor kopiujacy   
     x(b.x),y(b.y),z(b.z),tab(new bool **[x]) {
      for(unsigned q0 = 0; q0 < x; q0++){
			   tab[q0]=new bool *[y];
			   for (unsigned q1 = 0; q1 < y; q1++){
				   tab[q0][q1]=new bool[z];
				   for (unsigned q2 = 0; q2 < z; q2++){
					   tab[q0][q1][q2] = b(q0,q1,q2); 
				   }
			   }
      }
    } 
	 unsigned BitmapaExt :: sx() const{
		 return x;
	   }
	 unsigned BitmapaExt :: sy() const{
	     return y;
	   }
	 unsigned BitmapaExt :: sz() const{
		 return z;
	   }
	   bool& BitmapaExt::operator()(unsigned x, unsigned y, unsigned z){
		 return tab[x][y][z];
	   }
	   bool BitmapaExt::operator()(unsigned x, unsigned y, unsigned z) const{
		   return tab[x][y][z];
	   } 
	   BitmapaExt :: ~BitmapaExt() { 
		   for(unsigned q0 = 0; q0 < x; q0++){
			   for (unsigned q1 = 0; q1 < y; q1++){
				   delete[] tab[q0][q1];
			   }
			   delete[] tab[q0];
		   }		   
		   delete[] tab;
		   //delete tab; /////////////////////////////////////////////////
	   } 
	   
  BitmapaExt& BitmapaExt::operator=(const BitmapaExt& b){ 
	    if (this == &b){
          return *this;
        }
        else{
          for(unsigned q0 = 0; q0 < x; q0++){
			   for (unsigned q1 = 0; q1 < y; q1++){
				   delete[] tab[q0][q1];
			   }
			   delete[] tab[q0];
		   }		   
		   delete[] tab;
          x = b.x;
          y = b.y;
          z = b.z;
          tab = new bool **[x];
		   for(unsigned q0 = 0; q0 < x; q0++){
			   tab[q0]=new bool *[y];
			   for (unsigned q1 = 0; q1 < y; q1++){
				   tab[q0][q1]=new bool[z];
				   for (unsigned q2 = 0; q2 < z; q2++){
					   tab[q0][q1][q2] = false; 
				   }
			   }
		   }
       }
    return *this;
 } 
	   
 std::ostream &operator <<(std::ostream &stream, const Bitmapa &b){	
	stream << "{" << "\n"; 
	unsigned x = b.sx();
	unsigned y = b.sy();
	unsigned z = b.sz();
    for(unsigned q0=0; q0<x; q0++){
		stream << " {" << "\n";
		   for(unsigned q1=0; q1<y; q1++){
		      stream << "  {";
		        for(unsigned q2=0; q2<z; q2++){
		           stream << b(q0,q1,q2);
		           if (q2!=z-1) stream<<",";
			    }
		      stream << "}";
		      if(q1!=y-1) stream << "," << "\n";
		      else stream << "\n";
	       } 
		if(q0!= x-1) stream << " }," <<"\n";
		else stream << " }" <<"\n";
	}
	stream << "}";
	return stream;
}
class Inwersja : public Przeksztalcenie {
	public:
	 void przeksztalc( Bitmapa& );   
};	
void Inwersja :: przeksztalc ( Bitmapa& b ){
	 for(unsigned q0 = 0; q0 < b.sx(); q0++){
			   for (unsigned q1 = 0; q1 < b.sy(); q1++){
				   for (unsigned q2 = 0; q2 < b.sz(); q2++){
					    if(b(q0,q1,q2)==true) b(q0,q1,q2)=false;
					    else b(q0,q1,q2)=true;
				   }
			   }
	 }
}
class Erozja : public Przeksztalcenie {
	public:
	  void przeksztalc( Bitmapa& ); 
};
void Erozja :: przeksztalc ( Bitmapa& b ){ //6test
	unsigned xxx=b.sx();
    unsigned yyy=b.sy();
    unsigned zzz=b.sz();
	vector < unsigned > tabPunkt;
     for(unsigned q0 = 0; q0 < xxx; q0++){  
			   for (unsigned q1 = 0; q1 < yyy; q1++){
				   for (unsigned q2 = 0; q2 < zzz; q2++){
					    if(b(q0,q1,q2)==1){
						   
					       if( q2 + 1 < zzz && b(q0,q1,q2+1)==0 ){ 
					        tabPunkt.push_back(q0); 
					        tabPunkt.push_back(q1); 
					        tabPunkt.push_back(q2); 
					       }
					       else if( q2 != 0 && b(q0,q1,q2-1)==0 ){   
					        tabPunkt.push_back(q0); 
					        tabPunkt.push_back(q1); 
					        tabPunkt.push_back(q2); 
					       }
					       else if( q1 + 1 < yyy && b(q0,q1+1,q2)==0 ){  
					        tabPunkt.push_back(q0); 
					        tabPunkt.push_back(q1); 
					        tabPunkt.push_back(q2);   
					       }
					       else if( q1 != 0 && b(q0,q1-1,q2)==0 ){  
					        tabPunkt.push_back(q0); 
					        tabPunkt.push_back(q1); 
					        tabPunkt.push_back(q2);   
					       }
					       else if( q0 != 0 && b(q0-1,q1,q2)==0 ){  
					        tabPunkt.push_back(q0); 
					        tabPunkt.push_back(q1); 
					        tabPunkt.push_back(q2);  
					       }
					       else if( q0 + 1< xxx && b(q0+1,q1,q2)==0 ){  
					        tabPunkt.push_back(q0); 
					        tabPunkt.push_back(q1); 
					        tabPunkt.push_back(q2);   
					       }
					    }
				   }
			   }	   
	 }
	vector<unsigned>::iterator i;
    for (i=tabPunkt.begin(); i!=tabPunkt.end(); i++){
        unsigned x_ = *i;
		i++;
		unsigned y_ = *i;
		i++;
		unsigned z_ = *i;
		b(x_,y_,z_)=0;
    }
     tabPunkt.clear();
}
class Dylatacja : public Przeksztalcenie {
	public:
	 void przeksztalc( Bitmapa& );  
};
void Dylatacja :: przeksztalc ( Bitmapa& b ){ //6 test
    unsigned xxx=b.sx();
    unsigned yyy=b.sy();
    unsigned zzz=b.sz();
	vector < unsigned > tabPunkt;
     for(unsigned q0 = 0; q0 < xxx; q0++){
			   for (unsigned q1 = 0; q1 < yyy; q1++){
				   for (unsigned q2 = 0; q2 < zzz; q2++){
					    if(b(q0,q1,q2)==0){
						   
					       if( q2 + 1 < zzz && b(q0,q1,q2+1)==1 ){ 
					        tabPunkt.push_back(q0); 
					        tabPunkt.push_back(q1); 
					        tabPunkt.push_back(q2); 
					       }
					       else if( q2 != 0 && b(q0,q1,q2-1)==1 ){   
					        tabPunkt.push_back(q0); 
					        tabPunkt.push_back(q1); 
					        tabPunkt.push_back(q2); 
					       }
					       else if( q1 + 1 < yyy && b(q0,q1+1,q2)==1 ){  
					        tabPunkt.push_back(q0); 
					        tabPunkt.push_back(q1); 
					        tabPunkt.push_back(q2);   
					       }
					       else if( q1 != 0 && b(q0,q1-1,q2)==1 ){  
					        tabPunkt.push_back(q0); 
					        tabPunkt.push_back(q1); 
					        tabPunkt.push_back(q2);   
					       }
					       else if( q0 != 0 && b(q0-1,q1,q2)==1 ){  
					        tabPunkt.push_back(q0); 
					        tabPunkt.push_back(q1); 
					        tabPunkt.push_back(q2);  
					       }
					       else if( q0 + 1< xxx && b(q0+1,q1,q2)==1 ){  
					        tabPunkt.push_back(q0); 
					        tabPunkt.push_back(q1); 
					        tabPunkt.push_back(q2);   
					       }
					    }
				   }
			   }	   
	 }
	vector<unsigned>::iterator i;
    for (i=tabPunkt.begin(); i!=tabPunkt.end(); i++){
        unsigned x_ = *i;
		i++;
		unsigned y_ = *i;
		i++;
		unsigned z_ = *i;
		b(x_,y_,z_)=1;
    }
     tabPunkt.clear();
}
class Zerowanie : public Przeksztalcenie {
	public:
	  void przeksztalc( Bitmapa& ); 	   
};
void Zerowanie :: przeksztalc ( Bitmapa& b ){  //7test
	 for(unsigned q0 = 0; q0 < b.sx(); q0++){
			   for (unsigned q1 = 0; q1 < b.sy(); q1++){
				   for (unsigned q2 = 0; q2 < b.sz(); q2++){
					    b(q0,q1,q2)=false;
				   }
			   }
	 }
}
class Usrednianie : public Przeksztalcenie {
	public:
	  void przeksztalc( Bitmapa& ); 	   
};
void Usrednianie :: przeksztalc ( Bitmapa& b ){ //6 test
    unsigned xxx=b.sx();
    unsigned yyy=b.sy();
    unsigned zzz=b.sz();
	vector < unsigned > tabPunkt1; //0->1
	vector < unsigned > tabPunkt2; //1->0
	unsigned counter = 0;
     for(unsigned q0 = 0; q0 < xxx; q0++){
			   for (unsigned q1 = 0; q1 < yyy; q1++){
				   for (unsigned q2 = 0; q2 < zzz; q2++){
					    if(b(q0,q1,q2)==0){ //jezeli bialy
					       if( q2 + 1 < zzz && b(q0,q1,q2+1)==1 ){ 
					        counter++;
					       }
					       if( q2 != 0 && b(q0,q1,q2-1)==1 ){   
					         counter++; 
					       }
					       if( q1 + 1 < yyy && b(q0,q1+1,q2)==1 ){  
					         counter++;   
					       }
					       if( q1 != 0 && b(q0,q1-1,q2)==1 ){  
					         counter++;
					       }
					       if( q0 != 0 && b(q0-1,q1,q2)==1 ){  
					         counter++; 
					       }
					       if( q0 + 1< xxx && b(q0+1,q1,q2)==1 ){  
					         counter++;;   
					       }
					       if(counter > 3){
							tabPunkt1.push_back(q0); 
					        tabPunkt1.push_back(q1); 
					        tabPunkt1.push_back(q2);
						   }
						   counter = 0;
					       
					    } else { //jezeli czarny
							if( q2 + 1 < zzz && b(q0,q1,q2+1)==0 ){ 
					        counter++;
					       }
					       if( q2 != 0 && b(q0,q1,q2-1)==0 ){   
					         counter++; 
					       }
					       if( q1 + 1 < yyy && b(q0,q1+1,q2)==0 ){  
					         counter++;   
					       }
					       if( q1 != 0 && b(q0,q1-1,q2)==0 ){  
					         counter++;
					       }
					       if( q0 != 0 && b(q0-1,q1,q2)==0 ){  
					         counter++; 
					       }
					       if( q0 + 1< xxx && b(q0+1,q1,q2)==0 ){  
					         counter++;;   
					       }
					       if(counter > 3){   
							tabPunkt2.push_back(q0); 
					        tabPunkt2.push_back(q1); 
					        tabPunkt2.push_back(q2);
						   }
						   counter = 0;
						}
				   }
			   }	   
	 }
	vector<unsigned>::iterator i;
    for (i=tabPunkt1.begin(); i!=tabPunkt1.end(); i++){
        unsigned x_ = *i;
		i++;
		unsigned y_ = *i;
		i++;
		unsigned z_ = *i;
		b(x_,y_,z_)=1;
    }
     tabPunkt1.clear();
     for (i=tabPunkt2.begin(); i!=tabPunkt2.end(); i++){
        unsigned x_ = *i;
		i++;
		unsigned y_ = *i;
		i++;
		unsigned z_ = *i;
		b(x_,y_,z_)=0;
    }
     tabPunkt2.clear();
}
	
class ZlozeniePrzeksztalcen : public Przeksztalcenie {
	public:
	vector < Przeksztalcenie * > komandy;
	void dodajPrzeksztalcenie(Przeksztalcenie* p){
		this->komandy.push_back(p);
	}
	void przeksztalc (Bitmapa& b){
		for(Przeksztalcenie* przec : komandy){
           przec->przeksztalc(b);
        }
	  this->komandy.clear();
	}
	~ZlozeniePrzeksztalcen(){ komandy.clear(); }
};

