#include<iostream>
#include<vector>
#include<complex>

using namespace std;

template<class T>
T Sum(vector<T> v) {
	T sum;
	int n=v.size();
	for(int i=0; i<n; i++){
		 sum=sum+v[i];
	}
return sum;
}

int main(){

vector<string> v1;
vector<int> v2;
v1.emplace_back("a");
v1.emplace_back("l");
v1.emplace_back("a");
v2.emplace_back(4);
v2.emplace_back(3);
v2.emplace_back(5);
string m1 = Sum<string>(v1);
int m2 = Sum<int>(v2);
cout << m1 << endl << m2 << endl;

return 0;
}
