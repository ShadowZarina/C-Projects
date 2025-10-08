Create a C program that allows a user to input elements for 2 arrays, merge the two arrays together, and print out the new array in descending order.

The program should:
1. Ask the user to input the number of elements/size of the 2 arrays.
2. Ask the user to input all the elements of the first and second arrays.
3. Merge the elements of the 2 arrays into a single array.
4. Using nested for loops, sort the elements of the new array in DESCENDING order.
5. Print out the new array in a proper bracketed format.
*/

#include <stdio.h>

int main() {
    int temp, i, x, y, length1, length2, combinedLength;
    
    // Ask for array sizes for array1 and array2
    printf("Enter the number of elements for Array 1: ");
    scanf("%d", &length1);

    printf("Enter the number of elements for Array 2: ");
    scanf("%d", &length2);

    // Declare the 2 variable-length arrays
    int array1[length1];
    int array2[length2];

    // Input elements for array1
    printf("\n--- Enter elements for Array 1 ---\n");
    for (i = 0; i < length1; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &array1[i]);
    }

    // Step 4: Input elements for array2
    printf("\n--- Enter elements for Array 2 ---\n");
    for (i = 0; i < length2; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &array2[i]);
    }

    // Merge the arrays into a combinedArray, Calculate combinedLength
    combinedLength = length1 + length2;
    int combinedArray[combinedLength];

    // Copy elements from array1 onto combinedArray
    for (i = 0; i < length1; i++) {
        combinedArray[i] = array1[i];
    }

    // Copy elements from array2 onto combinedArray
    for (i = 0; i < length2; i++) {
        combinedArray[length1 + i] = array2[i];
    }

    // Sort the combined array in descending order using nested loops
    for (x = 0; x < combinedLength - 1; x++) {
        for (y = 0; y < combinedLength - x - 1; y++) {
            if (combinedArray[y] < combinedArray[y + 1]) {
                temp = combinedArray[y];
                combinedArray[y] = combinedArray[y + 1];
                combinedArray[y + 1] = temp;
            }
        }
    }

    // Print the final sorted array
    printf("\nMerged Array in Descending Order:\n{ ");
    for (i = 0; i < combinedLength; i++) {
        printf("%d", combinedArray[i]);
        // Print commas if 'i' is still not the last element
        if (i < combinedLength - 1) printf(", ");
    }
    printf(" }\n");

    return 0;
}
