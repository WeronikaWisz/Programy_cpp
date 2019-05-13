#include<iostream>
#include<vector>
#include <cstdlib>
#include <ctime>
using namespace std;

enum class Food{
	Sweet = 1,
	Water = 2,
	Juice = 3,
	Bar = 4,
	Beer = 5,
	Chips = 6,
	Fries = 7,
	Burger = 8,
	Wine = 9,
	Vodka = 10,
};

const char FoodDesc[10][10] = {
	"Sweet",
	"Water",
	"Juice",
	"Bar",
	"Beer",
	"Chips",
	"Fries",
	"Burger",
	"Wine",
	"Vodka",
  };

class Backpack{
	
	public:
		int capacity;
		float alko;
		vector<int> supplies;
		Backpack(int cap, float alk){
			capacity = cap;
			alko = alk;
		}
		~Backpack(){}
		float concentration(int check){
			float count=0;
				if(check==static_cast<int>(Food::Beer)){
					count =  check*0.4;
		 		}
				if(check==static_cast<int>(Food::Vodka)){
					count =  check*0.9;
		 		}
				if(check==static_cast<int>(Food::Wine)){
					count =  check*0.5;
		 		}
			return count;
		}
		void Supplies(){
			bool first = true;
			for(int n : supplies){
				if(!first){
					cout << ", ";
				}
				else{
					first = false;
				}
				cout << FoodDesc[n-1];
			}
			cout << endl;
		}
};



int main(){

int cap, alk, counter1 = 0;
float counter2 = 0;
int f;
cout << "Enter capacity of your backpack: ";
cin >> cap;
cout << "Enter percentage of alcohol you want: ";
cin >> alk;
Backpack b1(cap,alk);
srand( time( NULL ) );

while(b1.capacity>=counter1 && b1.alko>=counter2){
	f = rand() % 10 + 1;
	counter1+=f;
	counter2+=b1.concentration(f);
	if(b1.capacity>=counter1 && b1.alko>=counter2){
		b1.supplies.emplace_back(f);
	}
	else{
		counter1-=f;
		counter2-=b1.concentration(f);
		break;
	}
}

cout << "Your equipment: " << endl;
b1.Supplies();
cout << "Capacity: " << counter1 << ", Alcohol level: " << counter2 << endl;

return 0;
}