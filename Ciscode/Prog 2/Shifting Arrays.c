/*
Create a program that allows a user to input elements in an array of their chosen size, shift the elements to the right by a certain index, and print out the new array.

The program should:
1. Ask the user to input the number of elements/size of the array.
2. Ask the user to input all the elements of the array.
3. Ask the user to input a countby which the elements will left shift.
4. Call a function "void shiftArray(array, length, count)" that takes in 3 parameters and does the following: 
4a. Shift all the elements of the array to the left by a certain index (left shift by 1 index at a time).
(Elements that have reached the left end of the array (index 0) should be moved to the right end of the array and shifted accordingly.)
4b. Print out the new array in a proper bracketed format.
*/

// Header file declaration
#include <stdio.h>

// Define shiftArray function
void shiftArray(int array[], int length, int count) {
    int i, temp[length];

    count = count % length;  // prevent overflow if count > length

    // Right shift by 'count' positions
    for (i = 0; i < length; i++) {
        temp[i] = array[(i + count) % length];
    }

    // Copy back shifted values to the original array
    for (i = 0; i < length; i++) {
        array[i] = temp[i];
    }

    // Print the shifted array
    printf("\nShifted Array:\n{");
    for (i = 0; i < length; i++) {
        printf("%d", array[i]);
        // Print commas if i is not the last element of the array
        if (i < length - 1) printf(", ");
    }
    printf("}\n");
}

// Main function
int main() {
    int i, length, count;

    // Ask for length of array
    printf("Enter the number of elements for the array: ");
    scanf("%d", &length);
  
    int array[length];

    // Ask for elements of the array
    printf("\nEnter elements for the array:\n");
    for (i = 0; i < length; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    // Ask for the count by which all elements will shift
    printf("Enter the count by which all elements will shift: ");
    scanf("%d", &count);

    // Call shiftArray function
    shiftArray(array, length, count);

    return 0;
}


