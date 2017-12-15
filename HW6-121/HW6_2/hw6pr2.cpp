//Leilani Horlander-Cruz
//CSCE 121-505
//Due: October 25, 2016
//hw6pr2.cpp

#include "std_lib_facilities_4.h"
#include "Simple_window.h"
#include "Graph.h"

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

int main() {
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
		for (unsigned int i = 1; i <= 5000; ++i) {           //start with 1st number, and go 5000 times
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
		
		using namespace Graph_lib;
		if(H112 != 201401L)error("Error: incorrect std_lib_facilities_4.h version ",
		  	   H112);
		
		const int xmax = 700;  //window size
		const int ymax = 500;
		const int xoffset = 50;
		const int yoffset = 50;  
		const int xspace = 50;   //length beyond axes
		const int yspace = 50;
		const int xlength = xmax-xoffset-xspace;  //length of axes
		const int ylength = ymax-yoffset-yspace;
		
		const int end_amount = 600;
		const int base_amount = 0;
		
		const double xscale = double(xlength)/(end_amount-base_amount);
		const double yscale = double(ylength)/10;
		
		Simple_window win{Point{100,100},xmax,ymax,"hw6pr2"};
		
		Axis x(Axis::x,Point(xoffset,ymax-yoffset),xlength,10,"Occurances       60          120         180         240         300         360         420         480         540         600");
		x.label.move(-250,0);
		win.attach(x);
		Axis y(Axis::y,Point(xoffset,ymax-yoffset),ylength,10,"Final Digit");
		y.label.move(0,-15);
		win.attach(y);
		
		Rectangle zero{Point{50,ylength/10},zeros,10};
		zero.set_fill_color(Color::red);
		win.attach(zero);
		Text zero_label(Point(5,ylength/10+10),"zeros");
		zero_label.set_color(Color::red);
		win.attach(zero_label);
		
		Rectangle one{Point{50,2*ylength/10},ones,10};
		one.set_fill_color(Color::red);
		win.attach(one);
		Text one_label(Point(5,2*ylength/10+10),"ones");
		one_label.set_color(Color::red);
		win.attach(one_label);
		
		Rectangle two{Point{50,3*ylength/10},twos,10};
		two.set_fill_color(Color::red);
		win.attach(two);
		Text two_label(Point(5,3*ylength/10+10),"twos");
		two_label.set_color(Color::red);
		win.attach(two_label);
		
		Rectangle three{Point{50,4*ylength/10},threes,10};
		three.set_fill_color(Color::red);
		win.attach(three);
		Text three_label(Point(5,4*ylength/10+10),"threes");
		three_label.set_color(Color::red);
		win.attach(three_label);
		
		Rectangle four{Point{50,5*ylength/10},fours,10};
		four.set_fill_color(Color::red);
		win.attach(four);
		Text four_label(Point(5,5*ylength/10+10),"fours");
		four_label.set_color(Color::red);
		win.attach(four_label);
		
		Rectangle five{Point{50,6*ylength/10},fives,10};
		five.set_fill_color(Color::red);
		win.attach(five);
		Text five_label(Point(5,6*ylength/10+10),"fives");
		five_label.set_color(Color::red);
		win.attach(five_label);
		
		Rectangle six{Point{50,7*ylength/10},sixes,10};
		six.set_fill_color(Color::red);
		win.attach(six);
		Text six_label(Point(5,7*ylength/10+10),"sixes");
		six_label.set_color(Color::red);
		win.attach(six_label);
		
		Rectangle seven{Point{50,8*ylength/10},sevens,10};
		seven.set_fill_color(Color::red);
		win.attach(seven);
		Text seven_label(Point(5,8*ylength/10+10),"sevens");
		seven_label.set_color(Color::red);
		win.attach(seven_label);
		
		Rectangle eight{Point{50,9*ylength/10},eights,10};
		eight.set_fill_color(Color::red);
		win.attach(eight);
		Text eight_label(Point(5,9*ylength/10+10),"eights");
		eight_label.set_color(Color::red);
		win.attach(eight_label);
	
		Rectangle nine{Point{50,ylength},nines,10};
		nine.set_fill_color(Color::red);
		win.attach(nine);
		Text nine_label(Point(5,ylength+10),"nines");
		nine_label.set_color(Color::red);
		win.attach(nine_label);
		
		win.wait_for_button();
		return 0;
	}
	catch (exception& e) {
		cerr << "exception: " << e.what() << '\n';
		return 1;
	}
	catch (...) {
		cerr << "Some exception\n";
		return 2;
	}
}
