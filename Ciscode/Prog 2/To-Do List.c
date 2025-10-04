/* 
Create a To-Do List program where the user can add, view, and delete tasks.

The program should:

1. Print out a list of options for the user to choose from.
2. Ask the user to input their choice.
3. Call a function corresponding to the user's choice using a switch case.

(To ensure the main menu loops after each function call, secure all the code above in a while (1) loop.)

3a. Add Tasks
void addTasks(char tasks[][100], int *length) 
Allow the user to input a task in their own words.

(Use the fgets(array[*length], char limit, stdin) to read input.)

3b. View Tasks
void viewTasks(char tasks[][100], int *length)
Print out a list of all tasks using an array.

3c. Delete Tasks
void deleteTasks(char tasks[][100], int *length)
Delete a task by asking the user to input its index.

(Make sure to call the viewTasks function to print out the list of tasks again.)
(You may use the strcpy() function from string.h to left shift the tasks.)
*/

// Header file delcarations
#include <stdio.h>
#include <string.h>

// Add task function
void addTasks(char tasks[][100], int *length) {
    // Check if task list is full
    if (*length >= 10) {
        printf("Task list is full!\n");
        return;
    }
    // Add a new task
    printf("Enter a new task: \n");
    fgets(tasks[*length], 100, stdin);
    (*length)++;                 
}

// View tasks function
void viewTasks(char tasks[][100], int *length) {
    int i;
    // Print out to-do list
    printf("\n----- To-Do List -----\n");
    // Check if there are 0 tasks
    if (*length == 0) {
        printf("No tasks left to do!\n");
        return;
    }
    // Print out tasks one-by-one
    for (i = 0; i < *length; i++) {
        printf("%d. %s", i + 1, tasks[i]);
    }
}

// Delete tasks function
void deleteTasks(char tasks[][100], int *length) {
    int i, index;
    // Check if there are 0 tasks
    if (*length == 0) {
        printf("No tasks available to delete!\n");
        return;
    }
    // Call function to view task list
    viewTasks(tasks, length);

    // Ask user to input index
    printf("\nEnter the number of the task you want to delete: ");
    scanf("%d", &index);

    // Check if index input is valid
    if (index < 1 || index > *length) {
        printf("Invalid task number!\n");
        return;
    }
    // Move all tasks to the right of the index to the left
    for (i = index - 1; i < *length - 1; i++) {
        strcpy(tasks[i], tasks[i + 1]);
    }

    (*length)--;   
    printf("Task %d deleted successfully!\n", index);
}

// Main function
int main() {
    int choice, length = 0;
    char tasks[10][100];

    // While loop to print main menu and ask user input
    while (1) {
        printf("\n----- TO-DO LIST MENU -----\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Delete Task\n");
        printf("4. Exit\n");
        printf("Enter a choice: ");
        scanf("%d", &choice);
        while (getchar() != '\n'); 

        // Switch case for user's choice
        switch (choice) {
            case 1:
                addTasks(tasks, &length);
                break;
            case 2:
                viewTasks(tasks, &length);
                break;
            case 3:
                deleteTasks(tasks, &length);
                break;
            case 4:
                printf("Closing the program.\n");
                return 0;
            default:
                printf("Invalid choice, try again!\n");
        }
    }
    // End program
    return 0;
}


