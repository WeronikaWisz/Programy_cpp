#include<iostream>
#include<string>

using namespace std;

class Student{

	public:
		Student(string name1, string name2): f_name{name1}, l_name{name2} {}
		virtual bool IsLess(Student &left, Student &right) const =0;
		string f_name, l_name;
};

bool Comparator(Student &left, Student &right) {

	return left.IsLess(left, right);

}

class ByFirstNameAscending : public Student{

	public:
		
		ByFirstNameAscending(string name1, string name2): Student(name1, name2) {}
		virtual bool IsLess(Student &left, Student &right) const override;

};

class ByFirstNameDescending : public Student{
	
	public:
		
		ByFirstNameDescending(string name1, string name2): Student(name1, name2) {}
		virtual bool IsLess(Student &left, Student &right) const override;

};


class ByLastNameAscending : public Student{

	public:
		
		ByLastNameAscending(string name1, string name2): Student(name1, name2) {}
		virtual bool IsLess(Student &left, Student &right) const override;

};
	
bool ByFirstNameAscending::IsLess(Student &left, Student &right) const {

	int i;
	while(left.f_name[i] == right.f_name[i] && i<=(left.f_name).length() && i<=(right.f_name).length()){
		i++;
	}
	if(left.f_name[i] < right.f_name[i] && i<=(left.f_name).length() && i<=(right.f_name).length()){
		return true;
	}
	else{ 
		return false;
	}

}

bool ByFirstNameDescending::IsLess(Student &left, Student &right) const {
	
	int i;
	while(left.f_name[i] == right.f_name[i] && i<=(left.f_name).length() && i<=(right.f_name).length()){
		i++;
	}
	if(left.f_name[i] > right.f_name[i] && i<=(left.f_name).length() && i<=(right.f_name).length()){
		return true;
	}
	else{ 
		return false;
	}

}

bool ByLastNameAscending::IsLess(Student &left, Student &right) const {

	int i;
	while(left.l_name[i] == right.l_name[i] && i<=(left.l_name).length() && i<=(right.l_name).length()){
		i++;
	}
	if(left.l_name[i] < right.l_name[i] && i<=(left.l_name).length() && i<=(right.l_name).length()){
		return true;
	}
	else{ 
		return false;
	}

}

int main(){

	bool comp1, comp2;
	ByFirstNameAscending left("Jan", "Kowalski");
	ByFirstNameAscending right("Jakub", "Nowak");
	ByFirstNameDescending left1("Jan", "Kowalski");
	ByFirstNameDescending right1("Jakub", "Nowak");
	comp1 = Comparator(left, right);
	comp2 = Comparator(left1, right1);
	cout << comp1 << endl << comp2 << endl;

return 0;
}