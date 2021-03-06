/**
 * Names scores
 * Myyyura
 */

/**
 * Using names.txt (right click and 'Save Link/Target As...'), a 46K text file 
 * containing over five-thousand first names, begin by sorting it into alphabetical 
 * order. Then working out the alphabetical value for each name, multiply this 
 * value by its alphabetical position in the list to obtain a name score.
 *
 * For example, when the list is sorted into alphabetical order, COLIN, which 
 * is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN 
 * would obtain a score of 938 × 53 = 49714.
 * 
 * What is the total of all the name scores in the file?
 */

#include <stdio.h>
#include <stdint.h>
// #include <string.h>
#include <stdlib.h>

char name_list[10000][20];

int read_data(FILE *input) {
    int num_names = 0, cur_name_len = 0;
    for (char c = '\0'; (c = getc(input)) != EOF;) {
        if (c == ',') {
            name_list[num_names++][cur_name_len] = '\0';
            cur_name_len = 0;
        }

        if (c >= 'A' && c <= 'Z') {
            name_list[num_names][cur_name_len++] = c;
        }
    }
    name_list[num_names][cur_name_len] = '\0';

    return num_names + 1;
}

int64_t value_of_name(int pos, char *name) {
    int64_t value = 0;
    for (int i = 0; name[i] != '\0'; i++) {
        value += (name[i] - 'A' + 1);
    }

    return value * pos;
}

int compare_in_alphabetical_order(const void *a, const void *b) {
    for (int i = 0; ; i++) {
        if (*(char *)(a + i) != *(char *)(b + i)) {
            return (int)(*(char *)(a + i)) < (int)(*(char *)(b + i)) ? -1 : 1;
        }

        if (*(char *)(a + i) == '\0') {
            return 0;
        }
    }

    return 0;
}

int64_t total_value_of_name_list(int n) {
    // actually we can use <strcmp> instead of compare_in_alphabetical_order
    qsort(name_list, n, sizeof(name_list[0]), compare_in_alphabetical_order);
    int64_t total_value = 0;
    for (int i = 0; i < n; i++) {
        total_value += value_of_name(i + 1, name_list[i]);
    }

    return total_value;
}

int main(void) {
    FILE *names = fopen("../../data/p22_names.txt", "r");
    int num_names = read_data(names);
    printf("%lld\n", total_value_of_name_list(num_names));
    return 0;
}