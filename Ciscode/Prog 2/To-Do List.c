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
    scanf("%s", &tasks[length]);
    length++;
}

int viewTasks() {
    int i;

    printf("To-Do List:\n");
        
        if (length == 0) {
            printf("No tasks left to do!");
            return 1;
        } else {
            for (i = 0; i < length; i++) {
                if (i == length - 1) {
                    printf("\n%d. %s", i+1, tasks[i]);
                } else {
                    printf("\n%d. %s, ", i+1, tasks[i]);
                }
            }
        }
}

int deleteTasks() {
    int i, index, length;

    if (length == 0) {
            printf("No tasks available to delete!");
            return 1;
        } else {
            for (i = 0; i < length; i++) {
                if (i == length - 1) {
                    printf("\n%d. %s", i+1, tasks[i]);
                } else {
                    printf("\n%d. %s, ", i+1, tasks[i]);
                }
            }
        }

    printf("\nEnter the number of the task you want to delete:");
    scanf("%d", &index);

    for (i = 0; i < length - index - 1; i++) {
        tasks[index-1] = tasks[index];
    }

    length--;
}

int main() {
    int tasks[10], choice, i, length = 0;

    printf("----- TO-DO LIST ----- \n");
    printf("1. Add Task\n");
    printf("2. View Tasks\n");
    printf("3. Delete Task\n");
    printf("Enter a choice:");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            addTasks();
            return 1;
        case 2:
            viewTasks();
            return 1;
        case 3:
            deleteTasks();
            return 1;
        default:
            break;
    }

    return 0;
}


