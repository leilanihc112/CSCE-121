#include "std_lib_facilities_4.h"

double ctok(double c)	// converts Celcius to Kelvin
{
	double k = c + 273.15;
	return k;
}

int main(){
try {
	double c = 0;   // declare input variable
	cin >> c;	// retrieve temperature to input variable
	if (c < -273.15) {
		error("Below absolute zero");
	}
	double k = ctok(c);    // convert temperature
	cout << k << " K" << endl;      // print out temperature
}
catch (exception &e) {
	cerr << "error: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Unknown error\n";
	return 2;
}
return 0;
}
