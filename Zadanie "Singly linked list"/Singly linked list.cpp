#include <iostream>
#include <vector>
using namespace std;

vector <int> vecInt(2);
struct Point{
	int x,y;
	Point(int valueX, int valueY): x(valueX), y(valueY){}
};

struct Node{
	Point data;
	Node* wsk;
	Node(Point _data): data(_data), wsk(nullptr){}  
};

struct List{
	Node* first; 
	Node* last; 
	List(): first(nullptr), last(nullptr){}
	
    void l_push_front ( Point _data){   //funkcja wstawianie nowego elementu na poczatek
     Node * p = new Node(_data);
     p->data = _data;    // inicjujemy element
     p->wsk = first;
     first = p;
}

    void l_push_back ( Point _data ){  //funkcja wstawianie nowego elementu na koniec
      Node * p, * e; //wskazania elementu listy
       e = new Node(_data);  // tworzymy nowy element
         e->wsk = NULL;   // inicjujemy element
         e->data = _data;
         p = first;
       if(p){
        while( p->wsk ) p = p->wsk;
        p->wsk = e;
       }
     else first = e;
   } 

	void l_insert_after (Node* node, Point point){ //funkcja wstawianie elementu za pierwszym wystąpieniem podanego elementu 
     Node * p = new Node(point);
     p->wsk = node->wsk;
     p->data = point;
     node->wsk = p;
   } 
	
	bool pusta(){return first==nullptr;} //sprawdzanie, czy lista jest pusta 
	
	void Print()  //wypisywanie na ekran elementów listy
	{
		Node* p= first;
		while(p!=nullptr)
		{
			cout<<"("<< p->data.x<<","<<p->data.y<<")"<<endl;
			p=p->wsk;
		}	
		cout<<"========================================"<<endl;
	}
};


int main()
{
	List pierwszy;
	cout<< pierwszy.pusta()<<endl;
	Point a(1,2), b(3,4);
	pierwszy.l_push_back(a);
	pierwszy.l_push_back(b);
	pierwszy.Print();
	pierwszy.l_push_front(b);
	pierwszy.Print();
	pierwszy.l_insert_after(pierwszy.first,Point(28,29));
	pierwszy.Print();
	
	cout<<"========"<<endl;
	cout<< pierwszy.pusta()<<endl; 
	cout<<"========"<<endl;
	
	List spisok1;
	spisok1.l_push_back(Point(0,0));
	spisok1.l_push_back(Point(1,2));
	spisok1.l_push_back(Point(3,4));
	spisok1.l_push_back(Point(5,6));
	spisok1.Print();

	List spisok2;
	spisok2.l_push_back(b);
	spisok2.l_push_back(Point(7,8));
	spisok2.l_push_back(Point(11,12));
	spisok2.Print();
}
