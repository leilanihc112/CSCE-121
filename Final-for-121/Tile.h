#include "Graph.h"
#include "Simple_window.h"
#include "std_lib_facilities_4.h"

//Tile.cpp
//by Michael Hall

class Tile
{
public:
	Tile(); 
	Tile(char c, int diff, int ord, Simple_window* win, list<Tile>* han, list<Tile*>* play);
	Tile(Tile& t);
	~Tile();
	char getCharacter() { return character; };
	int getDifficulty() { return difficulty; };
	int getOrder() { return order; };
	bool setCharacter(char c);
	bool setDifficulty(int i);
	bool setOrder(int i);
	void draw(int winHeight, int winWidth, Callback cb);
	void clone(Tile& t);
	void cb_clicked(Button* t);
	static void static_callback(Address w, Address data) { Tile* t = (Tile*)data; (*t).cb_clicked(&((*t).butt)); }
	Callback calla = static_callback;

	/*bool operator==(Tile& t) {
		if (t.character != character) { return false; }
		if (difficulty != t.difficulty) { return false; }
		if (order != t.order) { return false; }
		return true;
	}*/
	Simple_window* win;

private:
	char character;
	int difficulty;
	int originalOrder;
	int order;
	int width = 50;
	int height = 100;
	list<Tile>* hand;
	list<Tile*>* played;
	bool beenPlayed;
	Rectangle tile;
	Text tileChar;
	Button butt;
};