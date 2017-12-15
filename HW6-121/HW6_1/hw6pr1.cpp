//Leilani Horlander-Cruz
//CSCE 121-505
//Due: October 25, 2016
//hw6pr1.cpp

#include "std_lib_facilities_4.h"
#include "Simple_window.h"
#include "Graph.h"

int main() {
	try {
		using namespace Graph_lib;
		if(H112 != 201401L)error("Error: incorrect std_lib_facilities_4.h version ",
		  	   H112);
		Simple_window win{Point{50,50},900,900,"hw6pr1"};
		
		//Theoretically, would've used a for loop, but given time constraints, I couldn't get it to work in time. If I had more time I would've used one
		//Green is "light" color
		
		Rectangle s1_1{Point{50,50},100,100};
		s1_1.set_fill_color(Color::green);
		s1_1.set_color(Color::invisible);
		win.attach(s1_1);
		Rectangle s1_2{Point{150,50},100,100};
		s1_2.set_fill_color(Color::magenta);
		s1_2.set_color(Color::invisible);
		win.attach(s1_2);
		Rectangle s1_3{Point{250,50},100,100};
		s1_3.set_fill_color(Color::green);
		s1_3.set_color(Color::invisible);
		win.attach(s1_3);
		Rectangle s1_4{Point{350,50},100,100};
		s1_4.set_fill_color(Color::magenta);
		s1_4.set_color(Color::invisible);
		win.attach(s1_4);
		Rectangle s1_5{Point{450,50},100,100};
		s1_5.set_fill_color(Color::green);
		s1_5.set_color(Color::invisible);
		win.attach(s1_5);
		Rectangle s1_6{Point{550,50},100,100};
		s1_6.set_fill_color(Color::magenta);
		s1_6.set_color(Color::invisible);
		win.attach(s1_6);
		Rectangle s1_7{Point{650,50},100,100};
		s1_7.set_fill_color(Color::green);
		s1_7.set_color(Color::invisible);
		win.attach(s1_7);
		Rectangle s1_8{Point{750,50},100,100};
		s1_8.set_fill_color(Color::magenta);
		s1_8.set_color(Color::invisible);
		win.attach(s1_8);
		
		Rectangle s2_1{Point{50,150},100,100};
		s2_1.set_fill_color(Color::magenta);
		s2_1.set_color(Color::invisible);
		win.attach(s2_1);
		Rectangle s2_2{Point{150,150},100,100};
		s2_2.set_fill_color(Color::green);
		s2_2.set_color(Color::invisible);
		win.attach(s2_2);
		Rectangle s2_3{Point{250,150},100,100};
		s2_3.set_fill_color(Color::magenta);
		s2_3.set_color(Color::invisible);
		win.attach(s2_3);
		Rectangle s2_4{Point{350,150},100,100};
		s2_4.set_fill_color(Color::green);
		s2_4.set_color(Color::invisible);
		win.attach(s2_4);
		Rectangle s2_5{Point{450,150},100,100};
		s2_5.set_fill_color(Color::magenta);
		s2_5.set_color(Color::invisible);
		win.attach(s2_5);
		Rectangle s2_6{Point{550,150},100,100};
		s2_6.set_fill_color(Color::green);
		s2_6.set_color(Color::invisible);
		win.attach(s2_6);
		Rectangle s2_7{Point{650,150},100,100};
		s2_7.set_fill_color(Color::magenta);
		s2_7.set_color(Color::invisible);
		win.attach(s2_7);
		Rectangle s2_8{Point{750,150},100,100};
		s2_8.set_fill_color(Color::green);
		s2_8.set_color(Color::invisible);
		win.attach(s2_8);
				
		Rectangle s3_1{Point{50,250},100,100};
		s3_1.set_fill_color(Color::green);
		s3_1.set_color(Color::invisible);
		win.attach(s3_1);
		Rectangle s3_2{Point{150,250},100,100};
		s3_2.set_fill_color(Color::magenta);
		s3_2.set_color(Color::invisible);
		win.attach(s3_2);
		Rectangle s3_3{Point{250,250},100,100};
		s3_3.set_fill_color(Color::green);
		s3_3.set_color(Color::invisible);
		win.attach(s3_3);
		Rectangle s3_4{Point{350,250},100,100};
		s3_4.set_fill_color(Color::magenta);
		s3_4.set_color(Color::invisible);
		win.attach(s3_4);
		Rectangle s3_5{Point{450,250},100,100};
		s3_5.set_fill_color(Color::green);
		s3_5.set_color(Color::invisible);
		win.attach(s3_5);
		Rectangle s3_6{Point{550,250},100,100};
		s3_6.set_fill_color(Color::magenta);
		s3_6.set_color(Color::invisible);
		win.attach(s3_6);
		Rectangle s3_7{Point{650,250},100,100};
		s3_7.set_fill_color(Color::green);
		s3_7.set_color(Color::invisible);
		win.attach(s3_7);
		Rectangle s3_8{Point{750,250},100,100};
		s3_8.set_fill_color(Color::magenta);
		s3_8.set_color(Color::invisible);
		win.attach(s3_8);
		
		Rectangle s4_1{Point{50,350},100,100};
		s4_1.set_fill_color(Color::magenta);
		s4_1.set_color(Color::invisible);
		win.attach(s4_1);
		Rectangle s4_2{Point{150,350},100,100};
		s4_2.set_fill_color(Color::green);
		s4_2.set_color(Color::invisible);
		win.attach(s4_2);
		Rectangle s4_3{Point{250,350},100,100};
		s4_3.set_fill_color(Color::magenta);
		s4_3.set_color(Color::invisible);
		win.attach(s4_3);
		Rectangle s4_4{Point{350,350},100,100};
		s4_4.set_fill_color(Color::green);
		s4_4.set_color(Color::invisible);
		win.attach(s4_4);
		Rectangle s4_5{Point{450,350},100,100};
		s4_5.set_fill_color(Color::magenta);
		s4_5.set_color(Color::invisible);
		win.attach(s4_5);
		Rectangle s4_6{Point{550,350},100,100};
		s4_6.set_fill_color(Color::green);
		s4_6.set_color(Color::invisible);
		win.attach(s4_6);
		Rectangle s4_7{Point{650,350},100,100};
		s4_7.set_fill_color(Color::magenta);
		s4_7.set_color(Color::invisible);
		win.attach(s4_7);
		Rectangle s4_8{Point{750,350},100,100};
		s4_8.set_fill_color(Color::green);
		s4_8.set_color(Color::invisible);
		win.attach(s4_8);
			
		Rectangle s5_1{Point{50,450},100,100};
		s5_1.set_fill_color(Color::green);
		s5_1.set_color(Color::invisible);
		win.attach(s5_1);
		Rectangle s5_2{Point{150,450},100,100};
		s5_2.set_fill_color(Color::magenta);
		s5_2.set_color(Color::invisible);
		win.attach(s5_2);
		Rectangle s5_3{Point{250,450},100,100};
		s5_3.set_fill_color(Color::green);
		s5_3.set_color(Color::invisible);
		win.attach(s5_3);
		Rectangle s5_4{Point{350,450},100,100};
		s5_4.set_fill_color(Color::magenta);
		s5_4.set_color(Color::invisible);
		win.attach(s5_4);
		Rectangle s5_5{Point{450,450},100,100};
		s5_5.set_fill_color(Color::green);
		s5_5.set_color(Color::invisible);
		win.attach(s5_5);
		Rectangle s5_6{Point{550,450},100,100};
		s5_6.set_fill_color(Color::magenta);
		s5_6.set_color(Color::invisible);
		win.attach(s5_6);
		Rectangle s5_7{Point{650,450},100,100};
		s5_7.set_fill_color(Color::green);
		s5_7.set_color(Color::invisible);
		win.attach(s5_7);
		Rectangle s5_8{Point{750,450},100,100};
		s5_8.set_fill_color(Color::magenta);
		s5_8.set_color(Color::invisible);
		win.attach(s5_8);
		
		Rectangle s6_1{Point{50,550},100,100};
		s6_1.set_fill_color(Color::magenta);
		s6_1.set_color(Color::invisible);
		win.attach(s6_1);
		Rectangle s6_2{Point{150,550},100,100};
		s6_2.set_fill_color(Color::green);
		s6_2.set_color(Color::invisible);
		win.attach(s6_2);
		Rectangle s6_3{Point{250,550},100,100};
		s6_3.set_fill_color(Color::magenta);
		s6_3.set_color(Color::invisible);
		win.attach(s6_3);
		Rectangle s6_4{Point{350,550},100,100};
		s6_4.set_fill_color(Color::green);
		s6_4.set_color(Color::invisible);
		win.attach(s6_4);
		Rectangle s6_5{Point{450,550},100,100};
		s6_5.set_fill_color(Color::magenta);
		s6_5.set_color(Color::invisible);
		win.attach(s6_5);
		Rectangle s6_6{Point{550,550},100,100};
		s6_6.set_fill_color(Color::green);
		s6_6.set_color(Color::invisible);
		win.attach(s6_6);
		Rectangle s6_7{Point{650,550},100,100};
		s6_7.set_fill_color(Color::magenta);
		s6_7.set_color(Color::invisible);
		win.attach(s6_7);
		Rectangle s6_8{Point{750,550},100,100};
		s6_8.set_fill_color(Color::green);
		s6_8.set_color(Color::invisible);
		win.attach(s6_8);
			
		Rectangle s7_1{Point{50,650},100,100};
		s7_1.set_fill_color(Color::green);
		s7_1.set_color(Color::invisible);
		win.attach(s7_1);
		Rectangle s7_2{Point{150,650},100,100};
		s7_2.set_fill_color(Color::magenta);
		s7_2.set_color(Color::invisible);
		win.attach(s7_2);
		Rectangle s7_3{Point{250,650},100,100};
		s7_3.set_fill_color(Color::green);
		s7_3.set_color(Color::invisible);
		win.attach(s7_3);
		Rectangle s7_4{Point{350,650},100,100};
		s7_4.set_fill_color(Color::magenta);
		s7_4.set_color(Color::invisible);
		win.attach(s7_4);
		Rectangle s7_5{Point{450,650},100,100};
		s7_5.set_fill_color(Color::green);
		s7_5.set_color(Color::invisible);
		win.attach(s7_5);
		Rectangle s7_6{Point{550,650},100,100};
		s7_6.set_fill_color(Color::magenta);
		s7_6.set_color(Color::invisible);
		win.attach(s7_6);
		Rectangle s7_7{Point{650,650},100,100};
		s7_7.set_fill_color(Color::green);
		s7_7.set_color(Color::invisible);
		win.attach(s7_7);
		Rectangle s7_8{Point{750,650},100,100};
		s7_8.set_fill_color(Color::magenta);
		s7_8.set_color(Color::invisible);
		win.attach(s7_8);
		
		Rectangle s8_1{Point{50,750},100,100};
		s8_1.set_fill_color(Color::magenta);
		s8_1.set_color(Color::invisible);
		win.attach(s8_1);
		Rectangle s8_2{Point{150,750},100,100};
		s8_2.set_fill_color(Color::green);
		s8_2.set_color(Color::invisible);
		win.attach(s8_2);
		Rectangle s8_3{Point{250,750},100,100};
		s8_3.set_fill_color(Color::magenta);
		s8_3.set_color(Color::invisible);
		win.attach(s8_3);
		Rectangle s8_4{Point{350,750},100,100};
		s8_4.set_fill_color(Color::green);
		s8_4.set_color(Color::invisible);
		win.attach(s8_4);
		Rectangle s8_5{Point{450,750},100,100};
		s8_5.set_fill_color(Color::magenta);
		s8_5.set_color(Color::invisible);
		win.attach(s8_5);
		Rectangle s8_6{Point{550,750},100,100};
		s8_6.set_fill_color(Color::green);
		s8_6.set_color(Color::invisible);
		win.attach(s8_6);
		Rectangle s8_7{Point{650,750},100,100};
		s8_7.set_fill_color(Color::magenta);
		s8_7.set_color(Color::invisible);
		win.attach(s8_7);
		Rectangle s8_8{Point{750,750},100,100};
		s8_8.set_fill_color(Color::green);
		s8_8.set_color(Color::invisible);
		win.attach(s8_8);
		
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
