#include <iostream>
#include <string.h>
using namespace std;
/*
4.	Write a program to determine whether the Given Input is Identifier or Not. []
Conditions/convention to detect identifier:
a)	The first character should be alphabet characters/underscore (A-Z, a-z, _)
b)	From the Second character should be alpha-numeric characters/underscore (A-Z, a-z, _ , 0-9)

*/

bool isAlpha(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

bool isDigit(char ch)
{
    return ch >= '0' && ch <= '9';
}

bool isUnderscore(char ch)
{
    return ch == '_';
}

bool isIdentifier(string input)
{

    if (input.empty()) {return false;}

    if (!isAlpha(input[0]) && !isUnderscore(input[0])) {return false;}

    for (int i = 1; i<input.length(); ++i)
    {
        if (!isAlpha(input[i]) && !isDigit(input[i]) && !isUnderscore(input[i]))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string s;
    cout<<"Enter a string to check if it's an identifier: ";
    cin>>s;

    if (isIdentifier(s))
    {
        cout<<"'"<<s<<"' is a valid identifier."<<endl;
    }
    else
    {
        cout<<"'"<<s<<"' is not a valid identifier."<<endl;
    }

    return 0;
}



