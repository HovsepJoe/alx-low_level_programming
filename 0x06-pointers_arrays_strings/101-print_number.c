#include <stdio.h>
#include "main.h"

/*
 * Prototype: void print_number(int n);
 * You can only use _putchar function to print
 * You are not allowed to use long
 */

int _putchar(char c) {
    return write(1, &c, 1);
}

void print_number(int n) {
    if (n < 0) {
        _putchar('-');
        n = -n;
    }

    int divisor = 1;
    while (n / divisor >= 10) {
        divisor *= 10;
    }

    while (divisor > 0) {
        int digit = n / divisor;
        _putchar(digit + '0');
        n %= divisor;
        divisor /= 10;
    }
}

int main() {
    int number = -12345;
    print_number(number);
    _putchar('\n');

    return 0;
}
