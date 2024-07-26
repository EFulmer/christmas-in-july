#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Gets the first digit in a string. Assumes there is one.
int get_first_digit(char line[]) {
    char one[] = "one";
    char two[] = "two";
    char three[] = "three";
    char four[] = "four";
    char five[] = "five";
    char six[] = "six";
    char seven[] = "seven";
    char eight[] = "eight";
    char nine[] = "nine";

    for (int i = 0; line[i] != '\n' && line[i] != '\0'; i++) {
        if (isdigit(line[i])) {
            return line[i] - '0';
        } else if (memcmp(&line[i], &one, 3) == 0) {
            return 1;
        } else if (memcmp(&line[i], &two, 3) == 0) {
            return 2;
        } else if (memcmp(&line[i], &three, 5) == 0) {
            return 3;
        } else if (memcmp(&line[i], &four, 4) == 0) {
            return 4;
        } else if (memcmp(&line[i], &five, 4) == 0) {
            return 5;
        } else if (memcmp(&line[i], &six, 3) == 0) {
            return 6;
        } else if (memcmp(&line[i], &seven, 5) == 0) {
            return 7;
        } else if (memcmp(&line[i], &eight, 5) == 0) {
            return 8;
        } else if (memcmp(&line[i], &nine, 4) == 0) {
            return 9;
        }
    }
}

// Gets the last digit in a string. Assumes there is one.
int get_last_digit(char line[], int length) {
    char one[] = "one";
    char two[] = "two";
    char three[] = "three";
    char four[] = "four";
    char five[] = "five";
    char six[] = "six";
    char seven[] = "seven";
    char eight[] = "eight";
    char nine[] = "nine";
    for (int i = length; i > -1; i--) {
        if (isdigit(line[i])) {
            return line[i] - '0';
        } else if (memcmp(&line[i], &one, 3) == 0) {
            return 1;
        } else if (memcmp(&line[i], &two, 3) == 0) {
            return 2;
        } else if (memcmp(&line[i], &three, 5) == 0) {
            return 3;
        } else if (memcmp(&line[i], &four, 4) == 0) {
            return 4;
        } else if (memcmp(&line[i], &five, 4) == 0) {
            return 5;
        } else if (memcmp(&line[i], &six, 3) == 0) {
            return 6;
        } else if (memcmp(&line[i], &seven, 5) == 0) {
            return 7;
        } else if (memcmp(&line[i], &eight, 5) == 0) {
            return 8;
        } else if (memcmp(&line[i], &nine, 4) == 0) {
            return 9;
        }
    }
}

int main(int argc, char* argv[]) {
    char current_line[256];
    int first_digit, last_digit;
    int result = 0;
    FILE* fp;

    // fp = fopen("./input.txt", "r");
    fp = fopen("./input_test_01.txt", "r");

    if (fp == NULL) {
        printf("Error opening file.");
        return 1;
    } else {
        while (fgets(current_line, sizeof current_line, fp) != NULL) {
            first_digit = get_first_digit(current_line);
            last_digit = get_last_digit(current_line, strlen(current_line));
            result += (10 * first_digit + last_digit);
        }
    }
    printf("%d\n", result);
    fclose(fp);
    return 0;
}
