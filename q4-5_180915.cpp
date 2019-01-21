#include<iostream>
#include <fstream>

using namespace std;

#pragma region Input
//returns string of input from console
char * TakeInput() {
	char * Input = new char[500];
	cin >> Input;

	return Input;
}

//returns number entered
//returns -1 if input not correct
int CheckInputNum() {
	int Num = 0;
	bool neg = 0;

	char * Input = TakeInput();
	int InputLenght = strlen(Input);

	for (int x = 0;x < InputLenght;++x) {
		if (x == 0 && Input[x] == '-') {
			neg = 1;
		}
		else {
			Num = Num * 10 + Input[x] - '0';
		}
	}

	if (neg == 1) {
		Num = -Num;
	}

	return Num;
}

//returns number entered
//returns -1 if input not correct
int CheckInputPosNum() {
	int Num = 0;

	char * Input = TakeInput();
	int InputLenght = strlen(Input);

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
int ReturnPosNum() {
	int NumOfRnd;

	NumOfRnd = CheckInputPosNum();

	while (NumOfRnd == -1) {
		cout << "Invalid input. Please enter the number again: ";
		NumOfRnd = CheckInputPosNum();
	}

	return NumOfRnd;
}

//returns an integer
int ReturnNum() {
	int NumOfRnd;

	NumOfRnd = CheckInputNum();

	return NumOfRnd;
}
#pragma endregion Input

void InputToArr(int * Arr, int ArrLen) {
	for (int c = 0;c < ArrLen;++c) {
		cout << endl << "Enter element " << c << " : ";
		Arr[c] = ReturnNum();
	}
}

void PrintArr(int * Arr, int ArrLen) {
	for (int c = 0;c < ArrLen;++c) {
		cout << Arr[c] << endl;
	}
}

void SortArr(int * Arr, int ArrLen) {
	int n = ArrLen-1;

	for (int c = 0;c < ArrLen;++c) {

		for (int x = 0; x < n;++x) {
			if (Arr[x] > Arr[x + 1]) {
				swap(Arr[x], Arr[x + 1]);
			}
		}
	}

}

void InputToArrQ5(int * Arr, int ArrLen) {
	for (int c = 0;c < ArrLen;++c) {
		cout << endl << "Enter element " << c << " : ";
		*(Arr+c) = ReturnNum();
	}
}

void SortArrQ5(int * Arr, int ArrLen) {
	int n = ArrLen - 1;

	for (int c = 0;c < ArrLen;++c) {

		for (int x = 0; x < n;++x) {
			if (*(Arr+x) > *(Arr+x + 1)) {
				swap(*(Arr + x), *(Arr + x + 1));
			}
		}
	}

}

void SaveToFile(int * Arr, int ArrLen) {
	ofstream File("results_180915.txt");

	for (int c = 0;c < ArrLen;++c) {
		File << *(Arr + c) << "\n";
	}
}

void Q5() {
	cout << "Enter lenght of array ";
	int ArrLen = ReturnPosNum();

	int * Arr = new int[ArrLen];

	InputToArrQ5(Arr, ArrLen);

	SortArrQ5(Arr, ArrLen);

	SaveToFile(Arr, ArrLen);

}

void main() {
	cout << "Enter lenght of array ";
	int ArrLen = ReturnPosNum();
	
	int * Arr = new int[ArrLen];

	InputToArr(Arr, ArrLen);

	SortArr(Arr, ArrLen);

	PrintArr(Arr, ArrLen);

	cout << "q5";
	Q5();

	int dum;
	cin >> dum;
}