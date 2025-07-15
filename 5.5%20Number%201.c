#include<stdio.h>

int main(){
    int a = 5, b = 5, c = 10, result;
    
    //(a == b) = True AND (c > b) = True, therefore result = 1
    result = (a == b) && (c > b);
    printf("(a == b) && (c > b) is %d\n", result); 
    
    //(a == b) = True AND (c < b) = False, therefore result = 0
    result = (a == b) && (c < b);
    printf("(a == b) && (c < b) is %d\n", result); 
    
    //(a == b) = True OR (c < b) = False, therefore result = 1
    result = (a == b) || (c < b);
    printf("(a == b) || (c < b) is %d\n", result); 
    
    //(a != b) = False OR (c < b) = False, therefore result = 0
    result = (a != b) || (c < b);
    printf("(a != b) || (c < b) is %d\n", result); 
    
    //!(a != b) = NOT False, therefore result = 1
    result = !(a != b);
    printf("!(a != b) is %d\n", result); 
    
    //!(a == b) = NOT True, therefore result = 0
    result = !(a == b);
    printf("!(a == b) is %d\n", result); 
    
    return 0;
}
