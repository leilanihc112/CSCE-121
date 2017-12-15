#include "std_lib_facilities_4.h"

void swap_v(int a,int b)
{
	int temp;
	temp = a;
	a=b;
	b = temp;
}

void swap_r(int& a,int& b)
{
	int temp;
	temp = a;
	a=b;
	b = temp;
}

/*
void swap_cr(const int & a,const int & b)
{
	int temp;
	temp = a;                          // temp is const
	a=b;
	b = temp;
}
*/

int main()
{
	int x = 7;
	int y = 9;
	swap_v(x,y);                         //compiled because correct argument type, but doesn't change x & y - copy
	cout << "swap_v(x,y) : " << x << " " << y << endl;  //x and y don't change
	swap_r(x,y);                         //compiled because correct argument type
	cout << "swap_r(x,y) : " << x << " " << y << endl;
//	swap_cr(x,y);
//	cout << "swap_cr(x,y) : " << x << " " << y << endl;
	swap_v(7,9);                         //compiled because correct argument type
	cout << "swap_v(7,9) : " << endl;    //void type won't return value
//	swap_r(7,9);                         //needs variable to refer to
//	cout << "swap_r(7,9): " << endl;
//	swap_cr(7,9);
//	cout << "swap_cr(7,9) : " << endl;
	const int cx = 7;                    
	const int cy = 9;
	swap_v(cx,cy);			     //compiled because const int can be used in int type - makes a copy
	cout << "swap_v(cx,cy) : " << cx << " " << cy << endl;  //cx & cy don't change
//	swap_r(cx,cy);                      //const int, not int
//	cout << "swap_r(cx,cy) : " << cx << " " << cy << endl;
//	swap_cr(cx,cy);
//	cout << "swap_r(cx,cy) : " << cx << " " << cy << endl;
	swap_v(7.7,9.9);		     //compiled because read int before '.' character
	cout << "swap_v(7.7,9.9) : " << endl; //void type won't return value
//	swap_r(7.7,9.9);                     //needs variable to refer to
//	cout << "swap_r(7.7,9.9) : " << endl;
//	swap_cr(7.7,9.9);
//	cout << "swap_cr(7.7,9.9) : " << endl;
	double dx = 7.7;
	double dy = 9.9;
	swap_v(dx,dy);			     //compiled because read int before '.' character - made a copy
	cout << "swap_v(dx,dy) : " << dx << " " << dy << endl;   //dx and dy don't change
//	swap_r(dx,dy);                       //double type, not int
//	cout << "swap_r(dx,dy) : " << dx << " " << dy << endl;
//	swap_cr(dx,dy);
//	cout << "swap_cr(dx,dy) : " << dx << " " << dy << endl;
	return 0;
}
