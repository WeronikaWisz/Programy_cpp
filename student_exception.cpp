#include<iostream>
#include<string>

using namespace std;

class Invalid_argument{
	
	public:
		Invalid_argument(string exception): exc{exception} {}
		~Invalid_argument(){}
		string exc;
	
};

class InvalidNameSurname : public Invalid_argument{
	
	public:
		InvalidNameSurname(const string &ns) : Invalid_argument("Invalid Name/Surname"){ ns_ = ns; }
		string ns_;

};

class InvalidAge : public Invalid_argument{

	public:
		InvalidAge(const int &y) : Invalid_argument("Invalid Age"){ y_ = y; }
		int y_;

};

class InvalidProgram : public Invalid_argument{

	public:
		InvalidProgram(const string &p) : Invalid_argument("Invalid Program"){p_ = p; }
		string p_;

};

class Student{
	
	string first_name;
	string last_name;
	string program;
	int year;

	public:
		Student(){};
		Student(string first, string last, string prog, int y);
		~Student(){};	
		friend istream& operator>>(istream &, Student&);
		friend ostream& operator<<(ostream &, const Student&);

};

Student::Student(string first, string last, string prog, int y){
			int len = first.length();
			int len2 = last.length();
			bool check = false;
			bool check2 = false;
			for(int i=1; i<len; i++){
				if(first[i]<97 || first[i]>122){
					check = true;
				}
			}
			if(first[0]<90 && first[0]>65 && check == false){
				this->first_name = first;
			}
			else{
				throw InvalidNameSurname(first);
			}
			
			for(int i=1; i<len2; i++){
				if(last[i]<97 || last[i]>122){
					check2 = true;
				}
			}
			if(last[0]<90 && last[0]>65 && check2 == false){
				this->last_name = last;
			}
			else{
				throw InvalidNameSurname(last);
			}

			if(prog=="informatyka" || prog=="ekonomia" || prog=="matematyka" || prog=="fizyka" || prog=="filozofia"){
				this->program = prog;
			}
			else{
				throw InvalidProgram(prog);
			}
			if(y>=10 && y<=100){
				this->year = y;
			}
			else{
				throw InvalidAge(y);
			}
		}

istream& operator>>(istream & input, Student& s){

	input >> s.first_name;
	input >> s.last_name;
	input >> s.program;
	input >> s.year;      
	return input;     
}

ostream& operator<<(ostream & output, const Student& s){

	output << s.first_name;
	output << " ";
	output << s.last_name;
	output << " ";
	output << s.program;
	output << " ";
	output << s.year; 
	return output;     
}

int main(){

	try {
		Student s("Daniel", "Nowak", "informatyka", 20);
		//Student s1("Daniel", "Nowak", "angielski", 20);
		//Student s2("D@niel", "Nowak", "informatyka", 20);
		//Student s3("Daniel", "Nowak", "informatyka", 150);
    		cout << s << endl;
  	} catch(const InvalidNameSurname &w) {
		cerr << w.exc << endl;
  	} catch(const InvalidAge &w) {
		cerr << w.exc << endl;
  	} catch(const InvalidProgram &w) {
		cerr << w.exc << endl;
  	}
	
	
return 0;
}