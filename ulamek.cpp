#include<iostream>

using namespace std;

class Ulamek{

	private:
		int licznik;
		int mianownik;
	public:
		Ulamek(int licznik, int mianownik){
			if(mianownik != 0){
				this->licznik = licznik;
				this->mianownik = mianownik;
			}
			else{
				cout << "Nie dziel przez zero";
				return;
			}
		} 
		
		void Wypisz(){
			cout << licznik << "/" << mianownik << endl;
		}
};

int main(void){

	int x, y;
	cin >> x;
	cin >> y;
	Ulamek u(x,y);
	u.Wypisz();
	
return 0;
}	