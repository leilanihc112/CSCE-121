#include "std_lib_facilities_4.h"
#include "Simple_window.h"
#include "Graph.h"
#include "GUI.h"

struct Lines_window : Graph_lib::Window {
	Lines_window(Point xy,int w,int h,const string& title );
	int i = 0;
	private:
		//data:
		Circle circle1{Point{300,200},150};
		
		//widgets:
		Button button_1;
		
		//actions invoked by callbacks:
		void change_color_pressed() 
		{
			i++;
			if (i > 1) i = 0;
			if (i % 2 != 1) {
				circle1.set_fill_color(Color::white);
				circle1.set_color(Color::invisible);
			}
			else {
				circle1.set_fill_color(Color::black);
				circle1.set_color(Color::invisible);
			}
			redraw();
		};

		//callback functions:
		static void cb_change_color(Address, Address);
};

Lines_window::Lines_window(Point xy,int w,int h,const string& title):
	Window(xy,w,h,title),
	button_1(Point(x_max()-70,0),70,20,"Switch",cb_change_color)
	{
		using namespace Graph_lib;
		attach(button_1);
		attach(circle1);
		circle1.set_fill_color(Color::white);
		circle1.set_color(Color::invisible);
	}

void Lines_window::cb_change_color(Address, Address pw)
{
	reference_to<Lines_window>(pw).change_color_pressed();
}
	
int main() {
	try {
		if(H112 != 201401L)error("Error: incorrect std_lib_facilities_4.h version", H112);
		using namespace Graph_lib;
		Lines_window win(Point(100,100),600,400,"Circle");
		return gui_main();
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
	return 0;
}
