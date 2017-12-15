//Leilani Horlander-Cruz
//CSCE 121-505
//Due: October 4, 2016
//hw4pr1.cpp

#include "Chrono.h"

int main()
{
	try {
		int y;
		bool valid = false;
		cout << "Enter year (0 to quit): ";
		while (!valid) {                               //will loop until program is ended by Ctrl-Z or "0"
			try { 
				cin >> y;
			}
			catch (const std::out_of_range& oor) { //catch out of range error message
				std::cerr << "Out of range error: " << oor.what() << '\n';
			}
			if (cin.fail()) {                      //if bad input
				cin.clear();                   //clears error flag on cin
				cin.ignore(1000000,'\n');      //skips to next new line to ignore up to 1000000 characters on same line as non-number
							       //assumes that user will not input more than 1000000 characters at once
				cout << "That is not a valid input. Please enter a year in the form of a positive integer.\n" << endl;   //error message
				cout << "Enter year (0 to quit): ";    //reprompt; allow user to try again
			}
			else if (y == 0) {
				break;
			}
			else if (y < 0) {
				cout << "That is not a valid input. Please enter a year in the form of a positive integer.\n" << endl;   //error message
				cout << "Enter year (0 to quit): ";
			}
			else if (Chrono::leapyear(y) == true) {
				cout << y << " is a leap year\n\n";
				cout << "Enter year (0 to quit): ";
			}
			else {
				cout << y << " is not a leap year\n\n";
				cout << "Enter year (0 to quit): ";
			}
		}
		return 0;
	}
	catch (exception& e) {
		cerr << "error: " << e.what() << '\n';
	}
	catch (...) {
		cerr << "Oops unknown error!" << '\n';
	}
	return 0;
}
