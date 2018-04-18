/*
 * Author:	Jake Cabrera
 * Date:	04/17/2018	
 * Chapter 19 programming assignment
 * Math Stack
 */

#include <string>
#include <iostream>
#include <iomanip>
#include "MathStack.h"

using namespace std;

// Function prototypes
void displayMenu();
int getMenuOption();
int getInt();
void push(MathStack&);
void pop(MathStack&);
void add(MathStack&);
void sub(MathStack&);
void mult(MathStack&);
void div(MathStack&);
void display(MathStack&);
void waitToContinue();

int main() {
	MathStack stack;
	bool finished = false;
	int menuOption;

	do {
		displayMenu();
		menuOption = getMenuOption();

		switch (menuOption)
		{
		case 1:
			push(stack);
			break;
		case 2:
			pop(stack);
			break;
		case 3:
			add(stack);
			break;
		case 7:
			display(stack);
			break;
		case 8:
			finished = true;
			break;
		default:
			break;
		}
	} while (!finished);

	cout << "Program is finished. Press [ENTER] to exit..." << endl;

	string str;
	getline(cin, str);
	return 0;
}

// *********************************************************
// name:		displayMenu
// called by:	nobody
// passed:		nothing
// returns:		nothing
// calls:		nobody
// The displayMenu function displays the menu which shows the
// operations that you can perform with the stack
// *********************************************************

void displayMenu() {
	cout << "==============================" << endl;
	cout << "Operations:" << endl;
	cout << "==============================" << endl;
	cout << "1. Push" << endl;
	cout << "2. Pop" << endl;
	cout << "3. Add" << endl;
	cout << "4. Subtract" << endl;
	cout << "5. Multiply" << endl;
	cout << "6. Divide" << endl;
	cout << "7. Display" << endl;
	cout << "8. Exit" << endl;
	cout << "==============================" << endl << endl;
}

// *********************************************************
// name:		getMenuOption
// called by:	nobody
// passed:		nothing
// returns:		int as an option from the menu
// calls:		nobody
// The getMenuOption function asks for and retrieves a valid
// int from the user and returns it
// *********************************************************

int getMenuOption() {
	string input;
	int option;
	bool validInput = false;

	// keep asking for input until given valid input
	do {
		// get input
		cout << "Enter a menu option by number: ";
		getline(cin, input);

		try
		{
			// Get an integer from the input or die trying
			option = stoi(input);

			// Validate integer as a valid index
			if (option >= 1 && option <= 8) validInput = true;
			else cout << "ERROR! Input an integer 1 through 8..." << endl << endl;
		}
		catch (...) // Input was not able to be put into an integer
		{
			cout << "ERROR! Input must be an integer 1 through 8. Please try again..." << endl << endl;
		}
	} while (!validInput);

	cout << endl;
	return option;
}

// *********************************************************
// name:		getInt
// called by:	display
// passed:		nothing
// returns:		int
// calls:		nothing
// The getInt function asks and retrieves an integer from the
// user.
// *********************************************************

int getInt() {
	string input;
	int x;
	bool validInput = false;

	do {
		cout << "Please enter an integer: " << flush;
		getline(cin, input);

		try
		{
			x = stoi(input);
			validInput = true;
		}
		catch (const std::exception&)
		{
			cout << "ERROR! Input must be an integer. Press [ENTER] to try again..." << endl << endl;
		}
	} while (!validInput);

	cout << endl;
	return x;
}

// *********************************************************
// name:		push
// called by:	nobody
// passed:		MathStack
// returns:		nothing
// calls:		waitToContinue
//				getInt
//				MathStack::push
// The push function takes a stack and an integer from the
// user and pushes the integer on to the top of the stack
// *********************************************************

void push(MathStack &stack) {
	cout << "You have chosen to push an integer onto the stack." << endl;
	int x = getInt();
	stack.push(x);
	cout << "The integer [" << x << "] has been pushed onto the stack." << endl << endl;
	waitToContinue();
}

// *********************************************************
// name:		pop
// called by:	nobody
// passed:		MathStack
// returns:		nothing
// calls:		waitToContinue
//				MathStack::pop
//				MathStack::size
// The pop function takes a stack and removes the last integer
// in the stack.
// *********************************************************

void pop(MathStack &stack) {
	cout << "You have chosen to pop an integer off of the stack." << endl;

	// check if there is anything to pop off in the stack
	if (stack.size() == 0) {
		cout << "However, the stack is empty and there is nothing to pop off of the stack..." << endl << endl;
	}
	else {
		// There are elements in the stack
		// Pop off the last one and let the user know
		int x;
		stack.pop(x);
		cout << "The integer [" << x << "] has been popped off of the stack." << endl << endl;
	}

	waitToContinue();
}

// *********************************************************
// name:		add
// called by:	nobody
// passed:		MathStack
// returns:		nothing
// calls:		waitToContinue
//				MathStack::add
//				MathStack::size
// The add function adds the top two elements on the given
// stack and replaces them with their sum. High level validation
// of if there are enough elements in the stack to perform 
// the operation.
// *********************************************************

void add(MathStack &stack) {
	cout << "You have chosen to add the top two integers on the stack." << endl;

	// check if operation can be done
	if (stack.size() >= 2) {
		stack.add();
		cout << "The top two integers have been added and replaced with their sum." << endl << endl;
	}
	// Not enough elements
	else {
		cout << "However, there are not enough elements to perform this operation." << endl;
		cout << "There must be atleast 2 integers in the stack." << endl << endl;
	}

	waitToContinue();
}

// *********************************************************
// name:		display
// called by:	nobody
// passed:		nothing
// returns:		nothing
// calls:		waitToContinue, 
//				MathStack::toString
// The display function prints the current state of the stack
// to the screen.
// *********************************************************

void display(MathStack &stack) {
	cout << "Below is the contents of the stack, displayed horizontally with the top being on the right side:" << endl;
	cout << stack.toString() << endl << endl;

	waitToContinue();
}

// *********************************************************
// name:		waitToContinue
// called by:	display
// passed:		nothing
// returns:		nothing
// calls:		nothing
// The waitToContinue function will pause the program until
// the user presses enter.
// *********************************************************

void waitToContinue() {
	string tmp;
	cout << "Press [ENTER] to continue...";
	getline(cin, tmp);
	cout << endl;
}