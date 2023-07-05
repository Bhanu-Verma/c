#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b){
    int t=*a;
    *a=*b;
    *b=t;
}

void print(int* arr, int n){
    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void input(int* arr, int n){
    for(int i=0; i<n; i++){
        scanf("%d",arr+i);
    }
}


