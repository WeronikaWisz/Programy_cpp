#include<iostream>
#include <memory>

using namespace std;

template<class T>
T Value(T *v_) {
	return *v_;
}

template<class T>
T Value2(T v_){
	return v_;
}

int main(){

int n=5;
int *m = &n;
int value = Value<int>(m);
cout << value << endl;

shared_ptr<int> p = make_shared<int>(7);
int v = Value2<int>(*p);
cout << v << endl; 


return 0;
}