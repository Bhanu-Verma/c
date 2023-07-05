#include <stdio.h>
#include <stdlib.h>
typedef struct Node node;

struct Node
{
    int data;
    node* next;
};

node* Newnode(int key){
    node* t = (node*) malloc(sizeof(node));
    t->data = key;
    t->next = NULL;
    return t;
}

void display(node* head){
    printf("%d ",head->data);
    node* temp = head -> next;
    while(temp!=head){
        printf("%d ",temp->data);
        temp = temp -> next;
    }
    printf("\n");
}

void insert(node** head, int x){
    node* new_node = Newnode(x);
    if(*head == NULL){
        *head = new_node;
        new_node -> next = *head;
        return;
    }
    node* temp = *head;
    while(temp->next != *head){
       // printf("entered\n");
        temp = temp -> next;
    }
    temp->next = new_node;
    new_node->next = *head;
}

void search(node* head, int key){
    if(head == NULL){
        printf("element not found in the linked list\n");
        return;
    }
    node* temp = head;
    if(temp->data == key){
        printf("element found in the linked list\n");
        return;
    }
    temp = temp -> next;
    while(temp!=head){
        if(temp -> data == key){
            printf("element found in the linked list\n");
            return;
        }else{
            temp = temp -> next;
        }
    }
    printf("element not found in the linked list\n");
}

void del(node** head, int x){
    if(*head == NULL){
        printf("linked list is already empty\n");
        return;
    }
    node* temp = *head;
    if((*head)->data== x){
        while(temp->next!=*head){
            temp = temp->next;
        }
        temp->next = (*head)->next;
        (*head)->next = NULL;
        *head = temp->next;
       // free(*head);
       return;
    }   

    while(temp->next->data!=x){
        temp = temp->next;
    }
    node* c = temp->next;
    temp->next = c->next;  
    c->next = NULL; 
    free(c);
    return;
}

int main(){
    node* head = (node*) malloc(sizeof(node));
    head = NULL;
    int n;
    printf("Enter the number of elements that you want to insert in the circular linked list:");
    scanf("%d",&n);
    printf("enter the elements of the linked list:\n");
    for(int i=0; i<n; i++){
        int x;
        scanf("%d",&x);
        insert(&head,x);
    }
    display(head);
    int key;
    printf("give the element to be searched in the linked list\n");
    scanf("%d",&key);
    search(head,key);
    int x;
    printf("give the element to be deleted:\n");
    scanf("%d",&x);
    del(&head,x);
    display(head);
    return 0;
}
