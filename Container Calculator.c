/*
=======================================================================================
AUTHORS : Taparan, Jecho and To Chip, Andrea
DESCRIPTION  : Computes the number of containers needed for different volumes of Fruit Salad
CREATION DATE  : 10/16/24
=======================================================================================
*/

//import source file
#include<stdio.h>
//declare functions 1 and 2
int doCompute(int a, int b);
int computeRemainder(int a, int b);

//Main Function
int main(){
//Declare variables
	int nineCups, sixCups, threeCups, oneCup, cups, remainderNineCups, remainderSixCups;
//Asking for input of amount of fruit salad in cups from User
	printf("Enter desired amout of Fruit Salad in cups: ");
	scanf("%d",&cups);
//Calculate the value of each variable using Function 1 and 2
	nineCups = doCompute(cups,9);
	remainderNineCups = computeRemainder(cups,9);
	sixCups = doCompute(remainderNineCups,6);
	remainderSixCups = computeRemainder(remainderNineCups,6);
	threeCups = doCompute(remainderSixCups,3);
	oneCup = computeRemainder(remainderSixCups,3);
//Print the results
	printf("\nNumber of Containers for 9 cups: %d\nNumber of Containers for 6 cups: %d\nNumber of Containers for 3 cups: %d\nNumber of Containers for 1 cup: %d", nineCups, sixCups, threeCups, oneCup);
	return 0;
	}
//Function to divide integers a and b
int doCompute(int a, int b){
	return a/b;
}
//Function to find the remainder of integers a and b
int computeRemainder(int a, int b){
	return a%b;
}

