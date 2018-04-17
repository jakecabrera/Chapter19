#include <string>
#include <iostream>
#include "IntStack.h"

using namespace std;

int main() {
	string str;
	IntStack stack = IntStack();
	int val;
	stack.push(1);
	stack.push(3);
	stack.push(2);
	cout << stack.toString() << endl;
	cout << stack.size() << endl;

	stack.pop(val);
	cout << val << endl;

	cout << stack.toString() << endl;
	cout << stack.size() << endl;

	getline(cin, str);
	return 0;
}