#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Serializer{
	public:
		Serializer() = default;
		~Serializer() = default;
		vector<int> numbers;
		vector<string> subtitles;
		virtual void PrintVector() =0;
		
};

class XmlSerializer : public Serializer{
	public:
		XmlSerializer() : Serializer() {};
		~XmlSerializer(){};
		virtual void PrintVector() override;
};

class JsonSerializer : public Serializer{
	public:
		JsonSerializer() : Serializer() {};
		~JsonSerializer(){};
		virtual void PrintVector() override;
};

class Serializable{

	public:
		virtual void Serialize(Serializer *) = 0;
};

class Room : public Serializable {

	public:
		Room(int h, int y, string c){
			height = h;
			yardage = y;
			color = c;
		}
		~Room(){};
		virtual void Serialize(Serializer *) override;
		int height;
		int yardage;
		string color;
};

class Building : public Serializable {

	public:
		Building(int h, int y, int f, string t){
			height = h;
			yardage = y;
			floors = f;
			type = t;
		}
		~Building(){};
		virtual void Serialize(Serializer *) override;
		int height;
		int yardage;
		int floors;
		string type;
};

void Room::Serialize(Serializer *s){
	s->numbers.emplace_back(height);
	s->numbers.emplace_back(yardage);
	s->subtitles.emplace_back(color);	
}

void Building::Serialize(Serializer *s){
	s->numbers.emplace_back(height);
	s->numbers.emplace_back(yardage);
	s->numbers.emplace_back(floors);
	s->subtitles.emplace_back(type);
}

void XmlSerializer::PrintVector() {
    bool first = true;
    cout<<"Xml Format: ";
    for(auto n : numbers) {
        if (!first) {
            cout<< ", ";
        } else {
            first = false;
        }
        cout << n;
 
    }
    cout << ", ";
    first = true;
    for(auto m : subtitles) {
        if (!first) {
            cout<< ", ";
        } else {
            first = false;
        }
        cout << m;
 
    }
    cout<<endl;

}

void JsonSerializer::PrintVector() {
    bool first = true;
    cout<<"Json Format: ";
    for(auto n : numbers) {
        if (!first) {
            cout<< ", ";
        } else {
            first = false;
        }
        cout << n;
 
    }
    cout << ", ";
    first = true;
    for(auto m : subtitles) {
        if (!first) {
            cout<< ", ";
        } else {
            first = false;
        }
        cout << m;
 
    }
    cout<<endl;

}


int main(){
	
	Room r1(3, 8, "white");
	Building b1(10, 90, 2, "detached house"); 
	Serializer *s1 = new XmlSerializer;
	Serializer *s2 = new JsonSerializer;
	r1.Serialize(s1);
	b1.Serialize(s2);
	s1->PrintVector();
	s2->PrintVector();
	

return 0;
}