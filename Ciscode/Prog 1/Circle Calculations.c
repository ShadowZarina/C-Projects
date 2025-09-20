/*
Nico needs to draw circles to create circuit boards, however he needs to make sure they are absolutely perfect! He wants to calculate the perimeter and area of every circle he draws before he proceeds.

The program should:
1. Ask the user to input a radius length.
2. Check if the radius is valid. If the input is less than or equal to 0, print an error message.
3. Calculate  the circumference of the circle.
4. Calculate  the area of the circle.
5. Print the circumference and area of the circle.

FORMULAS:

1. Circumference
C=2πr
where π = 3.14 and r = radius

2. Area
A=πr^2
where π = 3.14 and r = radius
*/

// Header file declaration
#include<stdio.h>

// Main function
int main() {
    // Variable declarations
    int radius;
    float circumference, area;

    // Insert printf and scanf statements here...
    printf("Enter the length of the radius: ");
    scanf("%d", &radius);

    // Insert if statement to check for errors...
    if (radius <= 0) {
        printf("Invalid value. Please enter a different radius length.");
    }

    // Insert calculations here...
    circumference = 2 * 3.14 * radius;
    area = 3.14 * radius * radius;

    // Insert printf statements here...
    printf("The circumference of the circle is %.2f\n", circumference);
    printf("The area of the circle is %.2f", area);

    return 0;
}
