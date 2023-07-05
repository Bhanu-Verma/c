#include "ll.c"

void insert_at_head(node** head, int val){
    node* new_node = (node*) malloc(sizeof(node));
    new_node->data = val;
    new_node->next = NULL;

    if(*head == NULL){
        *head = new_node;
    }else{
        new_node->next = *head;
        *head = new_node;
    }
}

int main(){
    node* head = (node*) malloc(sizeof(node));
    head = NULL;

    for(int i=1; i<=10; i++){
        insert_at_head(&head,i);
    }
    display(head);
    return 0;
}