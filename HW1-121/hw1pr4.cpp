//Leilani Horlander-Cruz
//CSCE 121-505
//Due: September 8, 2016
//hw1pr4.cpp

#include "std_lib_facilities_4.h"

int main()
{
	auto x = 1;
	for(auto i = 1; i <= 11; i++) {    //will produce only 11 lines of table
		auto x2 = x * x;
		auto y = sqrt(x2);
		cout << "square root of ("										  << fixed
		     << setprecision(5)
		     << x
		     << " squared) is "
		     << y
		     << endl;
		x *= 10;                   //changes value of x so next line is different value
	}
	cout << "This table produced some odd values because the result will exceed the range of"
	     << " the 'auto' type after some iterations.";
}
