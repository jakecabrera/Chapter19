#pragma once
#include <string>
#include <iostream>

using namespace std;

// Class for the node of each element in the IntStack class.
class IntStackNode
{
public:
	int value;
	IntStackNode *lower; // To point to the node before itself

	// Constructor
	// No default constructor because our node NEEDS a value
	IntStackNode(int val) {
		value = val;
	}
};

class IntStack
{
private:
	IntStackNode *top; // Most recent element in the stack
	int numElements = 0;
public:
	// Constructor
	IntStack() {
		top = nullptr;
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
