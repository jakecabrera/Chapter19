/*
 * Author:	Jake Cabrera
 * Date:	04/17/2018	
 * Chapter 19 programming assignment
 * Math Stack
 */

#include <string>
#include <iostream>
#include <regex>
#include "MathStack.h"

using namespace std;

// Function prototypes
void displayMenu();
int getMenuOption();
int getInt();
void performMath(MathStack*, bool (MathStack::*)(), string);
void push(MathStack*);
void pop(MathStack*);
void display(MathStack*);
void waitToContinue();
void showErrorMessage(string msg);

int main() {
	MathStack *stack = new MathStack();
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
		case 3: // Addition
			performMath(stack, &MathStack::add, "You have chosen to add the top two integers on the stack.");
			break;
		case 4: // Subtraction
			performMath(stack, &MathStack::sub, "You have chosen to subtract the second top integer from the top most integer on the stack.");
			break;
		case 5: // Multiplication
			performMath(stack, &MathStack::mult, "You have chosen to multiply the top two integers on the stack.");
			break;
		case 6: // Division
			performMath(stack, &MathStack::div, "You have chosen to divide the top integer by the next integer on the stack.");
			break;
		case 7:
			display(stack);
			break;
		case 8:
			finished = true;
			break;
		default:
			cout << "Please select an option that is on the menu..." << endl;
			waitToContinue();
			break;
		}
	} while (!finished);

	cout << "Program is finished. Press [ENTER] to exit..." << endl;

	string str;
	getline(cin, str);
	delete stack;
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

		// Validate input as an integer
		if (regex_match(input, regex("0*[1-8]{1}"))) {
			try
			{
				// Input is verified to be a number 1-8
				option = stoi(input);
				validInput = true;
			}
			catch (const std::exception&)
			{
				showErrorMessage("Something unexpected happened.");
			}
		}

		if (!validInput) showErrorMessage("Input must be an integer 1 through 8.");
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

	// Keep asking for valid input until received
	do {
		cout << "Please enter an integer: " << flush;
		getline(cin, input);

		// Validate input as an integer
		if (regex_match(input, regex("\\d+"))) {
			try
			{
				// Input is verified to be just numbers
				// Let's see if it will fit in an int variable
				x = stoi(input);
				validInput = true;
			}
			catch (const std::out_of_range&) {
				showErrorMessage("Input is too large to be an integer.");
			}
			catch (const std::exception&)
			{
				showErrorMessage("Something unexpected happened.");
			}
		}
		else showErrorMessage("Input must be an integer.");
	} while (!validInput);

	cout << endl;
	return x;
}

// *********************************************************
// name:		performMath
// called by:	nobody
// passed:		MathStack as the stack to perform math on
//				MathStack::*operation as the operation to be 
//					performed
//				string as the message to display to the user
// returns:		nothing
// calls:		MathStack::add, MathStack::sub, MathStack::mult
//				MathStack::div, MathStack::size, waitToContinue
// The performMath function will take a stack and a MathStack 
// method and apply that method to the stack. 
// *********************************************************

void performMath(MathStack *stack, bool(MathStack::*operation)(), string msg) {
	// Let the user know what they are doing
	cout << msg << endl;

	// check if operation can be done
	if (stack->size() >= 2) {
		// Perform the operation and check if it was successful
		if ((stack->*operation)()) {
			// operation successful
			cout << "The Operation completed successfully!" << endl << endl;
		}
		else {
			// operation failed
			// right now, the only way an operation could fail is due to
			// division by zero. That's why the specific failure message
			cout << "The operation failed due to a division by zero. Please try a different operation first..." << endl << endl;
		}
	}
	// Not enough elements
	else {
		cout << "However, there are not enough elements to perform this operation." << endl;
		cout << "There must be atleast 2 integers in the stack." << endl << endl;
	}

	waitToContinue();
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

void push(MathStack *stack) {
	cout << "You have chosen to push an integer onto the stack." << endl;
	int x = getInt();
	stack->push(x);
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
//				MathStack::isEmpty
// The pop function takes a stack and removes the last integer
// in the stack.
// *********************************************************

void pop(MathStack *stack) {
	cout << "You have chosen to pop an integer off of the stack." << endl;

	// check if there is anything to pop off in the stack
	if (stack->isEmpty()) {
		cout << "However, the stack is empty and there is nothing to pop off of the stack..." << endl << endl;
	}
	else {
		// There are elements in the stack
		// Pop off the last one and let the user know
		int x;
		stack->pop(x);
		cout << "The integer [" << x << "] has been popped off of the stack." << endl << endl;
	}

	waitToContinue();
}

// *********************************************************
// name:		display
// called by:	nobody
// passed:		MathStack
// returns:		nothing
// calls:		waitToContinue, 
//				MathStack::toString
// The display function prints the current state of the stack
// to the screen.
// *********************************************************

void display(MathStack *stack) {
	cout << "Below is the contents of the stack, displayed horizontally with the top being on the right side:" << endl;
	cout << stack->toString() << endl << endl;

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

// *********************************************************
// name:		showErrorMessage
// called by:	getInt, getMenuOption
// passed:		string as reason of error
// returns:		nothing
// calls:		nobody
// The showErrorMessage function prints to console an error
// and it's reason for being there.
// *********************************************************

void showErrorMessage(string msg) {
	cout << "ERROR! " << msg << " Please try again..." << endl << endl;
}