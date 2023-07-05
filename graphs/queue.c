#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct node1 node1;

struct node1{
    int data;
    node1* next;
};

node1* newnode(int data){
    node1* x= (node1*) malloc(sizeof(node1));
    x -> data = data;
    x -> next = NULL;
    return x;
}


struct queue{
    node1* h;
    node1* t;
};

void pop(node1** h, node1** t){
    if(h==NULL){
        printf("queue error!!!\n");
        return;
    }
    node1* temp = (*h);
    (*h) = temp->next;
    temp->next = NULL;
    free(temp);
    if((*h)==NULL){
        (*t) == NULL;
    }
}

void push(node1** h, node1** t, int val){
    node1* y = newnode(val);
    if((*h)==NULL){
        (*h) = y;
        (*t) = y;
        return;
    }

    (*t) -> next = y;
    (*t) = y;
}

int front(node1* h){
    if(h == NULL){
        printf("bhai khali ho gyi queue!");
        return -1;
    }
    return h->data;
}

bool isempty(node1* h){
    if(h==NULL){
        return true;
    }
    return false;
}

