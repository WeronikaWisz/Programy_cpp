#include<iostream>
#include<string>
#include<regex>
#include<fstream>

using namespace std;

class Invalid_argument{
	
	public:
		Invalid_argument(string exception): exc{exception} {}
		~Invalid_argument(){}
		string exc;
	
};

class NegativeFrameAfterShift : public Invalid_argument{
	
	public:
		NegativeFrameAfterShift(const int &what_line, const string &err) : Invalid_argument("Negative Frame After Shift"){ what_line_ = what_line; err_ = err; }
		int what_line_;
		string err_;

};

class SubtitleEndBeforeStart : public Invalid_argument{
	
	public:
		SubtitleEndBeforeStart(const int &what_line, const string &err) : Invalid_argument("Subtitle End Before Start"){  what_line_ = what_line; err_ = err;  }
		int what_line_;
		string err_;

};

class InvalidSubtitleLineFormat : public Invalid_argument{
	
	public:
		InvalidSubtitleLineFormat(const int &what_line, const string &err) : Invalid_argument("Invalid Subtitle Line Format"){  what_line_ = what_line; err_ = err; }
		int what_line_;
		string err_;

};

class OutOfOrderFrames : public Invalid_argument{
	
	public:
		OutOfOrderFrames(const int &what_line, const string &err) : Invalid_argument("Out Of Order Frames"){  what_line_ = what_line; err_ = err; }
		int what_line_;
		string err_;

};


class MovieSubtitles{

	public:
		virtual void ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second, ifstream &dane, ofstream &wynik) const=0;
		~MovieSubtitles(){};

};

class MicroDvdSubtitles : public MovieSubtitles{
		public:
			MicroDvdSubtitles(){};
			~MicroDvdSubtitles(){};
			virtual void ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second, ifstream &dane, ofstream &wynik) const override;

};

class SubRipSubtitles : public MovieSubtitles{
		public:
			SubRipSubtitles(){};
			~SubRipSubtitles(){};
			virtual void ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second, ifstream &dane, ofstream &wynik) const override;

};

void MicroDvdSubtitles::ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second, ifstream &dane, ofstream &wynik) const {

	int what_line=0;
	string line, subtitles;
	regex pattern {R"((\{)(-?\d+)(\})(\{)(-?\d+)(\})([\w\s,.\!\?\(\)]+))"};
	smatch matches;
	int begin, end, prev_end;
	string start, stop;

	while(!dane.eof()){

		getline(dane, line);
		what_line+=1;
		prev_end = end;
		if(regex_match(line, matches, pattern)){
			start = matches[2];
			stop = matches[5];
			subtitles = matches[7];
			begin = stoi(start);
			end = stoi(stop);
		}
		else{
			throw InvalidSubtitleLineFormat(what_line, subtitles);
		}
		if(begin<0 || end<0){
			throw NegativeFrameAfterShift(what_line, subtitles);
		}
		if(end-begin < 0){
			throw SubtitleEndBeforeStart(what_line, subtitles);
		}
		if(prev_end > begin){
			throw OutOfOrderFrames(what_line, subtitles);
		}
		wynik << subtitles << " ";
	}
	return;
	
}

void SubRipSubtitles::ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second, ifstream &dane, ofstream &wynik) const {

	int what_line=0;
	string line;
	regex pattern1 {R"((\d+))"};
	regex pattern2 {R"(([1-9]|[01][1-9]|2[1-3])(:)([1-9]|[0-5][1-9])(:)([1-9]|[0-5][1-9])([,])([0-9][0-9][0-9])(-)([1-9]|[01][1-9]|2[1-3])(:)([1-9]|[0-5][1-9])(:)([1-9]|[0-5][1-9])([,])([0-9][0-9][0-9]))"};
	smatch matches1, matches2;
	int id, prev_id;
	string index;

	while(!dane.eof()){

		getline(dane, line);
		what_line+=1;
		prev_id = id;

		if(what_line%5 == 1){
			if(regex_match(line, matches1, pattern1)){
				index = matches1[1];
				id = stoi(index);
				if(prev_id > id){
					throw OutOfOrderFrames(what_line, "Index out of order");
				}	
			}
			else{
				throw InvalidSubtitleLineFormat(what_line, "Wrong index");
			}
		}

		if(what_line%5 == 2){
			if(!regex_match(line, matches2, pattern2)){
				throw InvalidSubtitleLineFormat(what_line, "Wrong time format");					
			}
		}
	
		if(what_line%5 == 3 || what_line%5 == 4){
			wynik << line << " ";
		}
		
	}
	return;
	
}

int main(){

	ifstream dane, dane2;
	ofstream wynik, wynik2;

	dane.open("dane_napisy1.txt");
	wynik.open("wynik_napisy1.txt");
	dane2.open("dane_napisy2.txt");
	wynik2.open("wynik_napisy2.txt");

	try{
		MicroDvdSubtitles text1;
		text1.ShiftAllSubtitlesBy(2, 4 , dane, wynik);
		SubRipSubtitles text2;
		text2.ShiftAllSubtitlesBy(2, 4 , dane2, wynik2);
		dane.close();
		wynik.close();
		dane2.close();
		wynik2.close();
	} catch( const NegativeFrameAfterShift &w){
		cerr << w.exc << " line: " << w.what_line_ << ", " << w.err_ << endl;
	} catch( const SubtitleEndBeforeStart &w){
		cerr << w.exc << " line: " << w.what_line_ << ", " << w.err_ << endl;
	} catch( const InvalidSubtitleLineFormat &w){
		cerr << w.exc << " line: " << w.what_line_ << ", " << w.err_ << endl;
	} catch( const OutOfOrderFrames &w){
		cerr << w.exc << " line: " << w.what_line_ << ", " << w.err_ << endl;
	}

return 0;
}
