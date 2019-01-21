#include <iostream>
#include <cstdlib>

using namespace std;

#pragma region Input Number

//returns string of input from console
char * TakeInput() {
	char * Input = new char[500];
	cin >> Input;

	return Input;
}

//returns number entered
//returns -1 if input not correct
int ReturnPositiveNum() {
	//stores number
	int Num = 0;

	//stores raw input
	char * Input = TakeInput();
	int InputLenght = strlen(Input);

	//checks if input is valid
	for (int x = 0;x < InputLenght;++x) {

		if (!(Input[x] >= '0' && Input[x] <= '9')) {
			return -1;
		}
		else {
			Num = Num * 10 + Input[x] - '0';
		}
	}

	return Num;
}

//returns a positive integer
int InputNumOfRnd() {
	int NumOfRnd;

	cout << "Enter number of random numbers to output: ";
	NumOfRnd = ReturnPositiveNum();

	while (NumOfRnd == -1) {
		cout << "Invalid input. Please enter the number again: ";
		NumOfRnd = ReturnPositiveNum();
	}

	return NumOfRnd;
}
#pragma endregion Input

//fills LOT with the pattern
void FindLine(char * LOT,int NumOfLines,int LineNum) {
	//which number should be printed
	int NumToPrint = LineNum;

	//to reset pattern after midway
	if (LineNum > NumOfLines) {
		LineNum = 2 * NumOfLines - LineNum;
	}

	for (int x = 0;x < LineNum;++x) {
		LOT[x] = NumToPrint +'0';
	}

	for (int x = LineNum;x<NumOfLines;++x) {
		LOT[x] = '*';
	}

	for (int x = NumOfLines;x<(2*NumOfLines-LineNum);++x) {
		LOT[x] = '*';
	}

	for (int x = (2 * NumOfLines - LineNum);x < 2*NumOfLines;++x) {
		LOT[x] = NumToPrint + '0';
	}

	LOT[2 * NumOfLines] = '\0';
}

void main() {
	//stores how many lines are to be printed
	int NumOfLines = InputNumOfRnd();

	//stores one line of pattern
	char * LOT = new char[NumOfLines+1];

	for (int LineNum = 1;LineNum < 2*NumOfLines;++LineNum) {
		
		FindLine(LOT, NumOfLines ,LineNum);

		cout << LOT << endl;
	}


	int dum;
	cin >> dum;
}