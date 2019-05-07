#include<iostream>
#include<vector>
using namespace std;

enum class Food{
	Beer = 5,
	Vodka = 10,
	Wine = 9,
	Water = 2,
	Juice = 3,
	Bar = 4,
	Sweet = 1,
};

class Backpack{
	
	public:
		int capacity;
		int alko;
		vector<Food> supplies;
		Backpack(int cap, int alk){
			capacity = cap;
			alko = alk;
		}
		~Backpack(){}
		int concentration(int check){
			int count=0;
				if(check==static_cast<int>(Food::Beer) || check==static_cast<int>(Food::Vodka) || check==static_cast<int>(Food::Wine)){
					count =  check*0.5;
		 		}
			return count;
		}
};



int main(){

//cout << static_cast<int>(Food::Beer) << endl;
int cap, alk, temp, counter1, counter2;
int f;
cin >> cap;
cin >> alk;
Backpack b1(cap,alk);
while(b1.capacity<=counter1 && b1.alko<=counter2){
	cin >> f;
	temp = static_cast<Food>(f)
	b1.supplies.emplace_back(f);
	counter1+=temp;
	counter2+=b1.concentration(f);
}

return 0;
}
