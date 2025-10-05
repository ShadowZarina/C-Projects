/*
Create a program that allows a user to input elements in an array of their chosen size, sort the elements in ascending order, and print out the new array.

The program should:
1. Ask the user to input all the 8 elements of the array.
2. Sort out each element in descending order.
3. Using an if-else statement, categorize each element into an array of even numbers or odd numbers.
4. Print out the even and odd arrays in a proper bracketed format.
*/

// Header file declarations
#include<stdio.h>

// Main function
int main() {
    // Variable declarations
    int array[8], length = 8;
    int temp, i, j, left, right, evenCount = 0, oddCount = 0;
    int even[8], odd[8];

    // Input all numbers of the array
    for (i = 0; i < length; i++) {
        printf("Enter number %d of the array: ", i+1);
        scanf("%d", &array[i]);
    }

    left = 0;
    right = length -1;
    
    // Bubble sort all elements of the array in descending order
    for (i = 0; i < length - 1; i++) {
        for (j = 0; j < length - i - 1; j++) {
            if (array[j] < array[j + 1]) { 
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    // Separate odd and even numbers
    for (i = 0; i < length; i++) {
        if (array[i] % 2 == 0) {
            even[evenCount] = array[i];
            evenCount++;
        } else {
            odd[oddCount] = array[i];
            oddCount++;
        }
    }

    // Print out even array
    printf("Even Array: {");
    for (i = 0; i < evenCount; i++) {
        if (i == evenCount - 1) {
            printf("%d", even[i]);
        } else {
            printf("%d, ", even[i]);
        }
    }
    printf("}");
    
    // Print out odd array
    printf("\nOdd Array: {");
    for (i = 0; i < oddCount; i++) {
        if (i == oddCount - 1) {
            printf("%d", odd[i]);
        } else {
            printf("%d, ", odd[i]);
        }
    }
    printf("}");

    return 0;
}
