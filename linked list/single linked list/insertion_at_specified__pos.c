#include "ll.c"

void insertion(node** head, node* new_node, int idx){
    if(idx ==0){
        new_node -> next = *head;
        *head = new_node;
        return;
    }

    node* temp = *head;
    int count = 1;
    while(count!=idx){
        temp = temp -> next;
        count++;
    }
    new_node -> next = temp -> next;
    temp -> next = new_node;
    return;
}

int main(){
    node* head = (node*) malloc(sizeof(node));
    head = NULL;
    for(int i=1; i<=10; i++){
        insert_at_tail(&head,i);
    }
    display(head);
    int idx;
    printf("give the index of the element that you want to insert:");
    scanf("%d",&idx);

    int ele;
    printf("give the element that you want to insert:");
    scanf("%d",&ele);
    node* new_node = (node*) malloc(sizeof(node));
    new_node -> data = ele;
    new_node -> next =NULL;
    insertion(&head, new_node, idx);
    display(head);
    return 0;
}