//Leilani Horlander-Cruz
//CSCE 121-505
//Due: October 4, 2016
//hw4pr4.cpp

#include "Chrono.h"

int main()
{
	try {
		vector<string> day_name = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
		int y;
		int d;
		int m;
		cout << "Enter date yyyy,mm,dd: ";
		while (cin >> y) //read year
		{
			if (cin.get() != ',')   //make sure comma between y & m
			{
				cout << "expected ,\n";
				cout << "Enter date yyyy,mm,dd: ";
			}
			cin >> m; //read month
			if (cin.get() != ',')   //make sure comma between m & d
			{
				cout << "expected ,\n";
				cout << "Enter date yyyy,mm,dd: ";
			}
			cin >> d; //read day
			if (Chrono::is_date(y,m,d) == false) {
				cout << "Invalid date.\n\n";
			}
			else {
				int day_of_week_1;
				day_of_week_1 = Chrono::day_of_week(y,m,d);
				cout << "That is a ";
				if (day_of_week_1 == 0) {
					cout << day_name[0] << ".\n\n";
				}
				else if (day_of_week_1 == 1) {
					cout << day_name[1] << ".\n\n";
				}
				else if (day_of_week_1 == 2) {
					cout << day_name[2] << ".\n\n";
				}
				else if (day_of_week_1 == 3) {
					cout << day_name[3] << ".\n\n";
				}
				else if (day_of_week_1 == 4) {
					cout << day_name[4] << ".\n\n";
				}
				else if (day_of_week_1 == 5) {
					cout << day_name[5] << ".\n\n";
				}
				else if (day_of_week_1 == 6) {
					cout << day_name[6] << ".\n\n";
				}
			}
			cout << "Enter date yyyy,mm,dd: ";
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