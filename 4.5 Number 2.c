#include<stdio.h>
#include<math.h>

int calcSum(int x,int y);
int calcDifference(int x,int y);
int calcProduct(int x,int y);
int calcQuotient(int x,int y);

int main(){
	int x,y;
	printf("Enter the values of the first integer: ");
	scanf("%d",&x);
	x = abs(x);
	printf("Enter the values of the second integer: ");
	scanf("%d",&y);
	y = abs(y);
	printf("\nThe sum of the integers is %d",calcSum(x,y));
	printf("\nThe difference of the integers is %d",calcDifference(x,y));
	printf("\nThe product of the integers is %d",calcProduct(x,y));
	printf("\nThe quotient of the integers is %d",calcQuotient(x,y));
	return 0;
}

int calcSum(int x,int y){
	int sum = x+y;
	return sum;
}

int calcDifference(int x,int y){
	int difference = x-y;
	return difference;
}

int calcProduct(int x,int y){
	int product = x*y;
	return product;
}

int calcQuotient(int x,int y){
	int quotient = x/y;
	return quotient;
}
