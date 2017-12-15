//Leilani Horlander-Cruz
//CSCE 121-505
//Due: October 25, 2016
//hw6pr3.cpp

#include "std_lib_facilities_4.h"
#include "Simple_window.h"
#include "Graph.h"

class Scandinavian_flag {
public:
		void attach_to(Simple_window& w) {
			w.attach(background);
			w.attach(vert_cross);
			w.attach(horiz_cross);
		}
		Scandinavian_flag(Color color1, Color color2) {
			background.set_fill_color(color2);
			background.set_color(color2);
			vert_cross.set_fill_color(color1);
			vert_cross.set_color(color1);
			horiz_cross.set_fill_color(color1);
			horiz_cross.set_color(color1);
		}
		
private:
	Rectangle background{Point{50,50},300,200};
	Rectangle vert_cross{Point{140,50},35,200};
	Rectangle horiz_cross{Point{50,135},300,35};
};

int main() {
	try {
		if(H112 != 201401L)error("Error: incorrect std_lib_facilities_4.h version ",
		  	   H112);
		Simple_window win{Point{50,50},500,600,"hw6pr3"};
		Scandinavian_flag Denmark{Color::white, Color::red};
		Denmark.attach_to(win);
		Text flag_name{Point{170,275},"Denmark"};
		win.attach(flag_name);
		win.wait_for_button();
		Scandinavian_flag Finland{Color::blue, Color::white};
		Finland.attach_to(win);
		flag_name.set_label("Finland");
		win.attach(flag_name);
		win.wait_for_button();
		Scandinavian_flag Sweden{Color::yellow, Color::blue};
		Sweden.attach_to(win);
		flag_name.set_label("Sweden");
		win.attach(flag_name);
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
