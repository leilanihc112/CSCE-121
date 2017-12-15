//Leilani Horlander-Cruz
//CSCE 121-505
//Due: September 8, 2016
//hw1pr3.cpp

#include "std_lib_facilities_4.h"

int main()
{
	cout << "How many pennies do you have?\n";
	int penny;
	cin >> penny;
	cout << "How many nickels do you have?\n";
	int nickel;
	cin >> nickel;
	cout << "How many dimes do you have?\n";
	int dime;
	cin >> dime;
	cout << "How many quarters do you have?\n";
	int quarter;
	cin >> quarter;
	cout << "How many half dollars do you have?\n";
	int half_dollar;
	cin >> half_dollar;
	cout << "How many one-dollar coins do you have?\n";
	int one_dollar;
	cin >> one_dollar;
	cout << "\n";

	double total;
	total = penny*1 + nickel*5 + dime*10 + quarter*25 + half_dollar*50 + one_dollar*100;
	
	if (penny == 1)
		cout << "You have " << penny << " penny.\n";
	else
		cout << "You have " << penny << " pennies.\n";
	
	if (nickel == 1)
		cout << "You have " << nickel << " nickel.\n";
	else
		cout << "You have " << nickel << " nickels.\n";

	if (dime == 1)
		cout << "You have " << dime << " dime.\n";
	else
		cout << "You have " << dime << " dimes.\n";

	if (quarter == 1)
		cout << "You have " << quarter << " quarter.\n";
	else 
		cout << "You have " << quarter << " quarters.\n";

	if (half_dollar == 1)
		cout << "You have " << half_dollar << " half dollar.\n";
	else
		cout << "You have " << half_dollar << " half dollars.\n";

	if (one_dollar == 1)
		cout << "You have " << one_dollar << " one-dollar coin.\n";
	else
		cout << "You have " << one_dollar << " one-dollar coins.\n";
	
	cout << "\nThe value of all of your coins is "
	     << total
	     << " cents or $"
	     << fixed
	     << setprecision(2)
	     << total/100
             << "."
	     << endl; 
	return 0;
}
