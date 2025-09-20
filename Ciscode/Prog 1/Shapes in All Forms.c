/*
Kino is working with 4 different shapes: squares, rectangles, triangles and circles. He doesn't want to mix the formulas up, so he's creating a program that can find the areas for all of these shapes without having to switch between different calculators. This program should:

1. Ask the user to choose which type of shape they are solving for. 
2. Using a switch-case statement, allow the user to input in the required measurements for their chosen shape.
3. Calculate for the area of the chosen shape accordingly.
4. Output the area of the user's chosen shape.

NOTE: You may choose to use functions to calculate each type of shape's area or do it all in the main function.

FORMULAS:
1. Square = side^2
2. Rectangle = length * width
3. Triangle = (1/2) * base * height
4. Circle = 3.14 * radius^2
*/

// Header file declaration
#include<stdio.h>

// Main function
int main() {
    
    // Variable declarations
    float result;
    int choice;

    // Printf and scanf statements 
    printf("Choose a shape:\n");
    printf("1. Square\n");
    printf("2. Rectangle\n");
    printf("3. Triangle\n");
    printf("4. Circle\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Switch case statement to determine type of shape
    switch (choice) {
        case 1:
            int side;
            printf("Enter the length of one side: ");
            scanf("%d", &side);
            result = side*side;
            printf("The area of the square is %.2f.", result);
            break;
        case 2:
            int length, width;
            printf("Enter the length of the rectangle: ");
            scanf("%d", &length);
            printf("Enter the width of the rectangle: ");
            scanf("%d", &width);
            result = length*width;
            printf("The area of the rectangle is %.2f.", result);
            break;
        case 3:
            int base, height;
            printf("Enter the base of the triangle: ");
            scanf("%d", &base);
            printf("Enter the height of the triangle: ");
            scanf("%d", &height);
            result = 0.5*base*height;
            printf("The area of the triangle is %.2f.", result);
            break;
        case 4:
            int radius;
            printf("Enter the radius of the circle: ");
            scanf("%d", &radius);
            result = 3.14 * radius * radius;
            printf("The area of the circle is %.2f.", result);
            break;
        default:
            break;
    }
    
    return 0;
}
