#include "main.h"
/**
 * print_last_digit - prints the last digit of a numer.
 * @n: digit to find the last place of.
 * Return: The last digit.
 */

int print_last_digit(int n) {
    if (num < 0) {
        num = -num;
    }

    int last_digit = num % 10;
    char last_digit_char = '0' + last_digit;
    write(1, &last_digit_char, 1);
    return last_digit;
}
