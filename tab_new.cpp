#include<iostream>
using namespace std;

int **Array2d(int wiersze, int kolumny){

	int licznik=1;
	int **tab = new int*[wiersze];
	
	for(int i=0;i<wiersze;i++){
		tab[i] = new int[kolumny];
	}
	
	for(int j=0;j<wiersze;j++){
		for(int k=0; k<kolumny;k++){
			tab[j][k] = licznik++;
		}
	}
	return tab;
}

void DeleteArray2d(int **tab, int wiersze){

	for(int i=0;i<wiersze;i++){
		delete [] tab[i];
	}
}



int main(){

	int wiersze, kolumny;
	cout << "Podaj wymiary tablicy: ";
	cin >> wiersze >> kolumny;
	
	int **tab;
	
	tab=Array2d(wiersze, kolumny);

	for(int l=0; l<wiersze; l++){
		for(int m=0; m<kolumny; m++){
			cout << tab[l][m] << '\t';
		}
		cout << endl;
	}
	DeleteArray2d(tab, wiersze);

return 0;
}