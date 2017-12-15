//Leilani Horlander-Cruz
//CSCE 121-505
//Due: September 22, 2016
//hw3pr2.cpp

#include "std_lib_facilities_4.h"

int main() 
{
	try {
		vector<string> answers = {"Amendment 1 guarantees freedom of religion, speech, press, assembly, and petition.", "Amendment 2 guarantees the right to bear arms.", "Amendment 3 protects against quartering of soldiers.", "Amendment 4 protects against unlawful searches and seizures.", "Amendment 5 guarantees the rights of persons accused of crimes.", "Amendment 6 guarantees the freedom to a speedy and public trial.", "Amendment 7 guarantees trial by jury in civil cases.", "Amendment 8 provides limitations on bail and punishments.", "Amendment 9 guarantees rights that are not listed in the Constitution to the people.", "Amendment 10 confirms that the states or people have all powers not given to the national government."};
		cout << "Which amendment? ";
		double amend;
		while (cin >> amend) {
			if (amend <= 0 || amend > 10 || amend != floor(amend)) {        //if input is not an integer or between 1 & 10
				cout << "That is not a valid input. Please enter an integer between 1 and 10." << endl;   //error message
				cout << "Which amendment? "; 
			}
			else {
				amend = amend-1;               //since first element of vector is v[0]
				cout << answers[amend] << endl;
				cout << "Which amendment? ";
			}
		}
		return 0;
	}
	catch (exception& e) {
		cerr << "error: " << e.what() << '\n';
		return 1;
	}
	catch (...) {
		cerr << "Oops unknown error!\n";
		return 2;
	}
	return 0;
}
