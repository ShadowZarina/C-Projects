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
    int length1, length2, combinedLength;
    int temp, i, x, y;

    int array1[], array2[];
    
    for (i = 0; i < length1; i++) {
        printf("Number %d of Array 1: ", i+1);
        scanf("%d", &array1[i]);
    }

    for (i = 0; i < length2; i++) {
        printf("Number %d of Array 2: ", i+1);
        scanf("%d", &array2[i]);
    }

    length1 = sizeof(array1) / sizeof(array1[0]);
    length2 = sizeof(array2) / sizeof(array2[0]);
    combinedLength = length1 + length2;
    int combinedArray[combinedLength];

    // Copy elements from array1 to combinedArray
    memcpy(combinedArray, array1, legnth1 * sizeof(int));

    // Copy elements from array2 to combinedArray, starting after array1's elements
    memcpy(combinedArray + length1, array2, length2 * sizeof(int));
    
    for (x = 0; x < combinedLength - 1; x++) {
        for (y = 0; y < combinedLength - x - 1; y++) {
            if (combinedArray[y] > combinedArray[y + 1]) {
                temp = combinedArray[y];
                combinedArray[y] = combinedArray[y + 1];
                combinedArray[y + 1] = temp;
            }
        }
    }

    for (i = 0; i < combinedLength; i++) {
        if (i == combinedLength - 1) {
            printf("%d", combinedArray[i]);
        } else {
            printf("%d, ", combinedArray[i]);
        }
    }
    printf("}");

    return 0;
}
