/*
Nolvin uses all types of numbers in engineering, especially binary and decimal numbers. To make his studies easier, he wants to build a converter for the two number systems. This converter should:
1. Ask the user to input a number.
2. Ask the user to input the type of number system the number belongs to.
3. Using a switch statement, call the corresponding calculations/functions for the chosen number system to convert it to the other system.
4. Output the conversion result.

HINTS:
- For the binary to decimal conversion, utilize the modulo and division operators to break down the number by digit, then use the left shift (<<) operator to handle exponents.
- For the decimal to binary conversion, utilize the modulo and division operators and convert the results into an array, then print the result out by array element.
*/

// Header file declaration
#include <stdio.h>
#include <math.h>

// Main function
int main() {
    int original, choice;

    // Printf and scanf statements
    printf("Enter the original number: ");
    scanf("%d", &original);

    printf("Enter the original number system:\n");
    printf("1. Binary\n");
    printf("2. Decimal\n");
    printf("Enter your choice (1-2): ");
    scanf("%d", &choice);

    // Switch case to determine number system and calculations
    switch (choice) {
        case 1: {   // Binary to Decimal
            int binary = original;
            int decimal = 0, remainder, i = 0;

            while (binary != 0) {
                remainder = binary % 10;              
                decimal += remainder * pow(2, i);      
                binary /= 10;                       
                i++;
            }

            printf("Decimal: %d\n", decimal);
            break;
        }

        case 2: {   // Decimal to Binary
            int decimal = original;
            int binary = 0, remainder, i = 1;

            while (decimal != 0) {
                remainder = decimal % 2;
                decimal /= 2;            
                binary += remainder * i;   
                i *= 10;
            }

            printf("Binary: %d\n", binary);
            break;
        }

        default:
            printf("Invalid choice.\n");
            break;
    }

    // End function
    return 0;
}
