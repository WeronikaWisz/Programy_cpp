#include<iostream>
#include<string>

using namespace std;

class StudyYear{

	int year;
	
	public:
		StudyYear():year(0){};
		StudyYear(int year){
			this->year = year;
		}
		~StudyYear(){};
		friend istream& operator>>(istream &, StudyYear&);
		friend ostream& operator<<(ostream &, const StudyYear&);
		
		StudyYear &operator++(){
			this->year++;
			return *this;
		}
	
		StudyYear &operator--(){
			this->year--;
			return *this;
		}

		bool operator==(const StudyYear &other){
			if(this->year==other.year){
				return true;
			}
			else{
				return false;
			}
		}

		bool operator<(const StudyYear &other){
			if(this->year<other.year){
				return true;
			}
			else{
				return false;
			}
		}
		
		operator int const(){
        		return year;
    		}
	
		
};

class Student{
	
	string id;
	string first_name;
	string last_name;
	string program;
	StudyYear year;

	public:
		Student(){};
		Student(string id, string first_name, string last_name, string program, StudyYear year){
			this->id = id;
			this->first_name = first_name;
			this->last_name = last_name;
			this->program = program;
			this->year = year;
		}
		~Student(){};	
		friend istream& operator>>(istream &, Student&);
		friend ostream& operator<<(ostream &, const Student&);

};



istream& operator>>(istream & input, StudyYear& y){
	input >> y.year;      
	return input;     
}

ostream& operator<<(ostream & output, const StudyYear& y){
	output << y.year;
	return output;     
}

istream& operator>>(istream & input, Student& s){
	input >> s.id;
	input >> s.first_name;
	input >> s.last_name;
	input >> s.program;
	input >> s.year;      
	return input;     
}

ostream& operator<<(ostream & output, const Student& s){
	output << s.id;
	output << s.first_name;
	output << s.last_name;
	output << s.program;
	output << s.year; 
	return output;     
}

int main(){

	StudyYear y;
	int liczba;
	cin >> y;
	++y;
	cout << y;
	cout << endl;
	liczba = y;
	cout << liczba;
	
return 0;
}