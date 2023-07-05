#include<stdio.h>
#include<stdlib.h>
typedef struct node node;
struct node{
    int data;
    node* next;
};

void push(node** head, int val){
    if(*head==NULL){
        node* new_node=(node*) malloc(sizeof(node));
        new_node->data=val;
        new_node->next=NULL;
        *head=new_node;
    }else{
        node* new_node=(node*) malloc(sizeof(node));
        new_node->data=val;
        new_node->next=NULL;
        new_node->next=*head;
        *head=new_node;
    }
}

void pop(node** head){
    if(head==NULL){
        printf("can't pop from the stack.\n");
        return;
    }else{
        node* temp =(node*) malloc(sizeof(node));
        temp=*head;
        *head=temp->next;
        temp->next=NULL;
        free(temp);
    }
}

void print(node* temp){
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main(){
    node* head=(node*) malloc(sizeof(node));
    head=NULL;

    for(int i=1; i<=10; i++){
        push(&head,i);
    }
    pop(&head);
    pop(&head);
    print(head);
    return 0;
}