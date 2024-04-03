#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    char c;
    int state=0,i=0;
    cout << "\n Enter a string:";
    getline(cin, s);
    char cc[100];
    while(i < s.length())
    {
        switch(state)
        {
            case 0:
                c=s[i++];
                if(c=='a'){
                    state=1;
                    cc[i++]=c;
                }
                else if(c=='b'){
                    state=2;
                    cc[i++]=c;
                }
                else{
                    state=6;
                    cc[i++]=c;
                }
                break;
            case 1:
                c=s[i++];
                if(c=='a'){
                    state=3;
                    cc[i++]=c;
                }
                else if(c=='b'){
                    state=4;
                    cc[i++]=c;
                }
                else{
                    state=6;
                    cc[i++]=c;
                }
                break;
            case 2:
                c=s[i++];
                if(c=='a'){
                    state=6;
                    cc[i++]=c;
                }
                else if(c=='b'){
                    state=2;
                    cc[i++]=c;
                }
                else{
                    state=6;
                    cc[i++]=c;
                }
                break;
            case 3:
                c=s[i++];
                if(c=='a'){
                    state=3;
                    cc[i++]=c;
                }
                else if(c=='b'){
                    state=2;
                    cc[i++]=c;
                }
                else{
                    state=6;
                    cc[i++]=c;
                }
                break;
            case 4:
                c=s[i++];
                if(c=='a'){
                    state=6;
                    cc[i++]=c;
                }
                else if(c=='b'){
                    state=5;
                    cc[i++]=c;
                }
                else{
                    state=6;
                    cc[i++]=c;
                }
                break;
            case 5:
                c=s[i++];
                if(c=='a'){
                    state=6;
                    cc[i++]=c;
                }
                else if(c=='b'){
                    state=2;
                    cc[i++]=c;
                }
                else{
                    state=6;
                    cc[i++]=c;
                }
                break;
            case 6:
                cout << "\n " << s << " is not recognised.";
                exit(0);
        }
    }
    if(state==1)
        cout << "\n " << s << " is accepted under rule 'a'";
    else if((state==2)||(state==4))
        cout << "\n " << s << " is accepted under rule 'a*b+'";
    else if(state==5)
        cout << "\n " << s << " is accepted under rule 'abb'";

    for(int i=0;i<7;i++){
        cout<<cc[i];
    }

    return 0;
}

