/*
Pauline has been receiving a lot of strange messages, and realized they're in reverse! Now she needs a program that can help her decode them. This program should:
1. Ask the user to input the original string to be reversed.
2. Scan the message using the fgets function (unlike scanf, fgets allows whitespace and punctuation marks to be read).
3. With a while loop, reverse the starting and ending characters of the message. Go through the whole string in this manner.
4. Print out the new message.

HINTS:
1. Use fgets instead of scanf to read the string input. 
FORMAT: fgets(destination, size, stream);
where destination = the array, size = the variable size, and stream = stdin.
2. In the while loop, use a temporary variable to help swap the starting and ending characters of the message. You may use indices to help you do so (eg. message[start/end]).  Make sure to change the indices' values after to make the loop continue!
  */

// Header file declaration
#include<stdio.h>
#include<string.h>

// Main function
int main() {
    int start = 0, end, length;
    char temp, message[50];

    printf("Enter the original string: ");
    fgets(message, sizeof(message), stdin);

    length = strlen(message);
    end = length - 1;

    while (start < end) {
        temp = message[start];
        message[start] = message[end];
        message[end] = temp;
        start++;
        end--;
    }

    printf("Reversed string: %s", message);
    return 0;
}
