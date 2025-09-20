/*
As a computer engineer, Vaughn is going to need a lot of multiplication in his work! Therefore, he wants to create a program that can print out multiplication tables for him to use! The program should:

1. Ask the user to input the number to generate the multiplication for as well as the number of rows the table should have.
2. Print out the multiplication table row-by-row using a for loop.
  */

// Header file declaration
#include<stdio.h>

// Main function
int main() {
    int i, num, rows;

    printf("Enter the number you want to generate a multiplication table for: ");
    scanf("%d", &num);
    printf("Enter how many rows you want in the table: ");
    scanf("%d", &rows);

    for (i = 1; i <= rows; i++) {
        printf("%d x %d = %d\n", num, i, num * i);
    }

    return 0;
}
