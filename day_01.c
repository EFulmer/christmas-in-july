#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int get_first_digit(char line[]) {
    for (int i = 0; line[i] != '\n' && line[i] != '\0'; i++) {
        if (isdigit(line[i])) {
            return line[i] - '0';
        }
    }
}

int get_last_digit(char line[], int length) {
    int last_digit;
    for (int i = length; i > -1; i--) {
        if (isdigit(line[i])) {
            return line[i] - '0';
        }
    }
}

int main(int argc, char* argv[]) {
    char current_line[256];
    int first_digit, last_digit;
    int result = 0;
    FILE* fp;

    fp = fopen("./input.txt", "r");

    if (fp == NULL) {
        printf("Error opening file.");
        return 1;
    } else {
        while (fgets(current_line, sizeof current_line, fp) != NULL) {
            // printf("%s\n", current_line);
            first_digit = get_first_digit(current_line);
            last_digit = get_last_digit(current_line, strlen(current_line));
            // printf("%d\t%d\n", first_digit, last_digit);
            result += (10 * first_digit + last_digit);
            // break;
        }
    }
    printf("%d\n", result);
    fclose(fp);
    return 0;
}
