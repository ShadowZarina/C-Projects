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

#include <stdio.h>
#include <string.h>

void addTasks(char tasks[][100], int *length) {
    if (*length >= 10) {
        printf("Task list is full!\n");
        return;
    }
    printf("Enter a new task: \n");
    fgets(tasks[*length], 100, stdin);
    (*length)++;                 
}

void viewTasks(char tasks[][100], int *length) {
    int i;

    printf("\n----- To-Do List -----\n");
    if (*length == 0) {
        printf("No tasks left to do!\n");
        return;
    }

    for (i = 0; i < *length; i++) {
        printf("%d. %s", i + 1, tasks[i]);
    }
}

void deleteTasks(char tasks[][100], int *length) {
    int i, index;

    if (*length == 0) {
        printf("No tasks available to delete!\n");
        return;
    }

    viewTasks(tasks, length);

    printf("\nEnter the number of the task you want to delete: ");
    scanf("%d", &index);

    if (index < 1 || index > *length) {
        printf("Invalid task number!\n");
        return;
    }

    for (i = index - 1; i < *length - 1; i++) {
        strcpy(tasks[i], tasks[i + 1]);
    }

    (*length)--;   
    printf("Task %d deleted successfully!\n", index);
}

int main() {
    int choice, length = 0;
    char tasks[10][100];

    while (1) {
        printf("\n----- TO-DO LIST MENU -----\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Delete Task\n");
        printf("4. Exit\n");
        printf("Enter a choice: ");
        scanf("%d", &choice);
        while (getchar() != '\n'); 

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
    // Header file declarations
    return 0;
}

 // Header file declarations
#include <stdio.h>
#include <string.h>

// Add tasks function
void addTasks(char tasks[][100], int *length) {
    // Ask user to input a new task
    printf("Enter a new task: \n");             
}

// View tasks function
void viewTasks(char tasks[][100], int *length) {
    // Print out all tasks
    printf("%d. %s");
}

// Delete tasks function
void deleteTasks(char tasks[][100], int *length) {
    // Call viewTasks function
    viewTasks();

    // Ask for task index & shift tasks accordingly
    printf("\nEnter the number of the task you want to delete: ");
    scanf();

    
    printf("Task %d deleted successfully!\n", index);
}

// Main functions
int main() {
    // Variable declarations
    char tasks[10][100];

    // While loop
    while () {
        // Print out main menu
        printf("\n----- TO-DO LIST MENU -----\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Delete Task\n");
        printf("4. Exit\n");
        printf("Enter a choice: ");
        scanf();

        // Switch case to call functions
        switch () {
            case 1:
                addTasks();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                deleteTasks();
                break;
            case 4:
                printf("Closing the program.");
            default:
                printf("Invalid choice, try again!\n");
        }
    }

    // End program
    return 0;
}


