#include <stdio.h>
#include <stdlib.h>

void print(int* arr, int n){
    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int min(int a, int b){
    return (a<b)?a:b;
}

void merge(int* arr, int l, int mid, int e){
    int n1=mid-l+1;
    int n2=e-mid;
    int* arr1=(int*) calloc(n1,sizeof(int));
    int* arr2=(int*) calloc(n2,sizeof(int));
    for(int i=0; i<n1; i++){
        arr1[i]=arr[l+i];
    }
    for(int i=0; i<n2; i++){
        arr2[i]=arr[mid+1+i];
    }
    print(arr1,n1);
    print(arr2,n2);

    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            arr[k++]=arr1[i++];
        }else{
            arr[k++]=arr2[j++];
        }
    }
    while(i<n1){
        arr[k++]=arr1[i++];
    }
    while(j<n2){
        arr[k++]=arr2[j++];
    }
    free(arr1);
    free(arr2);
}

void mergesort(int* arr, int n){
    int len=1;
    while(len<n){
        int s=0;
        
        for( ; s<n-1; s+=2*len){
            int mid=min(n-1,s+len-1);
            int e=min(n-1,s+2*len-1);
            merge(arr,s,mid,e);
        }
        print(arr,n);
        len*=2;
    }
}

int main(){
    int n;
    printf("enter the number of elements in the array:\n");
    scanf("%d",&n);

    int* arr=(int*) calloc(n,sizeof(int));
    printf("enter the elements of the array:\n");
    for(int i=0; i<n; i++){
        scanf("%d",arr+i);
    }
    mergesort(arr,n);
    printf("array after sorting:\n");
    print(arr,n);
    free(arr);

    return 0;
}