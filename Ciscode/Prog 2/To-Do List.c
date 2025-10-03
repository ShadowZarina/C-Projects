/* 
Create a To-Do List program where the user can add, view, and delete tasks.

The program should:
1. Print out a list of options for the user to choose from.
2. Ask the user to input their choice.
3. Call a function corresponding to the user's choice using a switch case.
3a. Allow the user to input a task in their own words.
3b. Print out a list of all tasks using an array.
3c. Delete a task by asking the user to input its index.
*/

#include <stdio.h>

int addTasks() {
    printf("Enter a new task:");
    scanf("%d", tasks[length]);

    return 1;
}

int viewTasks() {
    printf("To-Do List:\n");
        for (i = 0; i < length; i++) {
            if (i == length - 1) {
                printf("%d", array[i]);
            } else {
                printf("%d, ", array[i]);
            }
        }
        printf("}");

    return 1;
}

int main() {
    int choice, i;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &choice);

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

    return 0;
}


