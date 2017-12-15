#include "Tile.h"

//Tile.cpp
//by Michael Hall

void null_cb()
{

}

void Tile::cb_clicked(Button* t)
{
	if (!beenPlayed) {
		//cout << "notPlayed\n";
		int n = (*played).size() + difficulty;
		setOrder(n);
		//(*hand).remove(*this);
		(*played).push_back(this);
		beenPlayed = true;
	}
	else {
		//cout << "played\n";
		/*int n = 0;
		bool found = false;
		for (int i = 0; i < (*hand).size(); i++) {
			for (int j = 0; j < (*hand).size(); j++) {
				found = true;
				list<Tile*>::iterator it = (*played).begin();
				advance(it, j);
				Tile& x = **it;
				if (x.getOrder() == i) {
					break;
				}
				found = false;
			}
			if (!found) {
				n = i;
				break;
			}
		}*/
		//cout << originalOrder << '\n';
		setOrder(originalOrder);
		(*played).remove(this);
		for (int i = 0; i < (*played).size(); i++) {
			list<Tile*>::iterator it = (*played).begin();
			advance(it, i);
			Tile& x = **it;
			x.setOrder(i+difficulty);
			(*win).detach(x.butt);
			x.draw((*win).y_max(), (*win).x_max(), x.calla);
			x.butt.move(0, 0);
		}
		//(*hand).push_back(*this);
		beenPlayed = false;
	}
	//setOrder(order+1);
	(*win).detach(butt);
	draw((*win).y_max(), (*win).x_max(), calla);
	butt.move(0, 0);
}

//default constructor makes a zero tile with lowest difficutly. Really should never be used.
Tile::Tile() :
	character('0'),
	difficulty(3),
	originalOrder(0),
	order(0),
	hand(nullptr),
	played(nullptr),
	beenPlayed(false),
	tile(Point(0, 0), 1, 1),
	tileChar(Point(0, 0), " "),
	butt(Point(0, 0), 1, 1, " ", Callback(null_cb),this),
	win(nullptr)
{
}

//create a tile with specified attributes
Tile::Tile(char c, int diff, int ord, Simple_window* win1, list<Tile>* han, list<Tile*>* play) :
	character(c),
	difficulty(diff),
	originalOrder(ord),
	order(ord),
	hand(han),
	played(play),
	beenPlayed(false),
	tile(Point(0,0),1,1),
	tileChar(Point(0,0), " "),
	butt(Point(0, 0), 1, 1, " ", Callback(null_cb),this),
	win(win1)
{
	//If any of these happen, there was a problem and you may need to fix something.
	if (!Tile::setCharacter(c)) {
		Tile::setCharacter('0');
	}
	if (!Tile::setDifficulty(diff)) {
		Tile::setDifficulty(3);
	}
	if (!Tile::setOrder(ord)) {
		Tile::setOrder(0);
	}
}

Tile::~Tile()
{
}

//checks character validity before setting. Returns true if assignment is successful, false if otherwise
bool Tile::setCharacter(char c)
{
	//includes factorial, in case we add that later
	switch (c) {
	case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': case '+': case '-': case '*': case '/': case '(': case ')': case '!':
		character = c; return true;
	default: return false;
	}
}

//checks difficulty validity before setting. Returns true if assignment is successful, false if otherwise
bool Tile::setDifficulty(int i)
{
	if (i >= 3 && i <= 7) {
		difficulty = i;
		return true;
	}
	return false;
}

//checks order validity before setting. Returns true if assignment is successful, false if otherwise
bool Tile::setOrder(int i)
{
	if (i >= 0 && i < difficulty * 2) {
		order = i;
		return true;
	}
	return false;
}


//attaches the tile to the supplied window, using the height and width to set its position
void Tile::draw(int winHeight, int winWidth, Callback cb)
{
	//cout << order << '\n';
	//calculates x and y position based on window size, difficulty, and order.
	int xPos = (winWidth / (2 * difficulty))*((2 * (order % difficulty)) + 1) - (width / 2);
	int yPos = 0;
	if (order < difficulty) {
		yPos = (winHeight / 4) - (height / 2);
	}
	else {
		yPos = (winHeight / 4) * 3 - (height / 2);
	}

	//creates new rectangle and text to place on the screen
	Button b(Point(xPos, yPos), width, height, string(1, character), cb, this);
	//Rectangle r(Point(xPos, yPos), width, height);
	//Text t(Point(xPos + (width/2)-5, yPos + (height/2)+5), string(1,character));

	//clones new objects into the Tile's attributes (This is important and fixes segmentation faults)
	//tile.clone(r);
	//tileChar.clone(t);
	butt.clone(b);
	//If we want to add styles to the tiles we would put them in here.
	//attaches the tile to the window
	//win.attach(tile);
	//win.attach(tileChar);
	(*win).attach(butt);
}

void Tile::clone(Tile& t)
{
	character = t.character;
	difficulty = t.difficulty;
	originalOrder = t.originalOrder;
	order = t.order;
	hand = t.hand;
	played = t.played;
	beenPlayed = t.beenPlayed;
	tile.clone(t.tile);
	tileChar.clone(t.tileChar);
	butt.clone(t.butt);
	win = t.win;
}

Tile::Tile(Tile& t) :
	character(t.character),
	difficulty(t.difficulty),
	originalOrder(t.originalOrder),
	order(t.order),
	hand(t.hand),
	played(t.played),
	beenPlayed(false),
	tile(t.tile),
	tileChar(t.tileChar),
	butt(t.butt),
	win(t.win)
	{
	}