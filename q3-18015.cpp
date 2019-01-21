#include<iostream>

using namespace std;

void myswap(int &x,int &y) {
	int temp=x;
	x = y;
	y = temp;
}

void myswap(int * &x, int * &y) {
	int * temp = x;
	x = y;
	y = temp;
}

void PrintValues(int x, int y, int * p, int *q) {
	cout << endl;
	cout << "x=" << x << "   y="<<y << endl;
	cout << "p=" << p << "   q="<<q << endl;
	cout << "*p=" << *p << "   *q=" << *q << endl;
}

void main() {

	int x, y;
	int *p, *q;

	//set values
	x = 5;
	y = 9;

	//point pointers
	p = &x;
	q = &y;

	PrintValues(x, y, p, q);

	//myswap x,y
	cout << endl << "myswapping x,y";
	myswap(x, y);
	PrintValues(x, y, p, q);

	//myswap p,q
	cout << endl << "myswapping p,q";
	myswap(p, q);
	PrintValues(x, y, p, q);

	int dum;
	cin >> dum;
}