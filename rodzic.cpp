#include<iostream>
#include<string>

using namespace std;

class Child{

	private:
		string school;

	public:
		friend class Parent;
		Child();
		Child(string first_name_c1, string last_name_c1, int age_c1, string school1);
		string first_name_c;
		string last_name_c;
		int age_c;
};

class Parent{

	public:
		Parent();
		Parent(string first_name1, string last_name1, int age1, Child *child1);
		string first_name;
		string last_name;
		int age;
		Child *child;
		void dif_school(Child *child, string school2);
};

Child::Child(string first_name_c1, string last_name_c1, int age_c1, string school1){
	first_name_c = first_name_c1;
	last_name_c = last_name_c1;
	age_c = age_c1;
	school = school1;
}

Parent::Parent(string first_name1, string last_name1, int age1, Child *child1){
	first_name = first_name1;
	last_name = last_name1;
	age = age1;
	child = child1;
}

void Parent::dif_school(Child *child, string school2){
	child->school = school2;
}

int main(){
	Child *c = new Child("Ala", "Kowalska", 15, "podstawowa");
	Parent p("Anna", "Kowalska", 40, c);
	p.dif_school(c, "gimnazjum");
	cout << c->school << endl;
}
	