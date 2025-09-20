/*
Professor Malubay wants to provide students with a basic calculator program to help them understand how conditional branching works in C programming. The calculator should:

1. Ask the user to input two integers(a and b). 
Keep a space before the format specifiers to get rid of any whitespaces after the input.

2. Display a menu of operator choices (1 to 4).
a. 1 → Addition
b. 2 → Subtraction
c. 3 → Multiplication
d. 4 → Division

3. Use a switch statement to call the corresponding function for the selected operator (You may use the functions written below the main function).
Save the result of the function in an integer variable named result.

4. If the user inputs an invalid operator (eg. a number less than 1 or greater than 4), print an error message.
5. If the user selects division and inputs 0 as the value for the 2nd number, print another error message. 

(Note: You may need to declare the result variable and print statement in the division function rather than in the switch statement.)

6. Display the result variable in the main() function after the function returns a value.
*/

#include<stdio.h>

float getSum(float a, float b);
float getDifference(float a, float b);
float getProduct(float a, float b);
float getQuotient(float a, float b);

int main() {
    float a, b, result;
    int operation;

    printf("Enter first number: ");
    scanf("%f", &a);
    printf("Enter second number: ");
    scanf("%f", &b);

    printf("Choose an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("Enter choice: ");
    scanf("%d", &operation);

    switch (operation) {
    case 1:
        result = getSum(a, b);
        printf("Result: %.2f\n", result);
        break;
    case 2:
        result = getDifference(a, b);
        printf("Result: %.2f\n", result);
        break;
    case 3:
        result = getProduct(a, b);
        printf("Result: %.2f\n", result);
        break;
    case 4:
        result = getQuotient(a, b);
        break;
    default:
        printf("Invalid choice. Please select from 1–4.\n");
        break;
    }

    return 0;
}

float getSum(float a, float b) {
    return a + b;
}

float getDifference(float a, float b) {
    return a - b;
}

float getProduct(float a, float b) {
    return a * b;
}

float getQuotient(float a, float b) {
    if (b == 0) {
        printf("Error: Division by zero is not allowed.\n");
        return 0;
    }
    float result = a / b;
    printf("Result: %.2f\n", result);
    return result;
}
