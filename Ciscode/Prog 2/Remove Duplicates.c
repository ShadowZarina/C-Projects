/*
Create a program that allows a user to input elements in an array of their chosen size, remove duplicate elements, and print out the new organized array.

The program should:
1. Ask the user to input the number of elements/size of the array.
2. Ask the user to input all the elements of the array based on its size.
3. Call a function removeDuplicates(array, length) that will do the following:
3a. Sort the array in alphabetical order.
3b. Remove duplicates from the sorted array.
4. Print out the new array in a proper bracketed format.
*/

#include <stdio.h>

int main() {
    int length;
    int temp, i, x, y;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &length);

    int array[length];

    for (i = 0; i < length; i++) {
        printf("Enter number %d of the array: ", i+1);
        scanf("%d", &array[i]);
    }

    for (x = 0; x < length - 1; x++) {
        for (y = 0; y < length - x - 1; y++) {
            if (array[y] > array[y + 1]) {
                temp = array[y];
                array[y] = array[y + 1];
                array[y + 1] = temp;
            }
        }
    }

    for (i = 0; i < length; i++) {
        if (i == length - 1) {
            printf("%d", array[i]);
        } else {
            printf("%d, ", array[i]);
        }
    }
    printf("}");

    return 0;
}
