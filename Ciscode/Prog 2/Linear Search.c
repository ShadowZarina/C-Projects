/*
Create a C program that allows a user to input elements in an array and a number to look for, search the array, and print out the index where it's located.

The program should:
1. Ask the user to input the elements of the array.
2. Print out the original array.
3. Call a function int search(array[], length) to ask for a number to search.
4. Using a for loop, the function should iterate through the whole array to find the index of the number that matches what the user is searching for.
5. Return back to the main function.
6. If there is a corresponding number in the array, print out the index of the element that matches. Otherwise, state that the number cannot be found.
*/

#include <stdio.h>

int search(int array[], int length) {
    int i, index = -1, num;

    printf("Enter a number to search for in the array: ");
    scanf("%d", &num);
    
    for (i = 0; i < length; i++) {
        if (array[i] == num) {
            return i;
        }
        return 1;
    }
    
}
    
int main() {
    int i, index = -1; length = 10; array[10];

    // Input elements for array1
    printf("\n--- Enter elements for the array ---\n");
    for (i = 0; i < length1; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &array[i]);
    }
    // Print the final sorted array
    printf("\nArray:\n{ ");
    for (i = 0; i < length; i++) {
        printf("%d", array[i]);
        // Print commas if 'i' is still not the last element
        if (i < combinedLength - 1) printf(", ");
    }
    printf(" }\n");

    index = search(array, length);

    if (index != -1) {
        printf("The element can be found in index number %d!", index);
    }
    else {
        printf("The element cannot be found in the array!");
    }
    
    return 0;
}
