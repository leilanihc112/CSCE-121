#include "std_lib_facilities_4.h"

int main() 
{
	try {
		int num;
		cout << "Please enter a number between 1 and 4 digits\n";
		while (cin >> num) {
			if(!cin) {
				return 1;
			}
			else if (num >= 10000) {
				error("Number must be between 1 and 4 digits\n");
			}
			else if (num>=1000 && num<10000) {
				int num2 = num/1000;
				int num3 = num-num2*1000;
				int num4 = num3/100;
				int num5 = num3-num4*100;
				int num6 = num5/10;
				int num7 = num5-num6*10;
				cout << num << " is " << num2 << " thousand(s) and " << num4 << " hundred(s) and " << num6 << " ten(s) and " << num7 << " one(s).\n";	
			}	
			else if (num>=100 && num<1000) {
				int num2 = num/100;
				int num3 = num-num2*100;
				int num4 = num3/10;
				int num5 = num3-num4*10;
				cout << num << " is " << num2 << " hundred(s) and " << num4 << " ten(s) and " << num5 << " one(s).\n";
			}
			else if (num>=10 && num<100) {
				int num2 = num/10;
				int num3 = num-num2*10;
				cout << num << " is " << num2 << " ten(s) and " << num3 << " one(s).\n";
			}
			else if (num>=0 && num<10) {
				cout << num << " is " << num << " one(s).\n";
			}
			cout << "Please enter another number between 1 and 4 digits\n";
		}
		return 0;
	}
	catch (exception& e) {
		cerr << "error: " << e.what() << '\n';
		return 1;
	}
	catch (...) {
		cerr << "Oops: unknown exception!\n";
		return 2;
	}
	return 0;
}
