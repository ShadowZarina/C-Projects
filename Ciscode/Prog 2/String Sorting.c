/*
Create a C program that allows the user to input a string then sorts each word alphabetically regardless of punctuation marks or spacing.

The program should:

1. Ask the user to input a string (phrase or sentence).
2. Break down the string into an array of single-word strings. 

(Remove any whitespaces and punctuation marks using the isspace() and ispunct() functions from the ctype.h library.)
(Split the string into words using the strtok() function from string.h)

3. Sort the array of elements in alphabetical order.
(Use the qsort() function from stdlib.h to do so)

4. Print out the sorted words in a single sentence with all words in lowercase.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Function to convert a string to lowercase
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Comparison function for qsort
int compareWords(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    char input[200];
    char temp[200];
    char *words[100];
    int wordCount = 0;

    printf("Enter a phrase or sentence:\n");
    fgets(input, sizeof(input), stdin);

    // Clean the input: remove punctuation
    int j = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        if (!ispunct((unsigned char)input[i])) {
            temp[j++] = input[i];
        }
    }
    temp[j] = '\0';
    temp[strcspn(temp, "\n")] = '\0'; // remove newline from fgets

    toLowerCase(temp);

    // Split the string into words using strtok
    char *token = strtok(temp, " \t\n");
    while (token != NULL && wordCount < 100) {
        words[wordCount] = malloc(strlen(token) + 1);
        strcpy(words[wordCount], token);
        wordCount++;
        token = strtok(NULL, " \t\n");
    }

    if (wordCount == 0) {
        printf("No words to sort.\n");
        return 0;
    }

    // Sort the words alphabetically
    qsort(words, wordCount, sizeof(char *), compareWords);

    // Print sorted words
    printf("\nSorted unique words:\n");
    for (int i = 0; i < wordCount; i++) {
        if (i == 0 || strcmp(words[i], words[i - 1]) != 0) {
            printf("%s", words[i]);
            if (i < wordCount - 1) printf(", ");
        }
        free(words[i]);
    }
    printf(".\n");

    return 0;
}

