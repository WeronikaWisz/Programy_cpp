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
	unsigned int difference, min, time1, time2;
	min = 1440;

	for(int i=0; i<times.size()-1; i++){
		for(int j=1; j<times.size(); j++){
			if(i!=j){
				time1 = ToMinutes(times[i]);
				time2 = ToMinutes(times[j]);
				difference = time1-time2;
				if((time1-time2)>(time2-time1)){
					difference=time2-time1;
				}
				if(difference<min){
					min=difference;
				}
			}		
		}
	}
	return min;

}

int main(){

	vector<string> times;
	string time1, time2, time3;
	unsigned int mindiff;
	int t=1;
	while(t){
		cout << "Podaj godzine: ";
		cin >> time1;
		times.emplace_back(time1);
		cout << "Kliknij 0 jeśli podałeś wszystkie godziny, jeśli nie to 1: ";
		cin >> t;
	}
	//times.emplace_back(time2);
	//times.emplace_back(time3);
	mindiff=MinimalTimeDifference(times);
	cout << "Minimalna różnica: " << mindiff << " minuty" << endl;

return 0;
}