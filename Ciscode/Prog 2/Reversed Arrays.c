/* 
Create a program that allows a user to input elements in an array of their chosen size, sort the elements in ascending order, and print out the new array.

The program should:
1. Ask the user to input the number of elements/size of the array.
2. Ask the user to input all the elements of the array based on its size.
3. Use a nested for loop to reverse the order of all inputted numbers.
4. Print out the new array in a proper bracketed format.
*/

#include <stdio.h>

int main() {
    int length;
    int temp, i, left, right;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &length);

    int array[length];

    for (i = 0; i < length; i++) {
        printf("Enter number %d of the array: ", i+1);
        scanf("%d", &array[i]);
    }

    left = 0;
    right = length -1;
    
    while (left < right) {
        temp = array[left];
        array[left] = array[right];
        array[right] = temp;
        left++;
        right--;
    }

    printf("Reversed Array: {");
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
