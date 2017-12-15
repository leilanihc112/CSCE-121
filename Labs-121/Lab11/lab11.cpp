#include "std_lib_facilities_4.h"

void fill_vector(istream& ist, vector<int>& v, char terminator)
	// read integers from ist into v until we reach eof() or terminator
{
	for (int i; ist>>i; ) v.push_back(i);
	if (ist.eof()) return;      // fine: we found the end of file
	
	if (ist.bad()) error("ist is bad");   // stream corrupted; let's get out of here!
	if (ist.fail()) {   // clean up the mess as best we can and report the problem
		ist.clear();  // clear stream state,
			      // so that we can look for terminator
		char c;
		ist>>c;       // read a character, hopefully terminator
		if (c != terminator) {          // unexpected character
			ist.unget();            // put that character back
			ist.clear(ios_base::failbit);  // set the state to fail()
		}
	}
}

int main()
{
	try
	{
		cin.exceptions(cin.exceptions()|ios_base::badbit);
		vector<int> v;
		fill_vector(cin, v, '*');      // end with '*'
		int v_add = 0;                 // start with 0
		for (unsigned int i = 0; i < v.size(); ++i)  // add elements of vector v together
		{
			v_add = v_add + v[i];
		}
		cout << v_add;   // output sum
	}
	catch (exception& e) {
		cerr << "error: " << e.what() << '\n';
	}
	catch (...) {
		cerr << "Oops: unknown exception!\n";
	}
}
