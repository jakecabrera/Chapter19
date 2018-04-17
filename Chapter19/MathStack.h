#pragma once
#include "IntStack.h"

class MathStack :
	public IntStack
{
private:
	bool state = true;
public:
	// MathStack operations
	void add();
	void sub();
	void mult();
	void div();

	// For working with the state of this stack
	void ignore();
	bool good();
};

