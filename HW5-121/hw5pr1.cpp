//Leilani Horlander-Cruz
//CSCE 121-505
//Due: October 11, 2016
//hw5pr1.cpp

#include "std_lib_facilities_4.h"

bool is_vowel(char c) {
    //find if character is a vowel
	static const string vowels("aeiou");              
	return (vowels.find(tolower(c)) != string::npos);   //return boolean truth value
}

string pig_latin(const string& l) {
    //convert to pig latin
	string pig = l;
	if(is_vowel(l[0])) {                  //if first character is a vowel, will add "way" to end of word
		pig += string("way");
	}
	else {
		size_t p = 0;                 //size of object p
		while (!is_vowel(pig[++p]));  //will loop until finds which character is a vowel
		pig += (pig.substr(0,p) + string("ay"));  //once it is found, will add beginning consonants and "ay" to end of word
		pig.erase(0,p);     //remove consonants from beginning of word
	}
	return pig;      //return pig latin word
}

int main() {
	try {
		ifstream fin("in.txt");            //open file to read
		if (!fin) {
			cout << "Cannot open file" << endl;
			return 1;
		}
		ofstream fout("out.txt");           //create file to write
				
		string line;
		string word;
		stringstream ss;
		
		while(fin.good()) {
			getline(fin,line);          //get line
			if(line.size() > 0) {       //if there are characters in line
				ss.clear();        
				ss.str(line);       //add line to string stream
				while(ss.good()) {  
					ss >> word; //read individual words
					fout << pig_latin(word) << " ";  //convert to pig latin
				}
			}
			fout << endl;   //end line
		}
		return 0;	
	}
	catch (exception& e) {
		cerr << "error: " << e.what() << endl;
		return 1;
	}
	catch (...) {
		cerr << "Oops unknown error!" << endl;
		return 2;
	}
	return 0;
}
