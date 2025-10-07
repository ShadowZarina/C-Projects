Create a C program that allows a user to input elements for 2 arrays, merge the two arrays together, and print out the new array in descending order.

The program should:
1. Ask the user to input the number of elements/size of the 2 arrays.
2. Ask the user to input all the elements of the arrays (one array at a time).
3. Merge the two arrays together into one, regardless of the element order.
4. Use a nested for loop to sort through the array and arrange all its elements in descending order.
5. Print out the new array in a proper bracketed format.
*/

#include <stdio.h>

int main() {
    int length;
    int temp, i;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &length);

    int array[length];

    for (i = 0; i < length; i++) {
        printf("Enter number %d of the array: ", i+1);
        scanf("%d", &array[i]);
    }

    int size1 = sizeof(array1) / sizeof(array1[0]);
    int size2 = sizeof(array2) / sizeof(array2[0]);
    int combinedSize = size1 + size2;
    int combinedArray[combinedSize];

    // Copy elements from array1 to combinedArray
    memcpy(combinedArray, array1, size1 * sizeof(int));

    // Copy elements from array2 to combinedArray, starting after array1's elements
    memcpy(combinedArray + size1, array2, size2 * sizeof(int));
    
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
            printf("%d", combinedArray[i]);
        } else {
            printf("%d, ", combinedArray[i]);
        }
    }
    printf("}");

    return 0;
}
