#include<iostream>

using namespace std;

class Marsjanie{

	public:
		static int counter;
		Marsjanie(){counter++;}
		~Marsjanie(){counter--;}
		void attack();

};

int Marsjanie::counter = 0;

void Marsjanie::attack(){
	if(counter>5){
		cout << "Attack" << endl;
	}
	else{
		cout<< "Hide" << endl;
	}
}	 

struct ForwardList{
	Marsjanie *m;
	struct ForwardList *next;
};

void DestroyLast(ForwardList *list){
	
	ForwardList *tmp = list;
	if(tmp!=NULL){
		while(tmp->next->next!=NULL){
			tmp=tmp->next;
		}
		delete tmp->next->m;
		tmp->next=NULL;
	}
	return;
}

void PushFront(ForwardList *list){
	
	Marsjanie *m = new Marsjanie;
	ForwardList *tmp = new ForwardList;
	tmp->next=list;
	tmp->m=m;
	list=tmp;
	return;
}

int main(){

	ForwardList *list;
	list==NULL;
	Marsjanie *m1 = new Marsjanie;

	//while(){
		PushFront(list);
		PushFront(list);
		PushFront(list);
		m1->attack();
		PushFront(list);
		PushFront(list);
		m1->attack();
		DestroyLast(list);
		DestroyLast(list);
		cout << m1->counter << endl;
	//}

return 0;
}