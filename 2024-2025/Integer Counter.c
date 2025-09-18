#include<stdio.h>

int main(){
	int i, integer, positive = 0, negative = 0, zero = 0;
	   
	//asks for input of 10 integers from user
	printf("Enter 10 integers:\n");
	//for loop that goes through integers 1-10
	for (i=0; i<10; i++){
		//asks for input of user for each integer one-by-one
		//increments i by 1 after every runthrough
	   	printf("Number %d: ", i + 1);
	   	scanf("%d",&integer);
	   	
	   	if (integer > 0){
	   		//positive is incremented if the integer is positive
	   		positive++;
		}	else if (integer < 0){
			//negative is incremented if the integer is negative
			negative++;
		} else {
			//zero is incremented if the integer is zero
			zero++;
		}
}
	//print the number of postitive, negative and zero integers
	printf("\nNumber of positive integers: %d\n",positive);
	printf("Number of negative integers: %d\n",negative);
	printf("Number of zeroes: %d",zero);
	
	return 0;
}  
