#ifndef __COMPEX__
#define __COMPEX__
#include"complex.h"
int main() {
	complex c1(1, 2);
	complex c2(1, 3);
	cout << c1 << endl;
	cout << c1 + c2 << endl;
	cout << c1 + 1 << endl;
	cout << 1 + c1 << endl;
	c1 += c2;
	cout << c1 << endl;
	c1 = c1 + 1;
	cout << c1 << endl;
}















#endif
