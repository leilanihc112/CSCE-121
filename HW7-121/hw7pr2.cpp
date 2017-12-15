//Leilani Horlander-Cruz
//CSCE 121-505
//Due: December 7, 2016
//hw7pr2.cpp

#include <boost/regex.hpp>
#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include <regex>
#include "std_lib_facilities_4.h"

using namespace std;

int main () {
	try {
		regex uin ("\\d{3}-?00-?\\d{4}"); //UIN pattern
		regex invalid_ssn ("042-?68-?4425|078-?05-?1120|123-?45-?6789|111-?11-?1111|222-?22-?2222|333-?33-?3333|444-?44-?4444|555-?55-?5555|777-?77-?7777|888-?88-?8888|999-?99-?9999|987-?65-?432\\d{1}|666-?\\d{2}-?\\d{4}|000-?\\d{2}-?\\d{4}|\\d{3}-?\\d{2}-?0000|9\\d{2}-?\\d{2}-?\\d{4}"); //invalid SSN patterns
		regex ssn ("\\d{3}-?\\d{2}-?\\d{4}"); //SSN patterns
		string line; //input buffer
		cout << "Enter SSN or UIN:\n"; //prompt
		while (getline(cin,line)) {
			smatch matches; //matches go here
			smatch matches2;
			smatch matches3;
			if (regex_search(line,matches,uin)) { //any valid UIN is invalid SSN
				cout << "valid UIN" << '\n';
				cout << "invalid SSN" << '\n';
			}
			else {
				cout << "invalid UIN" << '\n';
				if (regex_search(line,matches2,invalid_ssn)) //find if invalid SSN
					cout << "invalid SSN" << '\n';
				else if (regex_search(line,matches3,ssn)) //make sure it is valid SSN
					cout << "valid SSN" << '\n';
				else //if not one of specific invalid SSNs or valid SSN, then automatically invalid SSN
					cout << "invalid SSN" << '\n';
			}
			cout << "Enter SSN or UIN:\n"; //prompt
		}
			return 0;
	}
	catch (exception& e) {
		cerr << "error: " << e.what() << '\n';
		return 1;
	}
	catch (...) {
		cerr << "Oops unknown error!" << '\n';
		return 2;
	}
	return 0;
}
