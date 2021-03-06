/**
 * Number letter counts
 * Myyyura
 */

/**
 * If the numbers 1 to 5 are written out in words: one, two, three, four, five, 
 * then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
 * 
 * If all the numbers from 1 to 1000 (one thousand) inclusive were written out 
 * in words, how many letters would be used?
 * 
 * NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) 
 * contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. 
 * The use of "and" when writing out numbers is in compliance with British usage.
 */

#include <stdio.h>
#include <string.h>

/* one, two, three, ... , nineteen */
int proper[20] = {0, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 6, 6, 8, 8, 7, 7, 9, 8, 8};

/* twenty, thirty, ... , ninety */
int tenth[8] = {6, 6, 5, 5, 5, 7, 6, 6};

int below_100(int n) {
    if (n < 20) {
        return proper[n];
    }

    return tenth[n / 10 - 2] + proper[n % 10];
}

// n <= 1000
int number_letter_lenth(int n) {
    if (n < 100) {
        return below_100(n);
    }

    int lenth = 0;

    int h = (n / 100) % 10;
    int t = n / 1000;
    int s = n % 100;

    if (n > 999) {
        lenth += below_100(t) + 8; // thousand
    }

    if (h != 0) {
        lenth += proper[h] + 7; // hundred
    }

    if (s != 0) {
        lenth += below_100(s) + 3; // and
    }

    return lenth;
}

int letters_lenth_until_n(int n) {
    int lenth = 0;
    for (int i = 1; i <= n; i++) {
        lenth += number_letter_lenth(i);
    }

    return lenth;
}

int main(void) {
    printf("%d\n", letters_lenth_until_n(1000));
    return 0;
}