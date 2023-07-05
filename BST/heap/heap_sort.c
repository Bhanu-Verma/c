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

    int last_node = n-1;
    while(last_node >= 1){
        printf("%d %d\n",arr[1],arr[last_node]);
        int t = arr[last_node];
        arr[last_node] = arr[1];
        arr[1] = t;

        heapify(arr,1,last_node);
        last_node -= 1;
    }

    for(int i=1; i<n; i++){
        printf("%d ",arr[i]);
    }
    //printf("%d\n",n);
    return 0;
}