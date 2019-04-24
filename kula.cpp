#include<iostream>

using namespace std;

class Circle{

	public:
		Circle(){}
		Circle(double x, double y, double r){
			this->x = x;
			this->y = y;
			this->r = r;
		}
		~Circle(){}
		double x, y, r;
		double area(){
			return 3.14*r*r;
		}
};

class Sphere: public Circle{

	public:
		Sphere(){}
		Sphere(double x, double y, double r, double z):Circle(x,y,r){
			this->z = z;
		}
		~Sphere(){}
		double z;
		double area(){
			return 4*r*r*3.14;
		}

}; 

int main(){

	Sphere s(4,2,3,3);
	cout << s.area() << endl;

return 0;
}