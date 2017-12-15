//Leilani Horlander-Cruz
//CSCE 121-505
//Due: September 8, 2016
//hw1pr2.cpp

#include "std_lib_facilities_4.h"

int main()
{
	cout << "Please enter a value followed by an operation (+,-,*,/,plus,minus,mul,div)"
	     << " followed by another value. Make sure to separate by spaces. To terminate program"
	     << " enter '|'\n";
	double left;        //left is the first value
	double right;       //right is the second value
	string operation;
	char input = 'a';   //variable for terminating program
	while (cin >> left >> operation >> right) {   //read multiple inputs until Crtl-D or Z or C 							    typed by user) 
		if (operation == "plus" || operation == "+") {
			cout << "Answer is " << left+right << "\n";
		}
		else if (operation == "minus" || operation == "-") {
			cout << "Answer is " << left-right << "\n";
		}
		else if (operation == "mul" || operation == "*") {
			cout << "Answer is " << left*right << "\n";
		}
		else if (operation == "div" || operation == "/") {
			if (right == 0) {
				cout << "Error: Cannot divide by zero\n";
			}
			else {
				cout << "Answer is " << left/right << "\n";
			}
		}
		else {
			cout << "Error: Operation must be one of the following (+,-,*,/,plus,minus,"
		    	     << "mul,div)\n";
		}
		if (input == '|') {
			break;
		}
		cout << "Try again or enter '|' to terminate program\n";   //prompt to read another
								  	   //arithmetic expression
	}
	return 0;
}
