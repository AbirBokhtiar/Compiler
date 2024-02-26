#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isValidIdentifier(const char *str) {
    if (!isalpha(str[0]) && str[0] != '_') {
        return 0;
    }

    for (int i = 1; i < strlen(str); ++i) {
        if (!isalnum(str[i]) && str[i] != '_') {
            return 0;
        }
    }
    return 1;
}

void analyzeCCode(FILE *file) {
    char code[1000000];
    while (fgets(code, sizeof(code), file) != NULL) {
        printf("%s", code);
        if (strstr(code, "int ") || strstr(code, "float ") || strstr(code, "char ")) {
            if (strstr(code, "(") && strstr(code, ")")) {
                printf("Function Declaration: %s", code);
            } else if (strstr(code, "{") && strstr(code, "}")) {
                printf("Function Definition: %s", code);
            } else {
                printf("Variable Declaration: %s", code);
            }
        }
    }
}

int main() {
    FILE *file = fopen("input3Lab4.txt", "r");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    analyzeCCode(file);

    fclose(file);
    return 0;
}
