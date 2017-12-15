//Leilani Horlander-Cruz
//CSCE 121-505
//Due: October 11, 2016
//hw5pr3.cpp

#include "std_lib_facilities_4.h"

int main() {
	try {
		string line;
		string search;
		bool found = 0;
		while (true) {
			ifstream fin("/usr/share/dict/words");  //reopen when loop restarts to search again
			cout << "Enter word: ";
			cin >> search;
			while(!fin.eof()) {
				getline(fin,line);
				if (search == line) {    //if words match, then boolean is true, and loop can stop searching
					found = 1;
					break;
				}
				else {
					found = 0;
				}
			}
			if (found == 1)
				cout << "That word is in my dictionary\n";
			else if (fin.eof() && (!found))
				cout << "That word is not in my dictionary\n";
			fin.close(); //close
		}
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
