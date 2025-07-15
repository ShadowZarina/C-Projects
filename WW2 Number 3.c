#include<stdio.h>

int main(){
	//declares the pin value as 488 and attempt value at 0
	const pin = 488;
	int input, attempt = 0;

	//while loop that occurs while attempt value is less than 3
	while (attempt < 3){
		
		//ask for user's PIN input
		printf("\nEnter your PIN: ");
		scanf("%d",&input);
		
		//conditional that checks if the user's input matches actual PIN
		if (input == pin){
			//if input matches PIN, user receives success message
			printf("Success, you may now proceed...");
			return 0;
		}
		else{
			//if incorrect, the attempt value increases by 1
			attempt++; 
			if (attempt < 3){
				//user receives an error message and can reenter the PIN if attempts are still less than 3
				printf("Sorry, Wrong PIN. Please try again.");
			} 
		}
	}
	 
	//statement that is shown if 3 attempts have already been done
	//user can no longer input and the program closes
	printf("Sorry, you have entered the wrong PIN, three attempts were over.");
	return 0;
}
