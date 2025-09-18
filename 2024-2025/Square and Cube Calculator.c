#include<stdio.h>
#include<math.h>

int calcSquare(int x);
int calcCube(int x);

int main(){
	int x;
	printf("Enter your number: ");
	scanf("%d",&x);
	printf("The number squared is %d",calcSquare(x));
	printf("\nThe number cubed is %d",calcCube(x));
	return 0;
}

int calcSquare(int x){
	int square = pow(x,2);
	return square;
}

int calcCube(int x){
	int cube = pow(x,3);
	return cube;
}
