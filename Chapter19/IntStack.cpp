#include "IntStack.h"

using namespace std;

// Destructor
IntStack::~IntStack()
{
	IntStackNode *nodePtr;
	IntStackNode *nextNode;

	nodePtr = top;

	// Delete all nodes in the stack
	while (nodePtr) {
		nextNode = nodePtr->lower;
		delete nodePtr;
		nodePtr = nextNode;
	}
}

// *********************************************************
// name:		push
// called by:	nobody
// passed:		int as value to be pushed to the top of the stack
// returns:		nothing
// calls:		isEmpty
// The push function takes an integer and puts it on the top
// of the calling stack.
// *********************************************************


void IntStack::push(int val) {
	// Allocate and point to a new Stack node with the given value
	IntStackNode *newNode = new IntStackNode(val);

	// List is not empty, append the new node to the end
	if (!isEmpty()) {
		// Add node to the top of the stack
		newNode->lower = top;
		top->upper = newNode;

		// Point stack top to the new node
		top = newNode;
	}
	// Else, the stack is empty, make the new node the first node
	else {
		bottom = top = newNode;
	}

	numElements++;
}

// *********************************************************
// name:		pop
// called by:	nobody
// passed:		int as container for the value of the last
//				element in the calling stack
// returns:		nothing
// calls:		isEmpty, size
// The pop function takes a variable and stores the value of
// the top most element in the stack into that variable. It
// then calls the destructor of the last element in the stack.
// *********************************************************

void IntStack::pop(int &var) {
	// Stack contains nodes
	if (!isEmpty()) {
		// Get last node's value
		var = top->value;

		if (size() == 1) {
			delete top;
			top = nullptr;
			bottom = nullptr;
		}
		else {
			// Move the tail back one element and delete the old last
			top = top->lower;
			delete top->upper;
			top->upper = nullptr;
		}
		
		numElements--;
	}
	// Stack is empty
	else {
		cout << "ERROR! Stack is empty. No elements to pop out. Exiting program, press [ENTER] to exit..." << endl;
		string tmp;
		getline(cin, tmp);
		exit(EXIT_FAILURE);
	}
}

// *********************************************************
// name:		size
// called by:	pop
// passed:		nothing
// returns:		int as count of elements in stack
// calls:		nobody
// The size function returns the count of elements in the stack.
// *********************************************************

int IntStack::size() {
	return numElements;
}

// *********************************************************
// name:		isEmpty
// called by:	push, pop
// passed:		nothing
// returns:		bool representing if the stack is empty or not
// calls:		nobody
// The isEmpty function checks the amount of elements in the
// stack and returns if the stack is empty or not.
// *********************************************************

bool IntStack::isEmpty() {
	// return is the stack has 0 elements and that tail is not set.
	return (numElements == 0);
}

// *********************************************************
// name:		toString
// called by:	nobody
// passed:		nothing
// returns:		string representing the current state of the stack
// calls:		isEmpty
// The toString function creates and returns a string that
// represents all the elements currently in the stack in order
// from first in to last in.
// *********************************************************

string IntStack::toString() {
	string str = "";
	IntStackNode *nodePtr = bottom;

	// Add all nodes to the string
	while (nodePtr) {
		str += "[" + to_string(nodePtr->value) + "] ";
		nodePtr = nodePtr->upper;
	}

	// Return string containing all nodes
	return str;
}