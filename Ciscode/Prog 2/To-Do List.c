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
                printf("%d", tasks[i]);
            } else {
                printf("%d, ", tasks[i]);
            }
        }
        printf("}");

    return 1;
}

int deleteTasks() {
    int index, left = 0; right = length;
    printf("Enter the number of the task you want to delete:");
    scanf("%d", &index);

    for (i = index - 1; i < length; i++) {
        task[i] = task[i + 1];
    }
    
    return 1;
}

int main() {
    int choice, i, length = 0;

    printf("----- TO-DO LIST ----- \n");
    printf("1. Add Task\n");
    printf("2. View Tasks\n");
    printf("3. Delete Task\n");
    scanf("%d", &choice);

    int tasks[length];

    switch case (choice) {
        case 1:
            addTasks();
            break;
        case 2:
            viewTasks();
            break;
        case 3:
            deleteTasks();
            break;
        default:
            break;
    }

    return 0;
}


