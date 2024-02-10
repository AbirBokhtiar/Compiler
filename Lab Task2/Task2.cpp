#include <iostream>
#include <string.h>
using namespace std;
/*
2.	Write a program to determine whether the Given Input is Operators or Not. (Arithmetic Operators +, -, *, /, %, =)
e.g., 2+3=5
Ans:
operator1:  +
operator2:  =
*/

bool isOperator(char op)
{
    return op == '+' || op == '-' || op == '*' || op == '/' || op == '%' || op == '=';
}

int main() {
    string input;
    cout<<"Enter a string to check if it contains operators: ";
    getline(cin, input);

    cout<<"Operators:"<<endl;
    for (char ch : input)
    {
        if (isOperator(ch))
        {
            cout<<ch<<endl;
        }
    }

    return 0;
}

