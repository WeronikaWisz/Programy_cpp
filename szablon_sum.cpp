#include<iostream>
#include<complex>

using namespace std;

template<class T>
 T Sum( const T &left, const T &right){
	return left + right;
 }

int main(){

int suma1 = Sum<int>(3, 4);
double suma2 = Sum<double>(2.50, 3.27);
complex<double> sum3 = Sum<complex<double>>((2,3),(4,7));
cout << suma1 <<", "<< suma2 << ", " <<sum3 <<endl;


return 0;
}
