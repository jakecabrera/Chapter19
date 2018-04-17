#include "MathStack.h"

// *********************************************************
// name:		add
// called by:	nobody
// passed:		nothing
// returns:		nothing
// calls:		push, pop
// The add function adds the top two values in the stack and
// replaces them with their sum
// *********************************************************

void MathStack::add() {
	int a, b; // to hold the top two values in the stack

	// retrieve top two values
	pop(a);
	pop(b);

	// Push their sum onto the stack
	push(a + b);
}

// *********************************************************
// name:		sub
// called by:	nobody
// passed:		nothing
// returns:		nothing
// calls:		push, pop
// The sub function subtracts the top two values in the stack
// and replaces them with their difference. The difference is
// with respect to the top most element before the operation.
// *********************************************************

void MathStack::sub() {
	int a, b; // to hold the top two values in the stack

	// retrieve top two values
	pop(a);
	pop(b);

	// Push their difference onto the stack
	push(a - b);
}

// *********************************************************
// name:		mult
// called by:	nobody
// passed:		nothing
// returns:		nothing
// calls:		push, pop
// The mult function multiplies the top two values in the
// stack and replaces them with their product.
// *********************************************************

void MathStack::mult() {
	int a, b; // to hold the top two values in the stack

	// retrieve top two values
	pop(a);
	pop(b);

	// Push their product onto the stack
	push(a * b);
}

// *********************************************************
// name:		div
// called by:	nobody
// passed:		nothing
// returns:		nothing
// calls:		push, pop
// The div function divides the top value by it's preceding
// value and replaces the two with their quotient. Because
// only integers are allowed on the stack, integer division
// is performed.
// *********************************************************

void MathStack::div() {
	int a, b; // to hold the top two values in the stack

	// retrieve top two values
	pop(a);
	pop(b);

	// Check for division by 0
	if (b == 0) {
		cout << "ERROR! Division by zero. Exiting program, press [ENTER] to exit..." << endl; 
		string tmp;
		getline(cin, tmp);
		exit(EXIT_FAILURE);
	}

	// Push their quotient onto the stack
	push(a / b);
}