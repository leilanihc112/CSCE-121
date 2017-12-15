#include "std_lib_facilities_4.h"

namespace Chrono {

class Date {
public:
    enum Month {
        jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };

	class Invalid { };                 // to throw as exception
    enum Day {
    sunday, monday, tuesday, wednesday, thursday, friday, saturday
    };

    Date(int y, int m, int d);       // check for valid date and initialize
    Date();                            // default constructor
    // the default copy operations are fine

    // non-modifying operations:
    int   day()   const { return d; }
    int month() const { return m; }
    int   year()  const { return y; }

    // modifying operations:
    static void add_day(int& y, int& m, int& d, int n);        
    void add_month(int n);
    void add_year(int y, int m, int d, int n);
private:
    int   y;
    int m;
    int   d;
};


bool is_date(int y, int m, int d); // true for valid date

bool leapyear(int y);                  // true if y is a leap year

bool operator==(const Date& a, const Date& b);
bool operator!=(const Date& a, const Date& b);

ostream& operator<<(ostream& os, const Date& d);
istream& operator>>(istream& is, Date& dd);

int days_in_month(int y, int m, int d);
int day_of_week(int y, int m, int d);

} // Chrono
