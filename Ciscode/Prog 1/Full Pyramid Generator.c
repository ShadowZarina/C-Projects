/*
After seeing artificial pyramids in Dubai, Von is inspired to build his own pyramids--in code. He wants to create a program that can generate full pyramids. The program should:

1. Ask the user to input the number of rows the pyramid should have.
2. Generate the pyramid row-by-row through the use of loops.
3. Output the full pyramid for the user to see.
*/ 

#include<stdio.h>

int main() {

    int i, j, rows, spaces;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    for (i = 0; i <= rows; i++) {
        for (j = 0; j < (rows - i); j++) {
            printf(" ");
        }

        for (j = 0; j < 2*i-1; j++) {
            printf("#");
        }

        printf("\n");
    }

    return 0;
}

