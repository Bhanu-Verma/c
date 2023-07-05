#include <stdio.h>
#include <stdlib.h>

void heapify(int arr[], int i, int n){
    int largest = i;
    int l = 2*i;
    int r = 2*i+1;

    if(l<n && arr[l]>arr[largest]){
        largest = l;
    }
    if(r<n && arr[r]>arr[largest]){
        largest = r;
    }
    if(largest != i){
        int t = arr[largest];
        arr[largest] = arr[i];
        arr[i] = t;
        heapify(arr,largest,n);
    }
}
        


int main(){
    int arr[]={-1,3,4,5,6,56,13,14};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i=n/2; i>0; i--){
        heapify(arr,i,n);
    }

    for(int i=1; i<n; i++){
        printf("%d ",arr[i]);
    }
    //printf("%d\n",n);
    return 0;
}