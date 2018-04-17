#include <string>
#include <iostream>
#include "MathStack.h"

using namespace std;

int main() {
	string str;
	MathStack stack = MathStack();

	stack.push(1);
	stack.push(3);
	stack.push(2);
	cout << stack.toString() << endl;

	stack.div();

	cout << stack.toString() << endl;

	getline(cin, str);
	return 0;
}