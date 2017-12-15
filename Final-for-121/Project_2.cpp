#include "std_lib_facilities_4.h"
#include "Simple_window.h"
#include "Graph.h"
#include "GUI.h"
#include "Tile.h"
#include <FL/fl_ask.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_JPEG_Image.H>
#include "scores_window.h"
//#include "gameHandler.cpp"

//Project_2.cpp
//main program

double current_score = 0;

//calculator code
struct Token {
	char kind;
	double value;
	string name;
	Token(char ch) :kind(ch), value(0) { }
	Token(char ch, double val) :kind(ch), value(val) { }
	Token(char ch, string val) :kind(ch), name(val) { }
};

class Token_stream {
	
	Token buffer;
public:
	Token_stream() :full(0), buffer(0) {
	}
	Token get();
	void unget(Token t) {
		buffer = t; full = true;
	}
	void ignore(char);
	bool full;
};

//actually define get() function in Token class
Token Token_stream::get()
{
	if (full) { full = false; return buffer; }
	char ch;
	cin >> ch; //This is where you input
	switch (ch) {
	case '(':case ')':case '+':case '-':case '*':case '/':case '%':case ';':case ',':
	case '=':
		return Token(ch);
	case '.':case '0':case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':
	case '9': {
		cin.unget();
		double val;
		cin >> val;
		return Token('k', val);
	}
	case 'k': {
		cin.unget();
		char val;
		cin >> val;
		return Token('k', 1000);
	}
	default: {
		//if (isalpha(ch)) {
		//	string s;
		//	s += ch;
		//	//Error on 78 but not sure whats up. Why are we checking for both digits and chars? Is the + operator already overloaded in std_lib_facilities?
		//	while (cin.get(ch) && (isalpha(ch) || isdigit(ch)))
		//		s += ch;
		//	cin.unget();
		//	if (s == "let") return Token(let);
		//	// name is not quit.... 	
		//	if (s == "quit") return Token(quit);
		//	if (s == "sqrt") return Token(root);
		//	if (s == "help") return Token(help);
		//	if (s == "pow")  return Token(pows);
		//	return Token(name, s);
		//}
		error("Bad token");
	}
	}
}

void Token_stream::ignore(char c) {
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch;
	while (cin >> ch)
		if (ch == c) return;
}

struct Variable {
	string name;
	double value;
	Variable(string n, double v) :name(n), value(v) { }
};

vector<Variable> names;

double get_value(string s) {
	for (int i = 0; i<names.size(); ++i)
		if (names[i].name == s) return names[i].value;
	error("get: undefined name ", s);
}

void set_value(string s, double d) {
	for (int i = 0; i<names.size(); ++i)
		if (names[i].name == s) {
			names[i].value = d;
			return;
		}
	error("set: undefined name ", s);
}

bool is_declared(string s) {
	for (int i = 0; i<names.size(); ++i)
		if (names[i].name == s) return true;
	return false;
}

Token_stream ts;

double expression();
int factorial(double number);

double primary() {
	Token t = ts.get();
	switch (t.kind) {
	case '(': {
		double d = expression();
		t = ts.get();
		if (t.kind != ')') return 0;;
		return d;
	}
	case '-':
		return -primary();
	case '+':
		return primary();
		// for sqrt
	/*case root: {
		double d = expression();
		if (d<0)error("cant be negative");
		else {
			double final = sqrt(d);
			return final;
		}
	}
	case pows: {
		t = ts.get();
		if (t.kind != '(') error("'(' expected");
		double d = expression();
		t = ts.get();
		if (t.kind != ',') error("',' expected");
		double i = expression();
		t = ts.get();
		if (t.kind != ')') error("')' expected");
		return pow(d, i);
	}
	case help: {
		cout << "\nYou are allowed to use +,-,*,/,sqrt(), and pow()\n\n";
		cout << "Once you are done entering an expression, enter a ';' to execute the expression.\n";
		cout << "pow() is used in the following syntax: pow(<number to be raised>,<number to raise it to>)\n\n";
	}*/
			   // number = '8'
	case 'k':
		return t.value;
		// name = 'a'
	/*case name:
		return get_value(t.name);*/
	case '=':
		return primary();
	default:
		return 0;
	}
}

