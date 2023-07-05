#include "dll.c"

void insert_after(node** head,node** tail, node* new_node, int idx){
    if(idx == 0){
        new_node->next = *head;
        (*head)->prev = new_node;
        *head = new_node;
        return ;
    }
    
    node* temp = *head;
    
    int c=1;
    while(c!=idx){
        temp = temp->next;
        c++;
    }
    if(temp->next == NULL){
         new_node -> prev = *tail;
        (*tail) -> next = new_node;
        *tail = new_node;
        return;
    }
    new_node->next = temp->next;
    new_node->prev = temp;
    temp->next->prev = new_node;
    temp->next = new_node;
    
}

int main(){
    node* head = (node*) malloc(sizeof(node));
    node* tail = (node*) malloc(sizeof(node));
    head = NULL;
    tail = NULL;
    for(int i=1; i<=10; i++){
        insertion_at_tail(&head,&tail,i);
    }
    display_direct(head);
    int idx;
    printf("index after which you want to insert:");
    scanf("%d",&idx);

    int ele;
    printf("element that you want to insert at the position:");
    scanf("%d",&ele);
    node* new_node=(node*) malloc(sizeof(node));
    new_node->data = ele;
    new_node->next = NULL;
    new_node->next = NULL;
    insert_after(&head,&tail,new_node,idx);
    display_direct(head);
    return 0;
}