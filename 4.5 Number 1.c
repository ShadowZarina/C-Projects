#include<stdio.h>
#include<math.h>

float calcVolume(int r);

int main(){
	int r;
	printf("Enter the value of the radius: ");
	scanf("%d",&r);
	printf("The volume of the sphere is: %f",calcVolume(r));
	return 0;
}

float calcVolume(int r){
	const float PI = 3.14159;
	float result = (4.0/3.0)*PI*pow(r,3);
	return result;
}