double term() {
	double left = primary();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '*':
			left *= primary();
			break;
		case '/':
		{	double d = primary();
		if (d == 0) return 0;
		left /= d;
		break;
		}
		default:
			ts.unget(t);
			return left;
		}
	}
}

double expression() {
	double left = term();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}

double declaration() {
	Token t = ts.get();
	if (t.kind != 'a') error("name expected in declaration");
	string name = t.name;
	if (is_declared(name)) error(name, " declared twice");
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", name);
	double d = expression();
	names.push_back(Variable(name, d));
	return d;
}

double statement() {
	/*Token t = ts.get();
	switch (t.kind) {
	case let:
		return declaration();
	default:
		ts.unget(t);
		return expression();
	}*/
}

void clean_up_mess() {
	//ts.ignore(print);
}

//const string prompt = "> ";
//const string result = "= ";

double calculate() {
	while (true) try {
		//cout << prompt;
		Token t = ts.get();


		cout << t.kind;
		char print = ';';
		if (t.kind == print) return expression();
		// quit = 'Q'
		/*if (t.kind == quit) return 0;*/
		ts.unget(t);
		//cout << result << statement() << endl;
	}
	catch (runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
		return 0;
	}
}

double find_value(string s) {
	cin.putback(';');
	for (int i = s.length() - 1; i >= 0; i--) {
		cin.putback(s.at(i));
	}
	ts.full = false;
	return expression();
}
//end calculator code

int game();

//Begin code written by Patrick
void start_cb(Fl_Widget* o, void* b)
{
	((Fl_Widget*)o)->hide();
	Simple_window *a = (Simple_window*)b;
	a->hide();
	game();
}
//instruction screen
void instructions()
{
	int winHeight = 800;
	int winWidth = 1000;
	Simple_window *win1 = new Simple_window(Point(100, 200), winWidth, winHeight, "Instructions");
	win1->begin();
	//begin attachments
	//instructions box
	Fl_Box *box = new Fl_Box(FL_UP_BOX, 100, 0, 800, 600, "Instructions: \nThe object of the game is to rearrange a certain number of tiles (each \n labelled with a digit or an operator) to yield the highest arithmetic value.  \n For example, the three tiles \n could be rearranged to 3+5 = 8, 5+3 = 8, +35 = 35, or +53 = 53.\n   Since +53 has the highest value, that is the best move.\n  If 35+ or 53+ is chosen, the score is zero \n since that is not a “well-formed formula” in arithmetic \n(in other words, it is an illegal move)\n\nTo select a tile, click on it. To unselect, click it while it is on the formula line.");
	//Finish before time runs out. If you fail to do so, your score will be 0.
	box->labelsize(24);//FONT
					   //Start button
	Fl_Button* but = new Fl_Button(450, 600, 100, 100, "Begin");
	but->callback(start_cb, win1);
	win1->end();
	win1->show();
}

//remove splash screen
void deleteSplash(void* m)
{
	Simple_window *f = (Simple_window*)m;
	f->hide();
	delete f;
	instructions();
}
//splash screen 
void splash() {
	Fl_Window *win1 = new Fl_Window(200, 100, 524, 592);
	win1->begin();
	win1->border(0);
	Fl_JPEG_Image *image1 = new Fl_JPEG_Image("d.jpg");
	Fl_Box *box = new Fl_Box(0, 0, 524, 592);
	win1->image(image1);
	box->image(image1);
	win1->redraw();
	win1->end();
	win1->show();
	Fl::add_timeout(5.0, deleteSplash, win1);
}
//end code written by patrick

