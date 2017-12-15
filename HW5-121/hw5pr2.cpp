//Leilani Horlander-Cruz
//CSCE 121-505
//Due: October 11, 2016
//hw5pr2.cpp

#include "std_lib_facilities_4.h"

void classify(char c) {
    //classify characters
	cout << "\n'" << c << "' is:\n";
	if (isspace(c)) 
		cout << "a space\n";
	if (isalpha(c))
		cout << "a letter\n";
	if (isdigit(c)) 
		cout << "a decimal digit\n";
	if (isxdigit(c)) 
		cout << "a hexadecimal digit\n";
	if (isupper(c)) 
		cout << "an uppercase letter\n";
	if (islower(c)) 
		cout << "a lowercase letter\n";
	if (isalnum(c)) 
		cout << "alphanumeric\n";
	if (iscntrl(c)) 
		cout << "a control character\n";
	if (ispunct(c)) 
		cout << "punctuation\n";
	if (isprint(c)) 
		cout << "printable\n";
	if (isspace(c)) 
		cout << "graphical\n";
}

int main() {
	try {
		string line;
		cout << "Enter a string to classify: ";
		getline(cin,line); //entire line of input (which is entire input)
			for(size_t i = 0; i<line.size(); ++i)
				classify(line[i]); //classify each character
		return 0;
	}
	catch (exception& e) {
		cerr << "error: " << e.what() << endl;
		return 1;
	}
	catch (...) {
		cerr << "Oops unknown error!" << endl;
		return 2;
	}
	return 0;
}
