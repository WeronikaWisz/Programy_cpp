#include<iostream>
#include<string>
#include<fstream>
using namespace std;

/*dane muszą być wielkimi literami*/

string PolybiusCrypt(string message, string array[][5]){
	string crypted, first, second;
	int len;
	len=message.length();
	string letter;

	for(int k=0; k<len; k++){
		letter = message[k];
		if(letter=="J"){
			crypted=crypted+"24"+" ";
		}
		else{

			for(int i=0; i<5; i++){
				for(int j=0; j<5; j++){
					if(array[i][j]==letter){
						first=to_string(i+1);
						second=to_string(j+1);
						crypted=crypted+first+second+" ";
					}
				}
			}
		}
	}

	cout<<crypted;

return crypted;
}

string PolybiusDecrypt(string crypted, string array[][5]){
	string message;

	if(crypted==to_string(73)){
		message=message+"J";
	}
	
	else{
		for(int i=0; i<5; i++){
			for(int j=0; j<5; j++){
				if(to_string(10*i+j)==crypted){
				message=message+array[i][j];
				}
			}
		}
	}


return message;
}

int main(int argc, char *argv[]){

	string array[5][5];
	int licznik=65;
	
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			array[i][j] = licznik++;
			if(licznik==73){
				licznik+=1;
			}
		}
	}


	ifstream dane(argv[1]);
	ofstream wynik(argv[2], ios_base::in | ios_base::app);

	string text;
	string message;
	int k;
	k=(*argv[3])-48;

	while(dane >> message){
    		
		if(k==1){
			text = PolybiusCrypt(message, array);
			wynik << text << " ";
		}
		if(k==0){
			text = PolybiusDecrypt(message, array);
			wynik << text;
		}
	}
	cout<<"Wynik zapisany w pliku"<<endl;

return 0;
}