#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

using namespace std;

struct liczba {
	unsigned long long int key = 0;
	liczba* nastepna;
	liczba* poprzednia;
	liczba();
};
liczba::liczba() {
	nastepna = 0;
	poprzednia = 0;
}

struct lista {
	void iterator(unsigned short, char[]);
	void dodajprzed(char[], unsigned long long int);
	void dodajpo(char[], unsigned long long int);
	void usun(char[]);
	void wypisz(char[]);
	void przesun(unsigned short);
	void cofnij(unsigned short);
	liczba* BEG;
	liczba* END;
	liczba* tab[10];
	lista();
};
lista::lista() {
	BEG = 0;
	END = 0;
	for (unsigned short i = 0; i < 10; i++)
		tab[i] = nullptr;
}

int main() {
	lista* baza = new lista;
	char operacja[2];
	unsigned long long int key;
	while (true) {
		scanf("%s", operacja);
		if (feof(stdin) != 0)
		{
		break;
		}
		if (!strcmp(operacja, "I")) {
			int i;
			scanf("%d", &i);
		}
		else if (!strcmp(operacja, "i")) {
			unsigned short x;
			char y[3];
			cin >> x;
			scanf("%s", y);
			if ((!strcmp(y, "BEG")) || (!strcmp(y, "END")) || (!strcmp(y, "0")) || (!strcmp(y, "1")) || (!strcmp(y, "2")) || (!strcmp(y, "3")) || (!strcmp(y, "4")) || (!strcmp(y, "5")) || (!strcmp(y, "6")) || (!strcmp(y, "7")) || (!strcmp(y, "8")) || (!strcmp(y, "9"))) {
				baza->iterator(x, y);
			}
		}
		else if (!strcmp(operacja, "+")) {
			unsigned short x;
			cin >> x;
			baza->przesun(x);
		}
		else if (!strcmp(operacja, "-")) {
			unsigned short x;
			cin >> x;
			baza->cofnij(x);
		}
		else if (!strcmp(operacja, ".A")) {
			char x[3];
			scanf("%s", x);
			cin >> key;
			if ((!strcmp(x, "BEG")) || (!strcmp(x, "END")) || (!strcmp(x, "0")) || (!strcmp(x, "1")) || (!strcmp(x, "2")) || (!strcmp(x, "3")) || (!strcmp(x, "4")) || (!strcmp(x, "5")) || (!strcmp(x, "6")) || (!strcmp(x, "7")) || (!strcmp(x, "8")) || (!strcmp(x, "9"))) {
				baza->dodajprzed(x, key);
			}

		}
		else if (!strcmp(operacja, "A.")) {
			char x[3];
			scanf("%s", x);
			cin >> key;
			if ((!strcmp(x, "BEG")) || (!strcmp(x, "END")) || (!strcmp(x, "0")) || (!strcmp(x, "1")) || (!strcmp(x, "2")) || (!strcmp(x, "3")) || (!strcmp(x, "4")) || (!strcmp(x, "5")) || (!strcmp(x, "6")) || (!strcmp(x, "7")) || (!strcmp(x, "8")) || (!strcmp(x, "9"))) {
				baza->dodajpo(x, key);
			}
		}
		else if (!strcmp(operacja, "R")) {
			char x[3];
			scanf("%s", x);
			if ((!strcmp(x, "BEG")) || (!strcmp(x, "END")) || (!strcmp(x, "0")) || (!strcmp(x, "1")) || (!strcmp(x, "2")) || (!strcmp(x, "3")) || (!strcmp(x, "4")) || (!strcmp(x, "5")) || (!strcmp(x, "6")) || (!strcmp(x, "7")) || (!strcmp(x, "8")) || (!strcmp(x, "9"))) {
				baza->usun(x); }
		}
		else if (!strcmp(operacja, "P")) {
			char p[3];
			scanf("%s", p);
			if ((!strcmp(p, "BEG")) || (!strcmp(p, "END")) || (!strcmp(p, "ALL")) || (!strcmp(p, "0")) || (!strcmp(p, "1")) || (!strcmp(p, "2")) || (!strcmp(p, "3")) || (!strcmp(p, "4")) || (!strcmp(p, "5")) || (!strcmp(p, "6")) || (!strcmp(p, "7")) || (!strcmp(p, "8")) || (!strcmp(p, "9"))) {
				baza->wypisz(p);
			}
		}	
	}
	delete baza;
	return 0;
}


