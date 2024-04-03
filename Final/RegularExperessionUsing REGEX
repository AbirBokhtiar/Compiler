#include <iostream>
#include <regex>
#include <string>

using namespace std;

pair<bool, string> recognize_string(const string& input_string) {
    if (regex_match(input_string, regex("a*"))) {
        return make_pair(true, "'" + input_string + "' matches the pattern 'a*'");
    } else if (regex_match(input_string, regex("a*b+"))) {
        return make_pair(true, "'" + input_string + "' matches the pattern 'a*b+'");
    } else if (regex_match(input_string, regex("abb"))) {
        return make_pair(true, "'" + input_string + "' matches the pattern 'abb'");
    } else {
        return make_pair(false, "'" + input_string + "' does not match any of the given patterns");
    }
}

int main() {
    vector<string> test_strings = {"", "a", "aa", "ab", "abb", "aab", "abbb", "bb", "aabbb"};

    for (const string& str : test_strings) {
        auto result = recognize_string(str);
        cout << result.second << endl;
    }

    return 0;
}
