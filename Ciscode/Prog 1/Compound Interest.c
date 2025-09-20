/*
Uziah is thinking of saving money in the bank for some extra income, however he wants to make sure he understands exactly how much he can gain before he even invests his hard-earned cash. He plans to do this through a compound interest calculator. 

The calculator should:
1. Ask for the total amount to be invested (principal),  the annual interest rate (rate; this should be turned into a decimal), the number of times compounded (periods) , and time the money is invested (time).
2. Calcuate for the future value of the investment using the formula (find the value of A as written below the instructions). 

NOTE: You may use the pow() function from math.h to handle exponents.

3. Print out the future value of the investment (future) at the end of the main function.


FORMULA FOR COMPOUND INTEREST:
A = P(1 + r/n)^(nt)

A = future value of the investment/loan
P = principal amount (the initial investment/loan amount)
r = annual interest rate (as a decimal)
n = number of times that interest is compounded per year 
t = number of years the money is invested or borrowed for
*/

// Header file declaration
#include<stdio.h>
#include<math.h>

// Main function
int main() {
    // Variable declarations
    float principal, rate, time, future;
    int periods;

    // Insert printf and scanf statements here...
    printf("Enter the principal amount: ");
    scanf("%f", &principal);
    printf("Enter the annual interest rate (%): ");
    scanf("%f", &rate);
    printf("Enter the number of times the interest will be compounded annually: ");
    scanf("%d", &periods);
    printf("Enter the time (years): ");
    scanf("%f", &time);
    
    // Insert if statement to check if periods is equal to 0
    if (periods == 0) {
        return 0;
    }

    // Convert the interest rate to a decimal here...
    rate *= 0.01;

    // Compound interest formula here...
    future = principal * pow((1 + rate/periods),(time * periods));

    // Insert final printf statement here...
    printf("After %.2f years, the future value of the investment would be %.2f", time, future);

    return 0;
}
