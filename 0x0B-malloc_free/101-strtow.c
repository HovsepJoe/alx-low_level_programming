#include "main.h"
#include <stdlib.h>


int is_whitespace(char c) {
    return (c == ' ' || c == '\t' || c == '\n');
}

int count_words(char *str) {
    int count = 0;
    int in_word = 0;

    while (*str) {
        if (!is_whitespace(*str)) {
            if (!in_word) {
                count++;
                in_word = 1;
            }
        } else {
            in_word = 0;
        }
        str++;
    }

    return count;
}

char **strtow(char *str) {
    if (str == NULL || *str == '\0') {
        return NULL;
    }

    int word_count = count_words(str);

    // Allocate memory for the array of pointers
    char **words = (char **)malloc((word_count + 1) * sizeof(char *));
    if (words == NULL) {
        return NULL;  // Memory allocation failed
    }

    int word_index = 0;
    int word_length = 0;
    int in_word = 0;

    while (*str) {
        if (!is_whitespace(*str)) {
            if (!in_word) {
                in_word = 1;
                word_length = 1;
                words[word_index] = str;
                word_index++;
            } else {
                word_length++;
            }
        } else {
            if (in_word) {
                in_word = 0;
                *str = '\0';  // Null-terminate the word
            }
        }
        str++;
    }

    words[word_count] = NULL;  // Set the last element to NULL

    return words;
}

int main() {
    char *str = "This is a sample string";
    char **words = strtow(str);

    if (words == NULL) {
        printf("Failed to split the string\n");
        return 1;
    }

    // Print the words
    for (int i = 0; words[i] != NULL; i++) {
        printf("Word %d: %s\n", i, words[i]);
    }

    // Free the allocated memory
    for (int i = 0; words[i] != NULL; i++) {
        free(words[i]);
    }
    free(words);

    return 0;
}

