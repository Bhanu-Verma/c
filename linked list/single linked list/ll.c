#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

struct node{
    int data;
    node* next;
};

void display(node* head){
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}

void insert_at_tail(node** head, int ele){
    node* new_node = (node*) malloc(sizeof(node));
    new_node->data = ele;
    new_node->next = NULL;

    if(*head == NULL){
       // printf("ENTERED\n");
        *head = new_node;
        return;
    }else{
        node* temp = *head;
        while(temp->next != NULL){
            temp = temp -> next;
        }
        temp->next = new_node;
        return;
    }
    
}
