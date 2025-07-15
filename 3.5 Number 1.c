#include<stdio.h>

int main(){
	char FName[20];
	char MName[20];
	char SName[20];
	printf("Enter your First Name: ");
	gets(FName);
	printf("Enter your Middle Name: ");
	gets(MName);
	printf("Enter your Family Name: ");
	gets(SName);
	
	printf("\n%s, %s %s",SName,FName,MName);
	
	printf("\n\n%s \n%s \n%s",FName,MName,SName);
		
	printf("\n\n%s, \n%s %s",SName,FName,MName);
	return 0;
}
