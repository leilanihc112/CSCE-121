#include "std_lib_facilities_4.h"

int main()
{
	int A = int('A');

	for (int i = int('a'); i <= int('z'); ++i) {
		cout << i << '\t' << char(i) << '\t' << A << '\t' << char(A) << endl;
		A++;
	}
return 0;
}