void lista::dodajprzed(char x[3], unsigned long long int key) {
	liczba* nowa = new liczba;
	nowa->key = key;
	if (BEG == 0 && x[0] == 'B' && x[1] == 'E' && x[2] == 'G' || (END == 0 && x[0] == 'E' && x[1] == 'N' && x[2] == 'D')) { 
		BEG = nowa;
		nowa->nastepna = BEG;
		nowa->poprzednia = BEG;
		END = nowa;
		nowa->poprzednia = END;
		nowa->nastepna = END;
	}
	else if (BEG != 0 && x[0] == 'B' && x[1] == 'E' && x[2] == 'G') {
		nowa->nastepna = BEG;
		nowa->poprzednia = END;
		BEG->poprzednia = nowa;
		BEG = nowa;	
	}
	else if (END != 0 && x[0] == 'E' && x[1] == 'N' && x[2] == 'D') {
		nowa->nastepna = END;
		nowa->poprzednia = END->poprzednia;
		END->poprzednia->nastepna = nowa;
		if (BEG == END) BEG = nowa;
		else END->poprzednia = nowa;
	}
	else if (x[0] == '0' || x[0] == '1' || x[0] == '2' || x[0] == '3' || x[0] == '4' || x[0] == '5' || x[0] == '6' || x[0] == '7' || x[0] == '8' || x[0] == '9') {
		unsigned short i;
		i = (unsigned short)x[0] - 48;
		if (tab[i] == BEG) {
			nowa->nastepna = BEG;
			nowa->poprzednia = END;
			BEG = nowa;
		}
		else {
			if (tab[i] != 0) {
				nowa->nastepna = tab[i];
				nowa->poprzednia = tab[i]->poprzednia;
				tab[i]->poprzednia->nastepna = nowa;
				tab[i]->poprzednia = nowa;
			}
		}
		
	}
}
void lista::dodajpo(char x[3], unsigned long long int key) {
	liczba* nowa = new liczba;
	nowa->key = key;
	if (BEG == 0 && x[0] == 'B' && x[1] == 'E' && x[2] == 'G' || (END==0 && x[0] == 'E' && x[1] == 'N' && x[2] == 'D')) { // DODAWANIE PIERWSZEGO ELEMENTU
		BEG = nowa;
		nowa->nastepna = BEG;
		nowa->poprzednia = BEG;
		END = nowa;
		nowa->poprzednia = END;
		nowa->nastepna = END;
	}
	else if (BEG != 0 && x[0] == 'B' && x[1] == 'E' && x[2] == 'G') {
		nowa->nastepna = BEG->nastepna;
		nowa->poprzednia = BEG;
		if (BEG != END) {
			BEG->nastepna->poprzednia = nowa;
			BEG->nastepna = nowa;
		}
		else {
			END = nowa;
			END->poprzednia = BEG;
			BEG->nastepna = END;
			END->nastepna = BEG;
		}
	}
	else if (END != 0 && x[0] == 'E' && x[1] == 'N' && x[2] == 'D') {
		nowa->nastepna = BEG;
		nowa->poprzednia = END;
		END->nastepna = nowa;
		END = nowa;
	}
	else if (x[0] == '0' || x[0] == '1' || x[0] == '2' || x[0] == '3' || x[0] == '4' || x[0] == '5' || x[0] == '6' || x[0] == '7' || x[0] == '8' || x[0] == '9') {
		unsigned short i;
		i = (unsigned short)x[0] - 48;
		if (tab[i] == END) {
			nowa->nastepna = BEG;
			nowa->poprzednia = END;
			END->nastepna = nowa;
			END = nowa;
		}
		else {
			if (tab[i] != 0) {
				nowa->nastepna = tab[i]->nastepna;
				nowa->poprzednia = tab[i];
				tab[i]->nastepna->poprzednia = nowa;
				tab[i]->nastepna = nowa;
			}
		}
	}
}

void lista::wypisz(char p[3]) {
	liczba* temp = BEG;
	if (p[0] == 'B' && p[1] == 'E' && p[2] == 'G') {
		printf("%llu ", BEG->key);	//cout << BEG->key << endl;
	}
	else if (p[0] == 'A' && p[1] == 'L' && p[2] == 'L' && BEG!=0 && END!=0) {	
			while (temp->nastepna) {
				printf("%llu ", temp->key);		//cout << temp->key << " ";
				temp = temp->nastepna;
				if (temp == END) break;
			}if (BEG != END) printf("%llu ", END->key); //cout << END->key << endl;
		}
	else if (p[0] == 'E' && p[1] == 'N' && p[2] == 'D') {
		printf("%llu ", END->key); //cout << END->key << endl;
	}
	else if (p[0] == '0' || p[0] == '1' || p[0] == '2' || p[0] == '3' || p[0] == '4' || p[0] == '5' || p[0] == '6' || p[0] == '7' || p[0] == '8' || p[0] == '9' ) {
		unsigned short i;
		i = (unsigned short)p[0]-48;
		printf("%llu ", tab[i]->key);	//cout << tab[i]->key << endl;
	}
}


