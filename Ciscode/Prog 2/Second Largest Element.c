/* description here
*/

#include<stdio.h>

int main() {
	int i, length, largest, secondLargest;

	printf("Enter the length of the array: ");
	scanf("%d", &length);
	
	int array[length];
	
	for (i = 0; i < length; i++) {
		printf("Enter number %d: ", i+1);
		scanf("%d", &array[i]);
	}	
	
	if (array[0] > array[1]) {
		largest = array[0];
		secondLargest = array[1];
	} else {
		largest = array[1];
		secondLargest = array[0];
	}
	
	for (i = 0; i < length; i++) {
		if (array[i] > largest){
			secondLargest = largest;
			largest = array[i];
		} else if (array[i] > secondLargest && array[i] != largest) {
			secondLargest = array[i];
		} 	
	}
	
	printf("The 2nd largest element in the array is %d.", secondLargest);
	
	return 0;
}
