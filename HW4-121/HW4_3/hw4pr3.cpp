//Leilani Horlander-Cruz
//CSCE 121-505
//Due: October 4, 2016
//hw4pr3.cpp

#include "std_lib_facilities_4.h"

void fibonacci(double x, double y, vector<double>& v, int n)
{
	if (n<1) return;              //deal with low values of n
	if (1<=n) v.push_back(x);
	if (1<=2) v.push_back(y);
	for (int i=2; i<n; ++i) {     //start at 2 because already 2 elements in vector
		int z = x+y;          //next element
		v.push_back(z);
		x = y;                //continue sequence
		y = z;
	}
}
int main()
{
	try {
		double x;
		double y;
		int n;
		cout << "How many elements? ";
		while (cin >> n) {
			if (n < 3) {
				cout << "Number of elements must be greater than or equal to 3\n\n";
				cout << "How many elements? ";
			}
			else {
				break;
			}
		}
		cout << "First element? ";
		cin >> x;
		cout << "Second element? ";
		cin >> y;
		vector<double> vf;
		fibonacci(x,y,vf,n);
		cout << sqrt(vf[vf.size()-1]/vf[vf.size()-3]) << endl;   //print square root of ratio of last element of vector divided by third to last element.
	}
	catch (exception& e) {
		cerr << "error: " << e.what() << '\n';
	}
	catch (...) {
		cerr << "Oops unknown error!" << '\n';
	}
}
