#pragma once
#include <string>
#include <iostream>

using namespace std;

// Class for the node of each element in the IntStack class.
class IntStackNode
{
public:
	int value;
	// I decided to name these two lower and upper as opposed to
	// prev and next because I visualize the stack like plates
	// in a cafeteria.
	IntStackNode *lower;
	IntStackNode *upper;

	// Constructor
	// No default constructor because our node NEEDS a value
	IntStackNode(int val) {
		value = val;
	}
};

class IntStack
{
private:
	IntStackNode *bottom;
	IntStackNode *top;
	int numElements = 0;
public:
	// Constructor
	IntStack() {
		top = nullptr;
		bottom = nullptr;
	}

	// Destructor
	~IntStack();

	// Stack Operations
	void push(int);
	void pop(int&);
	bool isEmpty();
	int size();
	string toString();
};
