#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>

typedef struct {
    int red;
    int blue;
    int green;
} Round;

int get_all_of_color(char* round_description, const char* color) {
    const char *digits = "([0-9]+) ";
    int color_len = strlen(color);
    int digits_len = strlen(digits);
    char reg_pattern[color_len + digits_len];
    strcpy(reg_pattern, digits);
    strcat(reg_pattern, color);

    regex_t regex;
    int re_comp_status;

    re_comp_status = regcomp(&regex, reg_pattern, REG_EXTENDED);
    if (re_comp_status) {
        fprintf(stderr, "Could not compile regex: %s\n", reg_pattern);
        exit(1);
    }

    regmatch_t matches[2];
    int re_match_status;
    re_match_status = regexec(&regex, round_description, 2, matches, 0);

    if (!re_match_status) {
        char subgroup[3];
        int length = matches[1].rm_eo - matches[1].rm_so;
        strncpy(subgroup, round_description + matches[0].rm_so, length);
        subgroup[length] = '\0';
        regfree(&regex);
        return atoi(subgroup);
    }
    regfree(&regex);
    return 0;
}

Round* make_round() {
    Round *rnd = (Round*)malloc(sizeof(Round));
    if (rnd == NULL) {
        fprintf(stderr, "Memory allocation failed");
        exit(1);
    }

    rnd->red = 0;
    rnd->blue = 0;
    rnd->green = 0;

    return rnd;
}

void free_round(Round *rnd) {
    free(rnd);
}

Round* get_round(char* round_description) {
    Round *rnd = make_round();

    rnd->red = get_all_of_color(round_description, "red");
    rnd->blue = get_all_of_color(round_description, "blue");
    rnd->green = get_all_of_color(round_description, "green");

    return rnd;
}

// Expects a semicolon-delimited list of games, and returns a Round object with the minimum number of red, green, and blue cubes kfor it to be valid.
Round* parse_games(char *rounds) {
    Round *max_round = make_round();
    Round *cur_round;
    char *game = strtok(NULL, ";");

    // ...
    do {
        cur_round = get_round(game);
        if (cur_round->red > max_round->red) {
            max_round->red = cur_round->red;
        }
        if (cur_round->blue > max_round->blue) {
            max_round->blue = cur_round->blue;
        }
        if (cur_round->green > max_round->green) {
            max_round->green = cur_round->green;
        }
        game = strtok(NULL, ";");
    } while (game != NULL);

    return max_round;
}

int main(int argc, char *argv[]) {
    char current_line[256];
    char *dup;
    int games[100];
    FILE *fp;
    Round *rnd;
    int rounds = 0;
    int answer_part_one = 0;

    fp = fopen("./input_02.txt", "r");

    if (fp == NULL) {
        printf("Error opening file.");
        return 1;
    }

    while (fgets(current_line, sizeof current_line, fp) != NULL) {
        rounds += 1;
        dup = strdup(current_line);
        char *part_1 = strtok(dup, ":");
        rnd = parse_games(dup);
        if ((rnd->red <= 12) && (rnd->green <= 13) && (rnd->blue <= 14)) {
            answer_part_one += rounds;
        }
        free_round(rnd);
    }

    fclose(fp);

    printf("Answer to part one = %d\n", answer_part_one);

    // Part two: get the minimum number of cubes needed for each game/line
    // And the product of that.
    int answer_part_two = 0;
    int power_of_round;

    fp = fopen("./input_02.txt", "r");

    if (fp == NULL) {
        printf("Error opening file.");
        return 1;
    }

    while (fgets(current_line, sizeof current_line, fp) != NULL) {
        dup = strdup(current_line);
        char *part_1 = strtok(dup, ":");
        rnd = parse_games(dup);
        power_of_round = rnd->red * rnd->green * rnd->blue;
        answer_part_two += power_of_round;
        free_round(rnd);
    }

    fclose(fp);

    printf("Answer to part two = %d\n", answer_part_two);

    return 0;
}
