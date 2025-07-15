//a program that calculates squares and cubes
#include<stdio.h>
int calcSquare(int x);
int calcCube(int x);

int main(){
	int x;
	printf("Enter an integer: ");
	scanf("%d",&x);
	printf("\nThe integer squared is %d",calcSquare(x));
	printf("\nThe integer cubed is %d",calcCube(x));
	return 0;
}
int calcSquare(int x){
	int result = x*x;
	return result;
}
int calcCube(int x){
	int result = x*x*x;
	return result;
}
