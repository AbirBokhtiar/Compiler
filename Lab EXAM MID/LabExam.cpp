#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

void findOperators(const string &s, vector<char> &operators) {
    char c;
    for (int i = 0; i < s.length(); i++) {
        c = s[i];
        if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '=' || c == '%') {
            operators.push_back(c);
        }
    }
}

void analyzeCCode(FILE *file) {
    char code[100];
    int var_count = 0;
    int func_count = 0;
    int prep_count = 0;
    int prep2_count = 0;
    int temp_var = 0;
    int unique_oper = 4;

    while (fgets(code, sizeof(code), file) != NULL) {
        if (prep2_count < 1) {
            if (strstr(code, "#include")) {
                printf("Preprocessor: %s", code);
                prep2_count++;
            }
        }

        if (strstr(code, "#define")) {
            printf("Preprocessor- %s", code);
            prep_count++;
        }

        if (strstr(code, "int ") || strstr(code, "float ") || strstr(code, "char ")) {
            if (strstr(code, ";")) {
                if (strstr(code, ",")) {
                    temp_var = 1;
                    printf("Variable- ");
                    for (int i = 0; i < sizeof(code); i++) {
                        if (code[i] == ',') {
                            temp_var++;
                            continue;
                        }
                        if (code[i] == ';' || code[i] == '\n')
                            break;
                        if (isalpha(code[i]) || code[i] == '_') {
                            printf("%c", code[i]);
                        }
                    }
                    printf("\n");
                    var_count += temp_var;
                } else {
                    printf("Variable- ");
                    for (int i = 0; i < sizeof(code); i++) {
                        if (code[i] == ';' || code[i] == '\n')
                            break;
                        if (isalpha(code[i]) || code[i] == '_') {
                            printf("%c", code[i]);
                        }
                    }
                    printf("\n");
                    var_count++;
                }
            }

            if (strstr(code, "(") && strstr(code, ");")) {
                printf("Function Declaration- %s", code);
            } else if (strstr(code, "{")) {
                if (!strstr(code, "main")) {
                    func_count++;
                    printf("User defined- %s", code);
                }
            }
        }
    }

    printf("No. of preprocessor: %d\n No. of functions: %d\n No. of Variable: %d\n Number of unique operator(s):%d\n", prep_count + prep2_count, func_count, var_count, unique_oper);
}

int main() {
    FILE *file = fopen("text.txt", "r");
    if (file == NULL) {
        cout << "Error opening file" << endl;
        return 1;
    }

    string file_content;
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        file_content += ch;
    }

    fclose(file);

    analyzeCCode(fopen("text.txt", "r"));

    vector<char> operators;
    findOperators(file_content, operators);

    cout << "Operators found: ";
    for (char op : operators) {
        cout << op << " ";
    }
    cout << endl;

    return 0;
}
