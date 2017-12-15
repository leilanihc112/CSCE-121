#include "Chrono.h"

namespace Chrono {

// member function definitions:


Date::Date(int yy, int mm, int dd)
    : y(yy), m(mm), d(dd)
{
    if (!is_date(yy,mm,dd)) throw Invalid();
}

int days_in_month(int y, int m, int d)
{
    if (d<=0) return false;            // d must be positive

    return 31;            // most months have 31 days

    switch (m) {
case 2:                        // the length of February varies
    return (leapyear(y))?29:28;
    break;
case 4: case 6: case 9: case 11:
    return 30;                // the rest have 30 days
    break;
    }
}

void Date::add_day(int& y, int& m, int& d, int n)
{
//Pseudocode:
//Repeat n times:
//add 1 to d //legal, unless we were at the end of the month
//if is_date is false
	//need to change to first of next month
	//set d to 1
	//if m is December
		//need to change to next year too
		//set m to January
		//increment y
	//else
		//increment m
	// use linear_day() below or things get really messy
	if (n<0) error("add_day(): can't handle negative n");	// not yet
	for (int i = 1; i <= n; ++i) 
	{
		d = d+1;
		if (is_date(y,m,d) == false) 
		{
			d = 1;
			if (m == 12) {
				m = 1;
				y = y+1;
			}
			else {
				m = m+1;
			}
		}
	}
}

void Date::add_month(int n)
{
	if (n<0) error("add_month(): cnot implemented");	// not yet
	// ...
}


void Date::add_year(int y, int m, int d, int n)
{
    if (m==2 && d==29 && !leapyear(y+n)) { // beware of leap years!
			// makes sense for both positive and negative n (n==0 should be impossible here)
			m = 3;        // use March 1 instead of February 29
			d = 1;
    }
    y+=n;
}

// helper functions:

bool is_date(int y, int m, int d)
{
    // assume that y is valid

    if (d<=0) return false;            // d must be positive
    if (m>12 || m<=0) return false;

    int days_in_month = 31;            // most months have 31 days

    switch (m) {
case 2:                        // the length of February varies
    days_in_month = (leapyear(y))?29:28;
    break;
case 4: case 6: case 9: case 11:
    days_in_month = 30;                // the rest have 30 days
    break;
    }

    if (days_in_month<d) return false;

    return true;
} 

bool leapyear(int y)
{
	if ((y % 4) == 0 && (y % 100) == 0 && (y % 400) != 0) {
		return false;
	}
	else if ((y % 4) == 0 || ((y % 4) == 0 && (y % 100) == 0 && (y % 400) == 0)) {
		return true;
	}
	else {
		return false;
	}
}

bool operator==(const Date& a, const Date& b)
{
    return a.year()==b.year()
        && a.month()==b.month()
        && a.day()==b.day();
}

bool operator!=(const Date& a, const Date& b)
{
    return !(a==b);
}

ostream& operator<<(ostream& os, const Date& d)
{
    return os << '(' << d.year()
              << ',' << d.month()
              << ',' << d.day() 
              << ')';
}

istream& operator>>(istream& is, Date& dd)
{
    int y, m, d;
    char ch1, ch2, ch3, ch4;
    is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
    if (!is) return is;
    if (ch1!='(' || ch2!=',' || ch3!=',' || ch4!=')') { // oops: format error
        is.clear(ios_base::failbit);                    // set the fail bit
        return is;
    }
    dd = Date(y,Date::Month(m),d);     // update dd
    return is;
}

int day_of_week(int y, int m, int d)
{
int h;
h = (d+13*(m+1)/5+(y%100)+((y%100)/4)+((y/100)/4)-2*(y/100))%7 - 1;
if (h == -1) 
{
	h = 6;
}
return h;
}

Date next_Sunday(const Date& d)
{
    // ...
    return d;
}

Date next_weekday(const Date& d)
{
    // ...
    return d;
}

} // Chrono

