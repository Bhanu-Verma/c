#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
typedef struct cqueue cqueue; 
struct cqueue{
    int arr[SIZE];
    int f;
    int r;
    
};

void push(cqueue* q, int ele){
    if((q->f)==0 && (q->r)==SIZE-1 || (q->f)!=0 && (q->r)==(q->f-1)%(SIZE-1)){
        printf("queue is already full.\n");
        return;
    }
    if(q->f==-1 && q->r==-1){
        (q->f)++;
        (q->r)++;
        q->arr[q->f]=ele;
    }else if((q->r)==SIZE-1 && (q->f) != 0){
        (q->r)=0;
        q->arr[q->r]=ele;
    }else{
        (q->r)++;
        q->arr[q->r]=ele;
    }
}

void pop(cqueue* q){
    if(q->f==-1 && q->r==-1){
        printf("queue is empty.\n");
        return;
    }else{
        if(q->f == q->r){
             q->f=-1;
            q->r=-1;
        }
        else if(q->f == SIZE-1){
            (q->f)=0;
        }else{
            (q->f)++;
        }
    }
}




