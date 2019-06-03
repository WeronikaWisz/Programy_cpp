#include<iostream>
#include<vector>
#include<complex>

using namespace std;

template<class T>
double Mean(vector<T> v) {
	double mean=0;
	int n=v.size();
	for(int i=0; i<n; i++){
		 mean=mean+v[i];
	}
	mean=mean/n;
return mean;
}

int main(){

vector<int> v1;
v1.emplace_back(1);
v1.emplace_back(2);
v1.emplace_back(3);
v1.emplace_back(4);
double m1 = Mean<int>(v1);
cout << m1 << endl;

return 0;
}