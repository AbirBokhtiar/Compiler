#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <cstring>
#include <cctype>

using namespace std;

bool contains(string str,char targetChar) {
    return str.find(targetChar) != std::string::npos;
}

bool isKeyword(const char *buffer) {
    const char* keywords[] = {"char", "float", "int", "long", "void"};
    for (const char* keyword : keywords) {
        if (strcmp(buffer, keyword) == 0) {
            return true;
        }
    }
    return false;
}

bool isValidIdentifier(const char *ch) {
    if (isalpha(ch[0]) || ch[0] == '_') {
        return true;
    }
    return false;
}

bool isDelimiter(char ch) {
    return (ch == ',' || ch == ';' || ch == '(' || ch == ')' || ch == '{' || ch == '}');
}

bool isVariableDeclaration(const char *buffer) {
    //dataType variableName;
    // We check for the presence of ';' after the variable name
    if (strstr(buffer, ";") && isValidIdentifier(buffer)) {
        return true;
    }
    return false;
}

bool isFunctionDeclaration(const char *buffer) {
    //returnType functionName(parameters)
    // We check for the presence of '(' after the function name
    if (contains(buffer, '(') && contains(buffer, ')') && !contains(buffer, '{')) {
        return true;
    }
    return false;
}

bool isFunctionDefinition(const char *buffer) {
    //returnType functionName(parameters) { body }
    // We check for the presence of '(' after the function name to ensure it's not a function declaration
    if (contains(buffer, '(') && contains(buffer, ')') && contains(buffer, '{') && contains(buffer, '}')) {
        return true;
    }
    return false;
}

int main() {
    char ch, buffer[100];
    ifstream fin("input3.txt");

    if (!fin.is_open()) {
        cout << "Error opening the file\n";
        exit(0);
    }

    while (fin.get(ch)) {
        if (isalnum(ch) || ch == '_') {
            strncat(buffer, &ch, 1);
        }
        else if ((ch == ' ' || ch == '\n') && (strlen(buffer) != 0)) {
            buffer[strlen(buffer)] = '\0';
            if (isKeyword(buffer)) {
                cout << buffer << " is keyword\n";
            }
            if (isValidIdentifier(buffer)) {
                cout << buffer << " is identifier\n";
            }
            else if (isDelimiter(ch)) {
                cout << ch << " is delimiter\n";
            }
            else if (isValidIdentifier(buffer) && isVariableDeclaration(buffer)) {
                cout << buffer << " is variable declaration\n";
            }
            else if (isValidIdentifier(buffer) && isFunctionDeclaration(buffer)) {
                cout << buffer << " is function declaration\n";
            }
            else if (isFunctionDefinition(buffer)) {
                cout << buffer << " is function definition\n";
            }
            buffer[0] = '\0';
        }
    }

    fin.close();
    return 0;
}