//begin code written by Michael Hall
void generate_tiles(int diff, vector<char>& tiles)
{
	//creates a random number generator that actually works
	random_device rd;
	mt19937 eng(rd());
	uniform_int_distribution<> distr(0, 99);

	int left = diff;
	//some chance to generate a set of parenthesis
	if (distr(eng) > 25 && diff >= 5) {
		tiles.push_back('(');
		tiles.push_back(')');
		left -= 2;
	}
	//generate random number of operators such that there will be more digits than operators
	int ops = left / 2;
	if (left - ops <= ops) {
		--ops;
	}
	uniform_int_distribution<> opsdist(1, ops);
	ops = opsdist(eng);
	left -= ops;
	//generate operators
	for (int i = 0; i < ops; i++) {
		switch (distr(eng) / 25) {
		case 0: tiles.push_back('+'); break;
		case 1: tiles.push_back('-'); break;
		case 2: tiles.push_back('*'); break;
		case 3: tiles.push_back('/'); break;
		}
	}
	for (int j = 0; j < left; j++) {
		int num = distr(eng) / 10;
		char c = '0' + num;
		tiles.push_back(c);
	}
	//check to make sure proper number of tiles generated
	if (tiles.size() != diff) {
		//empty vector and try again
		tiles.clear();
		generate_tiles(diff, tiles);
	}
}

static void cb_finish(Address t, Address data) {
	//cout << "calla\n";
	list<Tile*>* played = (list<Tile*>*)data;
	//cout << ((*(*((*played).begin()))).getDifficulty());
	if ((*played).size() > 0 && ((*played).size() == ((*(*((*played).begin()))).getDifficulty()))) {
		//cout << "DONE\n";
		string s = "";
		for (Tile* & t : (*played)) {
			s += (*t).getCharacter();
		}
		//cout << s << '\n';
		//do something here to pass data to calculator and end round
		//cout << find_value(s) << '\n';
		current_score = find_value(s);
		(*(*(*(*played).begin())).win).next();
	}
	else {
		 fl_alert("must play all tiles\n");
	}
}

void draw_hand(const vector<char>& tiles, int diff, Simple_window& win, int height, int width, list<Tile>& hand, list<Tile*>& played) {
	Tile t;
	for (int i = 0; i < tiles.size(); i++) {
		Tile t1(tiles[i], diff, i, &win, &hand, &played);
		t.clone(t1);
		hand.emplace_back(t);
	}
	for (Tile & t : hand) {
		t.draw(height, width, t.calla);
	}
}

//void delete_game_window(void* m) 
//{
//	Simple_window *f = (Simple_window*)m;
//	f->hide();
//	delete f;
//	int current_score = 0;
//}

void begin_game(Simple_window* win, int diff) {
	int time = 2*diff^2; //time to finish game
	int winHeight = 400;
	int winWidth = 600;
	Simple_window *win1 = new Simple_window(Point(100, 200), winWidth, winHeight, "Tile Game");

	vector<char> tiles;
	list<Tile> hand;
	list<Tile*> played;

	generate_tiles(diff, tiles);
	draw_hand(tiles, diff, *win1, winHeight, winWidth, hand, played);

	Button x(Point((winWidth / 2) - 50, (winHeight / 2) - 10), 100, 20, "Finish Round", cb_finish, &played);
	win1 -> attach(x);
	
	//Fl::add_timeout(time, delete_game_window, win1); //timer
	
	win1 -> wait_for_button();
}

//end code written by Michael Hall

//begin code written by Leilani Horlander-Cruz
//functions may exceed 24 lines because of the amount of widgets and calculations/sorting/overwriting done
void scores_window::cb_enter(Address, Address pw)
{
	reference_to<scores_window>(pw).enter();
}
	
