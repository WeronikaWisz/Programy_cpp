#include<iostream>
using namespace std;

struct ForwardList{
	int value;
	struct ForwardList *next;
};

ForwardList *CreateNode(int value){
	
	ForwardList *node = new ForwardList;
	node->value=value;
	node->next=NULL;
	return node;
}

void DestroyList(ForwardList *list){
	
	ForwardList *tmp = new ForwardList;
	if(list->next!=NULL){
		while(tmp->next!=NULL){
			tmp=tmp->next;
			tmp=NULL;
		}
	}
	return;
}

ForwardList *PushFront(ForwardList *list, int value){

	ForwardList *tmp = new ForwardList;
	tmp->next=list;
	tmp->value=value;
	list=tmp;
	return tmp;
}

void Append(ForwardList *list, ForwardList *tail){
	
	ForwardList *tmp = new ForwardList;
	tmp=list;
	
	if(tmp==NULL){
		list=tail;
	}
	else{
		while(tmp->next!= NULL){
			tmp=tmp->next;
		}
	tmp->next=tail;
	tail->next=NULL;
	}

	return;
}

int main(void){
	
	ForwardList *list;
	ForwardList *tail;
	int val;
	list=NULL;
	tail->value=7;
	cout << "Podaj numer początkowy: ";
	cin >> val;
	list=CreateNode(val);
	cout<<list->value<<endl;
	list=PushFront(list, 5);
	cout<<list->value<<endl<<list->next->value<<endl;
	DestroyList(list);
	cout<<list->value<<endl<<list->next->value<<endl;
	Append(list, tail);
	cout<<list->value<<endl<<list->next->value<<list->next->next->value<<endl;

return 0;
}