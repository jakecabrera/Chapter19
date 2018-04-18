#include "MathStack.h"

// *********************************************************
// name:		add
// called by:	nobody
// passed:		nothing
// returns:		bool as operation success
// calls:		push, pop
// The add function adds the top two values in the stack and
// replaces them with their sum
// *********************************************************

bool MathStack::add() {
	int a, b; // to hold the top two values in the stack

	// retrieve top two values
	pop(a);
	pop(b);

	// Push their sum onto the stack
	push(a + b);

	// operation success
	return true;
}

// *********************************************************
// name:		sub
// called by:	nobody
// passed:		nothing
// returns:		bool as operation success
// calls:		push, pop
// The sub function subtracts the top two values in the stack
// and replaces them with their difference. The difference is
// with respect to the top most element before the operation.
// *********************************************************

bool MathStack::sub() {
	int a, b; // to hold the top two values in the stack

	// retrieve top two values
	pop(a);
	pop(b);

	// Push their difference onto the stack
	push(a - b);

	// operation success
	return true;
}

// *********************************************************
// name:		mult
// called by:	nobody
// passed:		nothing
// returns:		bool as operation success
// calls:		push, pop
// The mult function multiplies the top two values in the
// stack and replaces them with their product.
// *********************************************************

bool MathStack::mult() {
	int a, b; // to hold the top two values in the stack

	// retrieve top two values
	pop(a);
	pop(b);

	// Push their product onto the stack
	push(a * b);

	// operation success
	return true;
}

// *********************************************************
// name:		div
// called by:	nobody
// passed:		nothing
// returns:		bool as operation success
// calls:		push, pop
// The div function divides the top value by it's preceding
// value and replaces the two with their quotient. Because
// only integers are allowed on the stack, integer division
// is performed.
// *********************************************************

bool MathStack::div() {
	int a, b; // to hold the top two values in the stack

	// retrieve top two values
	pop(a);
	pop(b);

	// Check for division by 0
	if (b == 0) {
		// We can't do this operation so put the stack in a 
		// broken state and don't perform the operation.
		// Put the values back on the stack
		push(b);
		push(a);

		// operation failure
		return false;
	}

	// Push their quotient onto the stack
	push(a / b);

	// operation success
	return true;
}