void scores_window::enter()
{	
	auto difficultylevel = difficulty.get_int();
	string player = initials.get_string();  //variable to keep string of initials of current player
	if((difficultylevel) > 7 || difficultylevel < 3)
		fl_alert("Please enter a difficulty level from 3-7"); //verify difficulty level
	else if (player.empty()) {
		fl_alert("Please enter your initials"); //verify initials
	}
	else {
		player_initials.put(player);
	
	ofstream fout("current_player.txt");
		
		fout << player; //save initials of current player to file
	
	fout.close();

	//display scores for chosen difficulty
	ifstream fin_1("scores_level" + to_string(difficultylevel) + ".txt");            //open file to read

	string line_1;
	string initials_1;
	string score_1;
	stringstream ss_1;
	vector<string> top_scores_1 {"0", "N/A", "0", "N/A", "0", "N/A", "0", "N/A", "0", "N/A"};
	int i_1 = 0;

	while (getline(fin_1, line_1)) {
		if (i_1 > top_scores_1.size() - 2) {
			i_1 = top_scores_1.size() - 2;
		}
		ss_1.clear();
		ss_1.str(line_1);       //add line to string stream
		ss_1 >> score_1 >> initials_1; //read scores and initials
		top_scores_1[i_1] = score_1;
		top_scores_1[i_1 + 1] = initials_1;
		i_1 = i_1 + 2;
	}

	player_1_s.put(top_scores_1[0]);
	player_1_i.put(top_scores_1[1]);
	player_2_s.put(top_scores_1[2]);
	player_2_i.put(top_scores_1[3]);
	player_3_s.put(top_scores_1[4]);
	player_3_i.put(top_scores_1[5]);
	player_4_s.put(top_scores_1[6]);
	player_4_i.put(top_scores_1[7]);
	player_5_s.put(top_scores_1[8]);
	player_5_i.put(top_scores_1[9]);
	
	detach(enter_button);
	detach(instruct);
	attach(instruct_2);
	attach(begin_button);

	}
}

void scores_window::cb_begin(Address, Address pw)
{
	reference_to<scores_window>(pw).begin();
}

