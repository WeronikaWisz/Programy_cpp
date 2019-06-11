#include<iostream>
#include<vector>
#include<complex>

using namespace std;

template<class T>
void Write(vector<T> &result, vector<T> &source, T &key) {
	for(int i=0; i< source.size(); i++){
		if(source[i]<key){
			result.emplace_back(source[i]);
		}
	}
return;
}

int main(){

vector<int> v1;
vector<int> v2;
v1.emplace_back(4);
v1.emplace_back(3);
v1.emplace_back(6);
v1.emplace_back(7);
v1.emplace_back(1);
int a=5;
Write<int>(v2, v1, a);
for(int i=0; i< v2.size(); i++){
	cout<< v2[i];
}
cout <<endl;


return 0;
}
