#include "std_lib_facilities_4.h"

namespace X
{
	int var;
	void print() 
	{
		cout << var << endl;
	} 
}
namespace Y
{
	int var;
	void print()
	{
		cout << var << endl;
	}
}
namespace Z
{
	int var;
	void print()
	{
		cout << var << endl;
	}
}

int main()
{
	try {
		X::var = 7;
		X::print();		//print X's var
		using namespace Y;
		var = 9;
		print();		//print Y's var
		{
			using Z::var;
			using Z::print;
			var = 11;
			print();	//print Z's var
		}
		print();		//print Y's var
		X::print();		//print X's var
		return 0;
	}
	catch (exception& e) {
		cerr << "error: " << e.what() << '\n';
		return 1;
	}
	catch (...) {
		cerr << "Oops unknown error!\n";
		return 2;
	}
	return 0;
}
