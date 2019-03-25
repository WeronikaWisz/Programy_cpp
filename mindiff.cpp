#include<iostream>
#include <vector>
#include <sstream>
#include <regex>
#include <cmath>
using namespace std;

unsigned int ToMinutes(string time_HH_MM){
	unsigned int minutes;
	string min1, min2;
	regex pattern {R"(([0-1]?[0-9]|2[0-4]):([0-5][0-9]))"};
	smatch matches;
	if(regex_match(time_HH_MM, matches, pattern)){
		min1 = matches[1];
		min2 = matches[2];
		minutes = 60*stoi(min1) + stoi(min2);
		return minutes;
	}
	else{
		cout << "Zły format"<<endl;
		return 1;
	}
}

unsigned int MinimalTimeDifference(std::vector<std::string> times){
	unsigned int difference, time1, time2;
	time1 = ToMinutes(times[0]);
	time2 = ToMinutes(times[1]);
	difference = time1-time2;
	if((time1-time2)>(time2-time1)){
		difference=time2-time1;
	}
	return difference;

}

int main(){

	vector<string> times;
	string time1, time2;
	unsigned int mindiff;
	cin >> time1 >> time2;
	times.emplace_back(time1);
	times.emplace_back(time2);
	mindiff=MinimalTimeDifference(times);
	cout << mindiff << " minutes" << endl;

return 0;
}