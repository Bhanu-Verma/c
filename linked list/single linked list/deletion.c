#include "ll.c"

void deletion(node** head, int idx){
    node* temp = *head;
    int count = 1;
    while(count!=idx-1){
        temp = temp -> next;
        count++;
    }
    node* ex = temp -> next;
    temp -> next = temp -> next -> next;
    ex -> next = NULL;
    free(ex);
}

int main(){
    node* head = (node*) malloc(sizeof(node));
    head = NULL;
    for(int i=1; i<=10; i++){
        insert_at_tail(&head,i);
    }
    int idx;
    printf("give the index of the element that you want to delete:");
    scanf("%d",&idx);
    deletion(&head, idx);
    display(head);
    return 0;
}