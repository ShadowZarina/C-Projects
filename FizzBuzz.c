#include<stdio.h>

int main(){
    int num;
    printf("Enter a number: ");
    scanf("%d",&num);
    
    if ((num % 15 == 0){
		printf("\nFIZZBUZZ");
	}
	else if (num % 3 == 0){
		printf("\nFIZZ");
	}
	else if (num % 5 == 0){
		printf("\nBUZZ");
	}
	else{
		printf("\n%d",num);
	}
    return 0;
}

