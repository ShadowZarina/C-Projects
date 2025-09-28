/*
Elrick works with combinations and permutations every day, so he wants to use a factorial calculator to make his studies easier. This factorial calculator should:
1. Ask the user to input the number they want to get the factorial of.
2. Calculate the factorial of the number using a for loop.
3. Output the result.

FORMULA:
n! = n × (n-1) × (n-2) × ... × 1
Example: 
5! = 5 x 4 x 3 x 2 x 1 = 120
*/


// Header file declaration
#include<stdio.h>

// Main function
int main() {
	int num = 1, i, n;

	printf("Enter a number: ");
	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		num *= i;
	}

	printf("The factorial for %d (%d!) is %d.", n, n, num);
	
	return 0;
}
