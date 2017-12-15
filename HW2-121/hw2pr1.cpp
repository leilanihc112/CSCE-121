// Leilani Horlander-Cruz
// CSCE 121-505
// Due: September 15, 2016
// hw2pr1.cpp

#include "std_lib_facilities_4.h"

int main()
{
	try {
		double income;
		cout << "Income in dollars? ";
		while (cin >> income) {
			if (income < 0) {
				error("Income must be greater than or equal to 0");
			}
			double give;
			double save;
			double live;
			give = income*.1;
			save = income*.1;
			live = income*.8;
			cout << "You should give away about $" 
			     << fixed
			     << setprecision(2)
			     << give 
			     << ", save about $" 
			     << fixed
			     << setprecision(2)
			     << save 
			     << ", and live on about $"
			     << fixed
			     << setprecision(2)
			     << live
			     << "."
			     << endl;
			cout << "Income in dollars? ";
	 	    }
		return 0;
	    }
	catch (exception& e) {
		cerr << "error: " << e.what() << '\n';
		keep_window_open();
		return 1;
	}
	catch (...) {
		cerr << "Oops unknown exception!" << '\n';
		keep_window_open();
		return 2;
	}
	return 0;
}