void lista::iterator(unsigned short x, char y[3]) {
	if (y[0] == 'B' && y[1] == 'E' && y[2] == 'G') {
		tab[x] = BEG;
		BEG->nastepna->poprzednia = tab[x];
		END->nastepna = tab[x];
	}
	else if (y[0] == 'E' && y[1] == 'N' && y[2] == 'D') {
		tab[x] = END;
		END->poprzednia->nastepna = tab[x];
		tab[x]->nastepna = BEG;
	}
	else if (y[0] == '0' || y[0] == '1' || y[0] == '2' || y[0] == '3' || y[0] == '4' || y[0] == '5' || y[0] == '6' || y[0] == '7' || y[0] == '8' || y[0] == '9') {
		unsigned short i;
		i = (unsigned short)y[0] - 48;
		if (i != x) {		
			tab[x] = tab[i];
		}
	}
}
void lista::usun(char x[3]) {
	if (x[0] == 'E' && x[1] == 'N' && x[2] == 'D') {
		if (BEG != END) {
			liczba* temp = END;
			END = END->poprzednia;
			delete temp;
			BEG->poprzednia = END;
			END->nastepna = BEG;
		}
		else { 
			delete BEG;
			BEG = 0;
			END = 0;
			for (unsigned short i = 0; i < 10; i++)
				tab[i] = nullptr;
		}
	}
	else if (x[0] == 'B' && x[1] == 'E' && x[2] == 'G') {
		if (BEG != END) {
			liczba* temp = BEG;
			BEG = BEG->nastepna;
			delete temp;
			END->nastepna = BEG;
			BEG->poprzednia = END;
		}
		else {
			delete BEG;
			BEG = 0;
			END = 0;
			for (unsigned short i = 0; i < 10; i++)
				tab[i] = nullptr;
		}	
	}
	else if (x[0] == '0' || x[0] == '1' || x[0] == '2' || x[0] == '3' || x[0] == '4' || x[0] == '5' || x[0] == '6' || x[0] == '7' || x[0] == '8' || x[0] == '9') {
		unsigned short i;
		i = (unsigned short)x[0] - 48;
		liczba* temp = tab[i];
		if (tab[i] != BEG) {
			if (tab[i] == END) {
				for (unsigned short y = 0; y < 10; y++){
					if (tab[y] == tab[i] && y != i) {
						tab[y]->nastepna->poprzednia = tab[y]->poprzednia;
						tab[y] = tab[y]->poprzednia;
					}
				}
				liczba* temp1 = END;
				BEG->poprzednia = tab[i]->poprzednia;
				tab[i] = tab[i]->poprzednia;
				END = tab[i];
				END->nastepna = BEG;
				delete temp1;
			}
			else {				
				for (unsigned short y = 0; y < 10; y++) {
					if (tab[i] != END) {
						if (tab[y] == tab[i] && y != i) {
							tab[y]->nastepna->poprzednia = tab[y]->poprzednia;
							tab[y]->poprzednia->nastepna = tab[y]->nastepna;
							tab[y] = tab[y]->nastepna;
						}
					}
				}
				tab[i]->nastepna->poprzednia = tab[i]->poprzednia;
				tab[i]->poprzednia->nastepna = tab[i]->nastepna;
				tab[i] = tab[i]->nastepna;
				delete temp;
			}
		}
		else {
			if (BEG != END) {
				liczba* temp2 = BEG;
				BEG = BEG->nastepna;
				delete temp2;
				END->nastepna = BEG;
				BEG->poprzednia = END;
			}
			else {
				delete BEG;
				BEG = 0;
				END = 0;
				for (i = 0; i < 10; i++)
					tab[i] = nullptr;
			}
		}
	}
}
void lista::przesun(unsigned short x) {
	if (tab[x] != 0) {
		if (tab[x]->nastepna != BEG) tab[x] = tab[x]->nastepna;	
	}
}
void lista::cofnij(unsigned short x) {
	if (tab[x] != 0) {
		if(tab[x]->poprzednia!=END) tab[x] = tab[x]->poprzednia;
	}
}