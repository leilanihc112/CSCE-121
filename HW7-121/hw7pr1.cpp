//Leilani Horlander-Cruz
//CSCE 121-505
//Due: December 7, 2016
//hw7pr1.cpp

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

unsigned long compute_hash(string input_string)
{
	vector<unsigned long> test_vector(200);  //initial vector
	for(unsigned int i = 0; i < input_string.length(); i++) {
		test_vector[i] = (long)input_string[i];
	}
	vector<unsigned long> shifted_vector(200); //elements shift left by their indexes
	unsigned long hash_value = 0;
	for(unsigned int j = 0; j < input_string.length(); j++) {
		shifted_vector[j] = test_vector[j] << j;
		hash_value = hash_value ^ shifted_vector[j]; //exclusive or all three numbers
	}
	return hash_value;
}

int main () {
	try {
		cout << "Enter a line to calculate the hash function value: ";
		string line;
		while(getline(cin,line)) {
			unsigned long result = compute_hash(line); //compute hash value
			cout << result << '\n'; //print
			cout << "Enter a line to calculate the hash function value: ";
		}
		system ("pause");
		return 0;
	}
	catch (exception& e) {
		cerr << "error: " << e.what() << '\n';
		return 1;
	}
	catch (...) {
		cerr << "Oops unknown error!" << '\n';
		return 2;
	}
	return 0;
}