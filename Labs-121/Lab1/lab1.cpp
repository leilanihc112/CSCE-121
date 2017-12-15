#include "std_lib_facilities_4.h"
int main()
{
cout << "Enter the name of the person you want to write to:\n";
string first_name;
cin >> first_name;
cout << "What is the name of another friend?:\n";
string friend_name;
cin >> friend_name;
char friend_sex = 0;
cout << "Enter an 'm' if this friend is male or an 'f' if they are female:\n";
cin >> friend_sex;
int age;
cout << "What is the recipient's age?:\n";
cin >> age;
if (age <= 0 || age >= 110)
{
simple_error("you're kidding!");
}

cout << "\n\nDear " << first_name << ",\n\n";
cout << "\tHow are you? I am fine. I miss you. ";
cout << "Have you seen " << friend_name << " lately? ";
if (friend_sex == 'm')
{
cout << "If you see " << friend_name << " please ask him to call me. ";
}
if (friend_sex == 'f')
{
cout << "If you see " << friend_name << " please ask her to call me. ";
}
cout << "I hear you just had a birthday and you are " << age << " years old. ";
if (age < 12)
{
cout << "Next year you will be " << age+1 << ".\n\n";
}
if (age == 17)
{
cout << "Next year you will be able to vote.\n\n";
}
if (age > 70)
{
cout << "I hope you are enjoying retirement.\n\n";
}
cout << "Yours sincerely,\n\n\nLeilani";
}
