/*
Create a C program that allows the user to input a string then sorts each word alphabetically regardless of punctuation marks or spacing.

The program should:
1. Ask the user to input the length of the array.
2. Ask the user to input an array of words.
3. Sort the array of elements in alphabetical order.
(Use the strcmp() and strcpy() functions from string.h to compare and copy strings in array indices respectively.)
4. Print out the sorted words in order with commas separating them.
*/

// Header file declarations
#include <stdio.h>
#include <string.h>

// Main function
int main() {
    int i, j, length; 
    char temp[20];

    // Ask user to input length
    printf("Enter the number of words in the array: ");
    scanf("%d", &length);

    // Declare the array with length and size
    char array[length][20]; 

    // For loop to allow user to input all strings of array
    for (i = 0; i < length; i++) {
        printf("Enter word %d: ", i + 1);
        scanf("%s", array[i]);
    }

    // Print out the original array of strings
    printf("\nOriginal array:\n");
    for (i = 0; i < length; i++) {
        if (i == length - 1)
            printf("%s", array[i]);
        else
            printf("%s, ", array[i]);
    }
    printf("\n");

    // Bubble sort to alphabeitcally sort the strings
    for (i = 0; i < length - 1; i++) {
        for (j = 0; j < length - i - 1; j++) {
            if (strcmp(array[j], array[j + 1]) > 0) {
                strcpy(temp, array[j]);
                strcpy(array[j], array[j + 1]);
                strcpy(array[j + 1], temp);
            }
        }
    }

    // Print out the list of sorted words
    printf("\nSorted words:\n");
    for (i = 0; i < length; i++) {
        if (i == length - 1)
            printf("%s", array[i]);
        else
            printf("%s, ", array[i]);
    }
    // End program
    return 0;
}
