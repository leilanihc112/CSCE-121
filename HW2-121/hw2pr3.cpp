// Leilani Horlander-Cruz
// CSCE 121-505
// Due: September 15, 2016
// hw2pr3.cpp

#include "std_lib_facilities_4.h"

double my_cbrt_1(double n)   // finds approximate cube root
{
	double c = -0.411665*pow(n,2) + 1.03455*n + 0.377113;
	return c;
}
template<typename T> void print_element(T t, const int& width)   // prints in columns
{
	const char separate = ' ';
	cout << left << setw(width) << setfill(separate) << t;
}

int main()
{
	try {
		double n = 0;
		const int col_width = 20;
		print_element("n", col_width);
		print_element("cbrt", col_width);
		print_element("my_cbrt_1", col_width);
		print_element("relative_error_per_cent", col_width);
		cout << '\n';
		for (auto k : {-100,-10,-1,0,1,10,100}) {    // n = pi*10^k,k={-100,-10,-1,0,1,10,100}
			n = M_PI*pow(10.0,k);
			print_element(n, col_width);
			print_element(cbrt(n), col_width);
			print_element(my_cbrt_1(n), col_width);
			print_element(100*((my_cbrt_1(n)-cbrt(n))/cbrt(n)), col_width);
			cout << '\n';
		}
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