#pragma once
#include "IntStack.h"

class MathStack :
	public IntStack
{
public:
	// Constructor
	MathStack() {

	};

	// MathStack operations
	void add();
	void sub();
	void mult();
	void div();
};