void scores_window::begin()
{
	auto difficultylevel = difficulty.get_int();
	hide();
	//runs the game before displaying final scores
	begin_game(this, difficultylevel);

	detach(begin_button);
	detach(instruct_2);
	detach(initials);
	detach(player_initials);
	detach(difficulty);
	attach(t);
	attach(yes_button);
	attach(no_button);
	
	double player_score = current_score; 
	
	ifstream f_in("current_player.txt");
		
		string lines;
		string player_initial; 
		stringstream ss_s;
		
		while(getline(f_in,lines)) {
			ss_s.clear();        
			ss_s.str(lines);       //add line to string stream
			ss_s >> player_initial; //read initials
		}
	
	ifstream fin("scores_level" + to_string(difficultylevel) + ".txt");
				
		string line;
		string initials;
		string score;
		stringstream ss;
		vector<string> top_scores {"0", "N/A", "0", "N/A", "0", "N/A", "0", "N/A", "0", "N/A"};
		int i = 0;
		
		while(getline(fin,line)) {
			if (i > top_scores.size()-2) {
				i = top_scores.size()-2;
			}
			ss.clear();        
			ss.str(line);       //add line to string stream
			ss >> score >> initials; //read scores and initials
			top_scores[i] = score;
			top_scores[i+1] = initials;
			i = i+2;
		}
		
		//sorting out high scores and overwriting old data
		string::size_type sz;
		if (player_score >= stod (top_scores[0],&sz)) {//stod string to double for inequality comparison
			ofstream fout("scores_level" + to_string(difficultylevel) + ".txt"); //print player's most recent score and initials in order to file
			fout << player_score << '\t' << player_initial << endl
				<< top_scores[0] << '\t' << top_scores[1] << endl
				<< top_scores[2] << '\t' << top_scores[3] << endl
				<< top_scores[4] << '\t' << top_scores[5] << endl
				<< top_scores[6] << '\t' << top_scores[7] << endl;
			fout.close(); 
		}
		else if (player_score >= stod (top_scores[2],&sz) && player_score <= stod (top_scores[0],&sz)) {
			ofstream fout("scores_level" + to_string(difficultylevel) + ".txt"); //print player's most recent score and initials in order to file
			fout << top_scores[0] << '\t' << top_scores[1] << endl
				<< player_score << '\t' << player_initial << endl
				<< top_scores[2] << '\t' << top_scores[3] << endl
				<< top_scores[4] << '\t' << top_scores[5] << endl
				<< top_scores[6] << '\t' << top_scores[7] << endl;
			fout.close(); 
		}
		else if (player_score >= stod (top_scores[4],&sz) && player_score <= stod (top_scores[2],&sz)) {
			ofstream fout("scores_level" + to_string(difficultylevel) + ".txt"); //print player's most recent score and initials in order to file
			fout << top_scores[0] << '\t' << top_scores[1] << endl
				<< top_scores[2] << '\t' << top_scores[3] << endl
				<< player_score << '\t' << player_initial << endl
				<< top_scores[4] << '\t' << top_scores[5] << endl
				<< top_scores[6] << '\t' << top_scores[7] << endl;
			fout.close(); 
		}
		else if (player_score >= stod (top_scores[6],&sz) && player_score <= stod (top_scores[4],&sz)) {
			ofstream fout("scores_level" + to_string(difficultylevel) + ".txt"); //print player's most recent score and initials in order to file
			fout << top_scores[0] << '\t' << top_scores[1] << endl
				<< top_scores[2] << '\t' << top_scores[3] << endl
				<< top_scores[4] << '\t' << top_scores[5] << endl
				<< player_score << '\t' << player_initial << endl
				<< top_scores[6] << '\t' << top_scores[7] << endl;
			fout.close(); 
		}
		else if (player_score >= stod (top_scores[8],&sz) && player_score <= stod (top_scores[6],&sz)) {
			ofstream fout("scores_level" + to_string(difficultylevel) + ".txt"); //print player's most recent score and initials in order to file
			fout << top_scores[0] << '\t' << top_scores[1] << endl
				<< top_scores[2] << '\t' << top_scores[3] << endl
				<< top_scores[4] << '\t' << top_scores[5] << endl
				<< top_scores[6] << '\t' << top_scores[7] << endl
				<< player_score << '\t' << player_initial << endl;
			fout.close(); 
		}
		
		//displaying new data
		ifstream fin_1("scores_level" + to_string(difficultylevel) + ".txt");            //open file to read
				
		string line_1;
		string initials_1;
		string score_1;
		stringstream ss_1;
		vector<string> top_scores_1 {"0", "N/A", "0", "N/A", "0", "N/A", "0", "N/A", "0", "N/A"};
		int i_1 = 0;
		
		while(getline(fin_1,line_1)) {
			if (i_1 > top_scores_1.size()-2) {
				i_1 = top_scores_1.size()-2;
			}
			ss_1.clear();        
			ss_1.str(line_1);       //add line to string stream
			ss_1 >> score_1 >> initials_1; //read scores and initials
			top_scores_1[i_1] = score_1;
			top_scores_1[i_1+1] = initials_1;
			i_1 = i_1+2;
		}
		
			player_1_s.put(top_scores_1[0]);
			player_1_i.put(top_scores_1[1]);
			player_2_s.put(top_scores_1[2]);
			player_2_i.put(top_scores_1[3]);
			player_3_s.put(top_scores_1[4]);
			player_3_i.put(top_scores_1[5]);
			player_4_s.put(top_scores_1[6]);
			player_4_i.put(top_scores_1[7]);
			player_5_s.put(top_scores_1[8]);
			player_5_i.put(top_scores_1[9]);
			
		fin.close();
		show();
}

void scores_window::cb_no(Address, Address pw)
{
	reference_to<scores_window>(pw).no();
}
	
void scores_window::no()
{
	hide(); //exit screen if don't want to play another game
}

void scores_window::cb_yes(Address, Address pw)
{
	reference_to<scores_window>(pw).yes();
}

int game() {
	try {
		using namespace Graph_lib;
		if(H112 != 201401L)error("Error: incorrect std_lib_facilities_4.h version ",
		  	   H112);
		scores_window win{Point{100,100},600,400,"scores"};
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
}

void scores_window::yes()
{
	hide();
	game();
}
//end code written by Leilani Horlander-Cruz

int main()
{
	splash();
	return Fl::run();
}