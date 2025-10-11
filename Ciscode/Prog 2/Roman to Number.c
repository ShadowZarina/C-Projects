Create a C program that allows a user to input a Roman numeral, convert it into numbers, and print out the result.

The program should:
1. Ask the user to input a string of Roman numerals.
2. Convert the Roman numerals into an integer.
2a. With a for loop, loop through each character and call getRomanValue(roman[i]);
2b. The function should contain a switch case that assigns numerical values to each Roman numeral and return it to the main function.
3. Print out the converted number.
*/

// Header file declaration
#include <stdio.h>

// Conversion function definition
int getRomanValue(char roman[i]) {

    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0; 
    }
}

// Main function 
int main() {
    int i, length, result = 0;
    
    // Ask for Roman numeral input
    printf("Enter a Roman numeral: ");
    scanf("%s", roman);

    length = strlen(roman);

    // Loop through each character and convert it to numbers
    for (i = 0; i < length; i++) {
        int currentValue = getRomanValue(roman[i]);
        int nextValue = i + 1 
        if (i + 1 < length) {
            getRomanValue(roman[i+1]);
        } else {
            0;
        }

        if (currentValue < nextValue) {
            result += currentValue;
        else if (currentValue > nextValue) {
            result -= currentValue;
        }
    }

    printf("The Roman numeral converted equals to %d.", result);
            
    return 0;
}

