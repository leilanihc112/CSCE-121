//Leilani Horlander-Cruz
//CSCE 121-505
//Due: October 4, 2016
//hw4pr2.cpp

#include "Chrono.h"

int main()
{
	try {
		int y;
		int d;
		int m;
		cout << "Enter date as yyyy,mm,dd: ";
		while (cin >> y) //read year
		{
			if (cin.get() != ',')   //make sure comma between y & m
			{
				cout << "expected ,\n";
				cout << "Enter date as yyyy,mm,dd: ";
			}
			cin >> m; //read month
			if (cin.get() != ',')   //make sure comma between m & d
			{
				cout << "expected ,\n";
				cout << "Enter date as yyyy,mm,dd: ";
			}
			cin >> d; //read day
			if (Chrono::is_date(y,m,d) == false) {
				cout << "Invalid date.\n\n";
			}
			else {
				int days_add;
				cout << "Enter number of days to add: ";
				cin >> days_add;
				Chrono::Date::add_day(y,m,d,days_add);
				cout << "That will be " << y << "," << m << "," << d << endl << endl;
			}
			cout << "Enter date as yyyy,mm,dd: ";
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

