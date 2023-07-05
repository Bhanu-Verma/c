//name - Bhanu Verma
//CSE B.Tech.
//Roll no.-22075021
//S. No. - 21

#include <stdio.h>
#include <stdlib.h>
            /*function to swap the two array elements*/
void swap(int* a, int* b){
    int t=*a;
    *a=*b;
    *b=t;
}


            /*function to print the content of the array*/
void print(int* arr, int n){
    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int pivot(int* arr, int s, int e){
    //here we are taking the last element as the pivot element
    int pivot=arr[e];
    int i=s-1;
    for(int j=s; j<e; j++){
        if(arr[j]<pivot){
            i++;
            swap(arr+i,arr+j);
        }
    }
    swap(arr+i+1, arr+e);
    return i+1;
}

void quick_sort(int* arr, int s, int e){
    //base case
    if(s>=e){
        return;
    }
    //call for pivot function-
    int p=pivot(arr,s,e);   
    //recursive call for quick_sort function
    quick_sort(arr,s,p-1);
    quick_sort(arr,p+1,e);
}

int main(){
    int n;                  
    printf("enter the number of elemens in the array:\n");
    scanf("%d",&n);


    int* arr=(int*) calloc(n,sizeof(int));                  //declaration of array dynamically
    printf("enter the elements of the array:\n");
    for(int i=0; i<n; i++){
        scanf("%d",arr+i);                  //taking input of array element
    }


    printf("\n\narray before applying the quick sort:\n");
    print(arr,n);


    quick_sort(arr,0,n-1);          //call for the function of merge sort 


    printf("\n\narray after applying the quick sort:\n");
    print(arr,n);
    return 0;
}