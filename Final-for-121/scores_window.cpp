#include "scores_window.h"

//scores_window.cpp
//by Leilani Horlander-Cruz

scores_window::scores_window(Point xy, int w, int h, const string& title):Simple_window(xy,w,h,title),
begin_button(Point(x_max()-70,20),70,20,"Begin",cb_begin),  //will be in this position until get rid of other next button
enter_button(Point(x_max()-70,20),70,20,"Enter",cb_enter),  
initials(Point(150,50),100,20,"Initials:"),
difficulty(Point(450,50),100,20,"Difficulty(3-7):"),
instruct(Point(15,25),"Enter your initials and desired difficulty level then press the Enter button."),
instruct_2(Point(15,25),"Press begin to continue"),
player_1_s(Point(200,100),70,20,""),
player_1_i(Point(300,100),70,20,""),
player_2_s(Point(200,150),70,20,""),
player_2_i(Point(300,150),70,20,""),
player_3_s(Point(200,200),70,20,""),
player_3_i(Point(300,200),70,20,""),
player_4_s(Point(200,250),70,20,""),
player_4_i(Point(300,250),70,20,""),
player_5_s(Point(200,300),70,20,""),
player_5_i(Point(300,300),70,20,""),
player_initials(Point(215,335),70,20,"Player:"),
ttt(Point(235,85),"Top Scores"),
t(Point(200,335),"Would you like to play again?"),
yes_button(Point(225,350),30,20,"Yes",cb_yes),
no_button(Point(325,350),30,20,"No",cb_no)
{
	attach(enter_button);
	attach(initials);
	attach(difficulty);
	attach(instruct);
	attach(ttt);
	attach(player_1_i);
	attach(player_2_i);
	attach(player_3_i);
	attach(player_4_i);
	attach(player_5_i);
	attach(player_1_s);
	attach(player_2_s);
	attach(player_3_s);
	attach(player_4_s);
	attach(player_5_s);
	attach(player_initials);
	auto difficultylevel = difficulty.get_int();
	ifstream fin("scores_level" + to_string(difficultylevel) + ".txt");            //open file to read
				
		string line;
		string initials;
		int difficulty;
		string score;
		stringstream ss;
		vector<string> top_scores {"0", "N/A", "0", "N/A", "0", "N/A", "0", "N/A", "0", "N/A"}; //default
		int i = 0;
		
		while(getline(fin,line)) {
			if (i > top_scores.size()-2) { //error checking
				i = top_scores.size()-2;
			}
			ss.clear();        
			ss.str(line);       //add line to string stream
			ss >> score >> initials; //read scores and initials
			top_scores[i] = score;
			top_scores[i+1] = initials;
			i = i+2;
		}

			player_1_s.put(top_scores[0]);
			player_1_i.put(top_scores[1]);
			player_2_s.put(top_scores[2]);
			player_2_i.put(top_scores[3]);
			player_3_s.put(top_scores[4]);
			player_3_i.put(top_scores[5]);
			player_4_s.put(top_scores[6]);
			player_4_i.put(top_scores[7]);
			player_5_s.put(top_scores[8]);
			player_5_i.put(top_scores[9]);
			
		fin.close();
}