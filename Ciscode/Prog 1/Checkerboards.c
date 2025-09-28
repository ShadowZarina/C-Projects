/*
Nathan loves playing chess. The problem is, he doesn't have a real chessboard! Therefore, he decided to try creating his own board with a program. This program should:
1. Ask the user to input the number of rows.
2. Ask the user to input the number of columns.
3. Use a nested for loop to create the checkerboard pattern using alternating #'s and spaces.
4. Print out the checkerboard row-by-row.
*/

// Header file declaration
#include<stdio.h>

// Main function 
int main() {
	// Variable declarations
	int rows, columns, i, j;
    // Printf & scanf statements 
	printf("Enter the number of rows: ");
	scanf("%d", &rows);
	printf("Enter the number of columns: ");
	scanf("%d", &columns);
	
	// Nested for loop to create the checkerboard pattern
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            if ((i + j) % 2 == 0) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
	
	return 0;
}
