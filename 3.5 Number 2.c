//a program that calculates distance
#include<stdio.h>
#include<math.h>
float calcDistance(float x1, float x2, float y1, float y2);

int main(){
	int x1, y1, x2, y2;
	printf("Enter the x and y coordinates of the first point: ");
	scanf("%d %d",&x1,&y1);
	printf("Enter the x and y coordinates of the second point: ");
	scanf("%d %d",&x2,&y2);
	printf("\nThe distance between the two points is %.4f",calcDistance(x1,x2,y1,y2));
	return 0;
}
float calcDistance(float x1, float x2, float y1, float y2){
	float sresult = ((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1));
	float result = sqrt(sresult);
	return result;
}

