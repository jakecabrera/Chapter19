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
	// Only continue if the MathStack is in a sufficient state
	if (!good()) return;

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
	// Only continue if the MathStack is in a sufficient state
	if (!good()) return;

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
	// Only continue if the MathStack is in a sufficient state
	if (!good()) return;

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
	// Only continue if the MathStack is in a sufficient state
	if (!good()) return;

	int a, b; // to hold the top two values in the stack

	// retrieve top two values
	pop(a);
	pop(b);

	// Check for division by 0
	if (b == 0) {
		// We can't do this operation so put the stack in a 
		// broken state and don't perform the operation.
		state = false;

		// Put the values back on the stack
		push(b);
		push(a);

		return;
	}

	// Push their quotient onto the stack
	push(a / b);
}

// *********************************************************
// name:		ignore
// called by:	nobody
// passed:		nothing
// returns:		nothing
// calls:		nobody
// The ignore function makes the stack ignore the fact that
// the last operation failed and resets the state of the stack
// to good.
// *********************************************************

void MathStack::ignore() {
	state = true;
}

// *********************************************************
// name:		good
// called by:	nobody
// passed:		nothing
// returns:		bool as state of stack
// calls:		nobody
// The good function returns false only if the stack tried and
// failed an operation.
// *********************************************************

bool MathStack::good() {
	return state;
}