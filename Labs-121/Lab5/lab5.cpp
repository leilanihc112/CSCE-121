#include "std_lib_facilities_4.h"

int main()
{
	char input = 'a';
	vector<double> numbers; //declare vector of double type to store
	double num1 = 0;
	string unit = "none";
	double num2 = 0;
	double num3 = 0;
	double num4 = 0;
	string unit2 = "none";
	string unit3 = "none";
	cout << "Enter a value followed by a unit (cm,in,ft,m) or enter '|' to terminate\n";
	while (cin >> num1 >> unit) {		
		if (unit == "in") {
			num2 = num1*2.54;
			numbers.push_back(num2); 
			sort(numbers.begin(),numbers.end());
			if (num2 == numbers.back()) {
				num3 = num1;
				unit2 = unit;
				cout << num1 << unit << ": the largest number so far" << endl;
			}
			else if (num2 == numbers.front()) {
				num4 = num1;
				unit3 = unit;
				cout << num1 << unit << ": the smallest number so far" << endl;
			}
			else {
				cout << num1 << unit << endl;
			}
		}
		else if (unit == "ft") {
			num2 = num1*12*2.54;
			numbers.push_back(num2);
			sort(numbers.begin(),numbers.end());
			if (num2 == numbers.back()) {
				num3 = num1;
				unit2 = unit;
				cout << num1 << unit << ": the largest number so far" << endl;
			}
			else if (num2 == numbers.front()) {
				num4 = num1;
				unit3 = unit;
				cout << num1 << unit << ": the smallest number so far" << endl;
			}
			else {
				cout << num1 << unit << endl;
			}
		}
		else if (unit == "m") {
			num2 = num1*100;
			numbers.push_back(num2);
			sort(numbers.begin(),numbers.end());
			if (num2 == numbers.back()) {
				num3 = num1;
				unit2 = unit;
				cout << num1 << unit << ": the largest number so far" << endl;
			}
			else if (num2 == numbers.front()) {
				num4 = num1;
				unit3 = unit;
				cout << num1 << unit << ": the smallest number so far" << endl;
			}
			else {
				cout << num1 << unit << endl;
			}
		}
		else if (unit == "cm") {
			num2 = num1;
			numbers.push_back(num2);
			sort(numbers.begin(),numbers.end());
			if (num2 == numbers.back()) {
				num3 = num1;
				unit2 = unit;
				cout << num1 << unit << ": the largest number so far" << endl;
			}
			else if (num2 == numbers.front()) {
				num4 = num1;
				unit3 = unit;
				cout << num1 << unit << ": the smallest number so far" << endl;
			}
			else {
				cout << num1 << unit << endl;
			}
		}
		else {
			cout << "Error: unit must be (cm,in,ft,m)" << endl;			
		}	
		cout << "Enter a value or enter '|' to terminate\n";
		if (input == '|') {
			break;
		}
	}
	double sum1;
	for (unsigned int i = 0; i < numbers.size(); ++i) {
		sum1 += numbers[i];
	}
	sum1 = sum1/100;
	cout << '\n' << "The smallest value entered: " << num4 << unit3 << endl
	     << "The largest value entered: " << num3 << unit2 << endl
	     << "Number of values entered: " << size(numbers) << endl
	     << "Sum of values entered: " << sum1 << "m" << endl;
	return 0;
}
