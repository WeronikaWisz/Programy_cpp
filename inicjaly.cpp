#include<iostream>
#include <string>

using namespace std;

class Name {

	public:
  		Name(string f_name, string s_name, string t_name, string l_name){
			first_name_ = f_name;
			second_name_ = s_name;
 			third_name_ = t_name;
			last_name_ = l_name;
		}
		Name(string f_name, string s_name, string l_name){
			first_name_ = f_name;
			second_name_ = s_name;
			last_name_ = l_name;
		}
		Name(string f_name, string l_name){
			first_name_ = f_name;
			last_name_ = l_name;
		}
		Name();

		string ToFullInitials(){
			string initials;
			initials = to_string(first_name_[0])+"."+to_string(second_name_[0])+"."+to_string(third_name_[0])+"."+to_string(last_name_[0])+".";
			return initials;
		}
	
  		string ToFirstNamesInitials(){
			string tfni;
			tfni = to_string(first_name_[0])+"."+to_string(second_name_[0])+"."+to_string(third_name_[0])+"."+last_name_;
			return tfni;
		}

  		string ToSurnameNames(){
			string tsn;
			tsn = last_name_+" "+first_name_+" "+second_name_+" "+third_name_;
			return tsn;
		}

  		string ToNamesSurname(){
			string tns;
			tns = first_name_+" "+second_name_+" "+third_name_+" "+last_name_;
			return tns;
		}

		bool IsBeforeBySurname(Name &other){
			if(other.last_name_[0] > this->last_name_[0]){
				return false;
			}
			else return true;
		}
	
		bool IsBeforeByFirstName(Name &other){
			if(other.first_name_[0] > this->first_name_[0]){
				return false;
			}
			else return true;
		}

 
 private:
  string first_name_;
  string second_name_;
 
  string third_name_;
  string last_name_;
};

int main(){
	
	string name, second, third, last, initials, tfni, tsn, tns;
	cout << "Give your names: ";
	cin >> name;
	cin >> second;
	cin >> third;
	cin >> last;
	Name n(name, second, third, last);
	initials = n.ToFullInitials();
	tfni = n.ToFirstNamesInitials();
	tsn = n.ToSurnameNames();
	tns = n.ToNamesSurname();
	cout << initials <<endl << tfni <<endl << tsn <<endl << tns <<endl;
	
	

return 0;
}
