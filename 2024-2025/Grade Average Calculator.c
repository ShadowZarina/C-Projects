#include<stdio.h>

int main() {
	int phys, chem, bio, math, comp, total;
	float average;
	
	printf("Enter your Physics marks: ");
	scanf("%d", &phys);
	printf("Enter your Chemistry marks: ");
	scanf("%d", &chem);
	printf("Enter your Biology marks: ");
	scanf("%d", &bio);
	printf("Enter your Mathematics marks: ");
	scanf("%d", &math);
	printf("Enter your Computer marks: ");
	scanf("%d", &comp);
	
	if (phys < 0 || phys > 100 || chem < 0 || chem > 100 || bio < 0 || bio > 100 || math < 0 || math > 100 || comp < 0 || comp > 100) {
	printf("\nERROR: Kindly enter marks between 0 and 100.");
	return 1;
	}
	
	total = phys + chem + bio + math + comp;
	average = total / 5;
	
	printf("\nAverage Marks: %.1f%%", average);
	
	if (average >= 90) {
	printf("\nGrade Criteria: Excellent");
	} else if (average >= 80) {
	printf("\nGrade Criteria: Very Good");
	} else if (average >= 70) {
	printf("\nGrade Criteria: Good");
	} else if (average >= 60) {
	printf("\nGrade Criteria: Fair");
	} else if (average >= 40) {
	printf("\nGrade Criteria: Poor");
	} else {
	printf("\nGrade Criteria: Fail");
	}

return 0;
}
