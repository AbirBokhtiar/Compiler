#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main() {
    string s;
    cout << "\nEnter a string: ";
    getline(cin, s);

    if (regex_match(s, regex("a*"))) {
        cout << "\n" << s << " is accepted under rule 'a*'";
    } else if (regex_match(s, regex("a*b+"))) {
        cout << "\n" << s << " is accepted under rule 'a*b+'";
    } else if (regex_match(s, regex("abb"))) {
        cout << "\n" << s << " is accepted under rule 'abb'";
    } else {
        cout << "\n" << s << " is not recognized.";
    }

    return 0;
}
