#include "std_lib_facilities_4.h"
#include "Simple_window.h"
#include "Graph.h"
#include "GUI.h"

//scores_window.h
//by Leilani Horlander-Cruz

struct scores_window : Simple_window{
	scores_window(Point xy, int w, int h, const string& title );
	private:
		Button begin_button;
		Button enter_button;
		In_box initials;   //box for player to enter initials
		In_box difficulty;   //box for player to enter difficulty
		Text instruct;     //instructions
		Text instruct_2;
		Out_box player_1_s;   
		Out_box player_1_i;  //score first then initials of player
		Out_box player_2_s;
		Out_box player_2_i;
		Out_box player_3_s;
		Out_box player_3_i;
		Out_box player_4_s;
		Out_box player_4_i;
		Out_box player_5_s;
		Out_box player_5_i;
		Out_box player_initials;   //current player initials
		Text ttt;  //Top Scores title
		Text t;       //ask if they want to play again
		Button yes_button; //answers to playing again
		Button no_button;
		
		static void cb_no(Address, Address);
		void no();
		static void cb_yes(Address, Address); 
		void yes();
		static void cb_begin(Address, Address);
		static void cb_enter(Address, Address);
		void enter();
		void begin();
};