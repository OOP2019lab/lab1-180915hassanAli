#include <iostream>
#include <fstream>

using namespace std;

int StrToNum(char * Str) {

	int Num;

	for (int c = 0;c < strlen(Str);++c) {
		Num = Str[c] - '0';
	}

	return Num;
}

float StrToRealNum(char * Str) {

	float Num;

	for (int c = 0;c < strlen(Str);++c) {
		Num = Str[c] - '0';
	}

	return Num;
}

void main() {

	ifstream FileIn("input.txt");

	ofstream FileOut("output.txt");

	char LOT[500];
	char Base[500];
	char Pow[500];

	FileIn.getline(LOT, 500);

	int CaseNum = StrToNum(LOT);

	for (int c = 0;c < CaseNum;++c) {

		FileIn.getline(LOT, 500);

		int LOTCOUNT = 0;
		int BaseCount = 0;
		while (LOT[LOTCOUNT] != ' ') {
			Base[BaseCount] = LOT[LOTCOUNT];
			++BaseCount;
			++LOTCOUNT;
		}
		++BaseCount;
		Base[BaseCount] = '\0';

		++LOTCOUNT;

		int PowCount = 0;
		while (LOT[LOTCOUNT] != '\0') {
			Pow[PowCount] = LOT[LOTCOUNT];
			++PowCount;
			++LOTCOUNT;
		}
		++PowCount;
		Pow[PowCount] = '\0';

		int base = StrToRealNum(Base);
		int pow = StrToRealNum(Pow);

		
	}



	

}