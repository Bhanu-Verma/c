#include <stdio.h>
#include <stdlib.h>

int main(){
    int a = 5;
    int* ptr = &a;
    printf("%u",ptr);
    return 0;
}