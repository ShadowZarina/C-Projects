/*
  Kent makes sure to protect all his devices by using passwords. He wants to do the same for his laptop by creating a program to check for the right password until it is provided. This password checker should:
  1. Ask the user to enter the password.
  2. If the user gets the password wrong, the program should print an error message and ask the user for input once again.
  3. If the user gets the password right, the program will print a success message.
  (Note: Do not change the value of the correct password to ensure the test cases work as intended.)
*/

// Header file declaration
#include <stdio.h>

// Main function 
int main() {
    // Variable declarations
    int password;
    const int correctPassword = 1234;

    // Do-while loop to keep asking until correct password is entered
    do {
        // Ask user for input
        printf("Enter password: ");
        scanf("%d", &password);

        // Check if password is wrong
        if (password != correctPassword) {
            printf("Incorrect password. Try again.\n");
        }

    } while (password != correctPassword); // Loop until correct password

    // If loop exits, it means password was correct
    printf("Correct password. Access granted!\n");

    return 0;
}
