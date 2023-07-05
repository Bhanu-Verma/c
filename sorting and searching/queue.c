#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000
typedef struct queue queue;
struct queue{
    int arr[SIZE];
    int f;
    int r;
};

void push(queue* q,int ele){
    if(q->r==SIZE-1){
        printf("queue is already full.\n");
        return;
    }
    (q->r)++;
    q->arr[q->r]=ele;
}

void pop(queue* q){
    if(q->r == q->f){
        printf("Queue is empty.\n");
        return;
    }
    (q->f)++;
    if(q->f == q->r){
        q->f = -1;
        q->r = -1;
    }
}

void front(queue* q){
    if(q->f == q->r){
        printf("queue is empty");
        return;
    }
    printf("%d",q->arr[q->f+1]);
}

int isEmpty(queue* q){
    if(q->r == q->f){
        return 1;
    }else{
        return 0;
    }
}

void print(queue* q){
    for(int i=q->f+1; i<=q->r; i++){
        printf("%d ",q->arr[i]);
    }
    printf("\n");
}