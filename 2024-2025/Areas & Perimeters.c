A program that calculates area and perimeter
#include<stdio.h>
int calcArea(int x, int y);
int calcPerimeter(int x, int y);

int main(){
	int x, y;
	printf("Enter the length and width: ");
	scanf("%d, %d",&x,&y);
	printf("\nThe area of the rectangle is %d",calcArea(x,y));
	printf("\nThe perimeter of the rectangle is %d",calcPerimeter(x,y));
	return 0;
}
int calcArea(int x, int y){
	int result = x*y;
	return result;
}
int calcPerimeter(int x, int y){
	int result = 2*x + 2*y;
	return result;
}
