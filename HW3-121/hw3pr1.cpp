//Leilani Horlander-Cruz
//CSCE 121-505
//Due: September 22, 2016
//hw3pr1.cpp

#include "std_lib_facilities_4.h"

int main() 
{
	try {
		double amend;
		cout << "Which amendment? ";
		while (cin >> amend) {
			if (amend <= 0 || amend > 10 || amend != floor(amend)) {           //if input is not an integer or between 1 & 10
				cout << "That is not a valid input. Please enter an integer between 1 and 10." << endl;    //error message
				cout << "Which amendment? ";
			}
			else {
				if (amend == 1) cout << "Amendment 1 guarantees freedom of religion, speech, press, assembly, and petition." << endl;
				else if (amend == 2) cout << "Amendment 2 guarantees the right to bear arms." << endl;
				else if (amend == 3) cout << "Amendment 3 protects against quartering of soldiers." << endl;
				else if (amend == 4) cout << "Amendment 4 protects against unlawful searches and seizures." << endl;
				else if (amend == 5) cout << "Amendment 5 guarantees the rights of persons accused of crimes." << endl;
				else if (amend == 6) cout << "Amendment 6 guarantees the freedom to a speedy and public trial." << endl;
				else if (amend == 7) cout << "Amendment 7 guarantees trial by jury in civil cases." << endl;
				else if (amend == 8) cout << "Amendment 8 provides limitations on bail and punishments." << endl;
				else if (amend == 9) cout << "Amendment 9 guarantees rights that are not listed in the Constitution to the people." << endl;
				else if (amend == 10) cout << "Amendment 10 confirms that the states or people have all powers not given to the national government." << endl;
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
