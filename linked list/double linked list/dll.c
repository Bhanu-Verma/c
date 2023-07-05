#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

struct node{
    int data;
    node* prev;
    node* next;
};

void insertion_at_tail(node** head, node** tail, int x){
    node* new_node = (node*) malloc(sizeof(node));
    new_node -> data = x;
    new_node -> prev = NULL;
    new_node -> next = NULL;
    if(*head == NULL){
        //printf("entered\n");
        *head = new_node;
        *tail = new_node;
    }
   
    new_node -> prev = *tail;
    (*tail) -> next = new_node;
    *tail = new_node;
   // printf("conplete\n");
    return;
}

void display_direct(node* head){
    while(head!=NULL){
        printf("%d ",head->data);
        head = head -> next;
    }
    printf("\n");
}

void display_reverse(node* tail){
    while(tail!=NULL){
        printf("%d ",tail->data);
        tail = tail->prev;
    }
    printf("\n");
}