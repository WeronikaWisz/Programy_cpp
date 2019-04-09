#include<iostream>

using namespace std;

class Complex{
	
	int re, im;

	public:
		Complex():re(0),im(0){};
		Complex(int re1, int im1);
		~Complex(){};
		friend istream& operator>>(istream &, Complex&);
		friend ostream& operator<<(ostream &, const Complex&);
		
		Complex operator+(const Complex& other){
			return Complex(this->re + other.re, this->im + other.im);
		}

		Complex operator-(const Complex& other){
			return Complex(this->re - other.re, this->im - other.im);
		}

		Complex operator*(const Complex& other){
			return Complex(this->re * other.re - this->im * other.im, this->re * other.im + this->im * other.im);
		}

		Complex operator/(const Complex& other){
			return Complex((this->re * other.re + this->im * other.im)/(other.re * other.re + other.im* other.im), (this->im * other.re + this->re * other.im)/(other.re * other.re + other.im* other.im));
		}



};

Complex::Complex(int re1, int im1){
	this->re = re1;
	this->im = im1; 
}

istream& operator>>(istream & input, Complex& c){
	input >> c.re;  
	input >> c.im;    
	return input;     
}

ostream& operator<<(ostream & output, const Complex& c){
	output << c.re;
	output << "+";
	output << c.im;
	output << "i";
	output << endl;
	return output;     
}


int main(){
	
	Complex point1, point2;
	cin >> point1;
	cin >> point2;
	cout << point1 + point2;
	cout << point1 - point2;
	cout << point1 * point2;
	
return 0;
}
