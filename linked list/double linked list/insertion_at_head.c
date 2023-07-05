#include "dll.c"

void insert_at_head(node** head, node** tail, int x){
    node* new_node = (node*) malloc(sizeof(node));
    new_node -> data = x;
    new_node -> prev = NULL;
    new_node -> next = NULL;

    
    if(*head == NULL){
        
        *head = new_node;
        *tail = new_node;
        return;
    }

    new_node->next=*head;
    (*head)->prev = new_node;
    *head = new_node;
}

int main(){
    node* head = (node*) malloc(sizeof(node));
    head = NULL;
    node* tail = (node*) malloc(sizeof(node));
    tail = NULL;
    for(int i=1; i<=10; i++){
        
        insert_at_head(&head,&tail,i);
    }
    display_direct(head);
    
    return 0;
}