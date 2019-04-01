#include<iostream>
#include<cmath>
using namespace std;

class Point{

	private:
		double x;
		double y;
	public:

		Point();
		Point(double x_, double y_);
		/*{
			this->x = x_;
			this->y = y_;
		}*/
		//~Point();

		void ToString(){
			cout << "(" << x << " , " << y << ")" << endl;
		}

		double Distance(const Point &other){ 
			return sqrt(pow(x-other.x,2)+pow(y-other.y,2));
		}

		double Distance2(const Point &first, const Point &second){ 
			return sqrt(pow(first.x-second.x,2)+pow(first.y-second.y,2));
		}
};

class Square{

	private:
		Point a;
		Point b;
		Point c;
		Point d;
	public:
	
		Square(Point a_, Point b_, Point c_, Point d_){
			a = a_;
			b = b_;
			c = c_;
			d = d_;
		}
		
		double Circumference(){
			double side;
			side = a.Distance(b);
			side*=4;
			return side;
		}
	
		double Area(){
			double side;
			side = a.Distance(b);
			side*=side;
			return side;
		}
		
		void Screen(){
			a.ToString();
			b.ToString();
			c.ToString();
			d.ToString();
		}

}; 

Point::Point(double x_, double y_){
  x = x_;
  y = y_;
}
Point::Point():x(0),y(0){}

int main(){
	
	double x, y, a, b, dif, dif2;
	cout << "Give your point: ";
	cin >> x;
	cin >> y;
	Point p1(2,4);
	Point p2(x,y);
	Point p3(4,4);
	Point p4(4,2);
	Point p6(2,2);
	cout << "Point 1: ";
	p1.ToString();
	dif = p1.Distance(p2);
	cout << "Distance: " << dif << endl;
	cout << "Give second point: ";
	cin >> a;
	cin >> b;
	Point p5(a,b);
	dif2 = p2.Distance2(p2,p5);
	cout << "Distance between your points: " << dif2 << endl;
	Square s(p1,p6,p3,p4);
	cout << "Square example: " << endl;
	s.Screen();
	double ar, circ;
	circ = s.Circumference();
	ar = s.Area();
	cout << "Circumference: " << circ << endl << "Area: " << ar << endl;
	

return 0;
}

