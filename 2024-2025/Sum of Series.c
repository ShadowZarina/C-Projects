#include <stdio.h>

int main(){
	int n, i, j, sum = 0, termSum;
	
	//ask the user to enter the nth term
	printf("Input the value for the nth term: ");
	scanf("%d", &n);
	
	printf("\n");
	
	//loop through each term in the series up to n
	for (i = 1; i <= n; i++) {
		termSum = 0; //initialize the termSum for each new row
		
		//inner loop to calculate the current term (1+2+....+i)
		for (j = 1; j <= i; j++) {
			printf("%d", j); //print each number in the term
			termSum += j; //add each number to the termSum
			
			if (j < i) {
			printf("+");  //print '+' between numbers
			}
		}
		
		//display the total for this term
		printf(" = %d\n", termSum);                        
		
		//add the term's sum to the overall series sum
		sum += termSum;
	}
	
	//print the total sum of the entire series
	printf("\nThe sum of the above series is: %d\n", sum);
	
	return 0;
}
