#pragma once
#include "IntStack.h"

class MathStack :
	public IntStack
{
public:
	// MathStack operations
	bool add();
	bool sub();
	bool mult();
	bool div();
};

