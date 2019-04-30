#include<iostream>
#include<string>
using namespace std;

class Pesel{

	public:
		Pesel(string p): pesel{p} {}
		~Pesel(){}
		void validatePESEL();
	private:
		string pesel;

};

void Pesel::validatePESEL(){
	int  control;
	control = (9*(pesel[0]-'0') + 7*(pesel[1]-'0') + 3*(pesel[2]-'0') + (pesel[3]-'0') + 9*(pesel[4]-'0') + 7*(pesel[5]-'0') + 3*(pesel[6]-'0') + (pesel[7]-'0') + 9*(pesel[8]-'0') + 7*(pesel[9]-'0')) % 10;
	if( pesel.length()!=11 || (pesel[10]-'0')!=control){
		cerr << "bledny numer pesel" <<endl;
		return;
	}
	cout << "jest ok" << endl;
	return;
}

int main(){
	Pesel p1{"12345678903"};
	Pesel p2{"12345678900"};
	Pesel p3{"123"};
	p1.validatePESEL();
	p2.validatePESEL();
return 0;
}
	
