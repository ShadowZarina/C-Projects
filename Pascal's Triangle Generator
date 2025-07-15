#include <stdio.h>

void printPascal(int height) {
    int i, j;

    // Loop through rows
    for (i = 0; i < height; i++) {
        int value = 1; // First value in each row is always 1

        // Print leading spaces to center the triangle
        for (j = 0; j < height - i - 1; j++) {
            printf(" ");
        }

        // Print the values for each column in the current row
        for (j = 0; j <= i; j++) {
            printf("%d ", value);
            // Calculate the next value in the row based on the Pascal's Triangle formula
            value = value * (i - j) / (j + 1);
        }

        // Move to the next line (row)
        printf("\n");
    }
}

int main() {
    int height; 

    // Input the height (number of rows) of Pascal's Triangle
    printf("Enter the height of Pascal's Triangle: ");
    scanf("%d", &height);

    // Print Pascal's Triangle
    printPascal(height);

    return 0;
}
