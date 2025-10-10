/*
Create a program that allows a user to input elements in an array of their chosen size, remove duplicate elements, and print out the new organized array.

The program should:
1. Ask the user to input the number of elements/size of the array.
2. Ask the user to input all the elements of the array based on its size.
3. Call a function removeDuplicates(array, length) that will do the following:
3a. Sort the array in alphabetical order.
3b. Remove duplicates from the sorted array.
3c. Copy the elements into a different array in the removal process, then copy the elements back into the original.
3d. Print out the new array in a proper bracketed format.
*/

/*
Create a program that allows a user to input elements in an array of their chosen size, remove duplicate elements, and print out the new organized array.

The program should:
1. Ask the user to input the number of elements/size of the array.
2. Ask the user to input all the elements of the array based on its size.
3. Call a function removeDuplicates(array, length) that will do the following:
3a. Sort the array in alphabetical order.
3b. Remove duplicates from the sorted array.
3c. Print out the new array in a proper bracketed format.
*/

// Header file declaration
#include <stdio.h>

// Remove duplicates function definition
int removeDuplicates(int array[], int length) {
    int temp, x, y;

    // Sort the array in ascending order
    for (x = 0; x < length - 1; x++) {
        for (y = 0; y < length - x - 1; y++) {
            if (array[y] > array[y + 1]) {
                temp = array[y];
                array[y] = array[y + 1];
                array[y + 1] = temp;
            }
        }
    }

    int copy[length];
    y = 0;
  
    // Loop through array for duplicates, copy sorted elements into copy array;
    for (x = 0; x < length; x++) {
        if (array[x] != array[x + 1]) {
            copy[y++] = array[x];
        }
    }

    // Copy unique elements back to original array
    for (x = 0; x < y; x++) {
        array[x] = copy[x];
    }
  
    // Return the new array length
    return y;
}

// Main function
int main() {
    int length;
    int i;

    // Input for length of array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &length);

    int array[length];

    // Input for each element in the array
    for (i = 0; i < length; i++) {
        printf("Enter number %d of the array: ", i+1);
        scanf("%d", &array[i]);
    }

    // Call function to remove duplicates
    length = removeDuplicates(array, length);

    // Print out the new array
    printf("Sorted array: {");
    for (i = 0; i < length; i++) {
        if (i == length - 1) {
            printf("%d", array[i]);
        } else {
            printf("%d, ", array[i]);
        }
    }
    printf("}");
}
