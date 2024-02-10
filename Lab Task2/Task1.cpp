#include <iostream>
#include <string.h>
using namespace std;

/*1.	Write a program to determine whether the Given Input is Numeric Constant or Not.
e.g. (if 100, 991, 1810 etc are given as an input , then the program says “numeric constant”,
      or if we take input as “ABCD”, “A1B2”, then the program will say that this is “not numeric”).*/


string c={'A','B','C','D','E','F','G','H','I',
'J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z', 'a','b','c','d',
'e','f','g','h','i','j','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

bool numConst(string s)
{
    bool flag=0;

    for(int i=0; i<s.length(); i++)
    {
        if(s[i]== '0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9')
        {
            flag=1;
        }
        for(int j=0; j<c.length();j++)
        {
            if(s[i]==c[j])return false;
        }
    }
    return flag;
}

int main()
{
    string st;
    cin>>st;
    if(numConst(st)==true)cout<<"numeric constant"<<endl;
    else cout<<"not numeric"<<endl;
    return 0;
}

