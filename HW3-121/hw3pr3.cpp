//Leilani Horlander-Cruz
//CSCE 121-505
//Due: September 22, 2016
//hw3pr3.cpp

#include "std_lib_facilities_4.h"

using namespace std::chrono;
//linear congruential pseudorandom number generator
int randint(){
        //use the clock for an initial pseudorandom number
        static long x = time_point_cast<microseconds>(system_clock::now())
		.time_since_epoch().count() & 0x7fffffff; //CORRECTED
        //calculate the next pseudorandom number
        x = (1103515245 * x + 12345) & 0x7fffffff;    //parameters from glibc(?)
        return x;
}
int main() 
{
	try {
		int zeros = 0;
		int ones = 0;
		int twos = 0;
		int threes = 0;
		int fours = 0;
		int fives = 0;
		int sixes = 0;
		int sevens = 0;
		int eights = 0;
		int nines = 0;
		for (unsigned int i = 1; i <= 1000000; ++i) {           //start with 1st number, and go 1000000 times
			double randint_ten = randint(i) % 10;          //divide randint by 10 and return remainder 
								       //will give final digit of randint
			if (randint_ten == 0) zeros = zeros+1;         //keeping track of how many times final digit is 0, and so on
			else if (randint_ten == 1) ones = ones+1;
			else if (randint_ten == 2) twos = twos+1;
			else if (randint_ten == 3) threes = threes+1;
			else if (randint_ten == 4) fours = fours+1;
			else if (randint_ten == 5) fives = fives+1;
			else if (randint_ten == 6) sixes = sixes+1;
			else if (randint_ten == 7) sevens = sevens+1;
			else if (randint_ten == 8) eights = eights+1;
			else if (randint_ten == 9) nines = nines+1;
		}	
		cout << "There were " << zeros << " 0’s." << endl;
		cout << "There were " << ones << " 1’s." << endl;
		cout << "There were " << twos << " 2’s." << endl;
		cout << "There were " << threes << " 3’s." << endl;
		cout << "There were " << fours << " 4’s." << endl;
		cout << "There were " << fives << " 5’s." << endl;
		cout << "There were " << sixes << " 6’s." << endl;
		cout << "There were " << sevens << " 7’s." << endl;
		cout << "There were " << eights << " 8’s." << endl;
		cout << "There were " << nines << " 9’s." << endl;
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
