#include <stdio.h>
#include <stdlib.h>
typedef struct pq priority_queue;
struct pq{
    int arr[100];
    int idx;
};


void heapify_bottomup(int arr[], int i, int n){
    int par = i/2;
    if(par<1){
        return;
    }

    
    if(arr[par] < arr[i]){
        int t = arr[i];
        arr[i] = arr[par];
        arr[par] = t;
        heapify_bottomup(arr,par,n);
    }
}

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
  
void display_heap(int* arr, int n){
    for(int i=1; i<n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    priority_queue* p = (priority_queue*) malloc(sizeof(priority_queue));
    (p->arr)[0] = -1;
    p->idx = 1;
    int n;
    printf("give the number of elements that you want to insert in pq: ");
    scanf("%d",&n);
    printf("give the elements that you wnat to insert in the priority queue:\n");
    for(int i=0; i<n; i++){
        int x;
        scanf("%d",&x);
        (p->arr)[p->idx] = p->arr[1];
        p->arr[1] = x;
        int index = p->idx;
        while(index>1){
            int par = index/2;
            if(p->arr[index] > p->arr[par]){
                int t = p->arr[index];
                p->arr[index] = p->arr[par];
                p->arr[par] = t;
                heapify_bottomup(p->arr,par,n);
            }
            else{
                break;
            }
        }

        p->idx += 1;
        display_heap(p->arr,p->idx);
    }

    printf("deleting all the elements one by one:\n");
    while((p->idx)>1){
        //swap the elements
        int t = p->arr[1];
        p->arr[1] = p->arr[p->idx-1];
        p->arr[p->idx-1] = t;
        //decrease size
        p->idx -=1;
        heapify(p->arr,1,p->idx);
        display_heap(p->arr,p->idx);
    }

    return 0;
}
 