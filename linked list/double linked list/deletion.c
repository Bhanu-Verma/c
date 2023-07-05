#include "dll.c"

void delete(node** head, node** tail, int idx){
    if(idx==1 && ((*head)->next == NULL)){
        printf("can't delete element as the list is empty.\n");
        return;
    }else if(idx==1){
        node* new_node = *head;
        *head = new_node->next;
        new_node->next = NULL;
        free(new_node);
        return;
    }
    int c=1;
    node* temp = *head;
    while(c<idx-1){
        
        c++;
        temp=temp->next;
    }
 //  printf("%d",temp->data);
        
    if(temp->next->next == NULL){
       // printf("entered");
        node* new_node = temp->next;
        temp->next = NULL;
        new_node -> prev = NULL;
        free(new_node);
        return;
    }

    node* new_node = temp -> next;
    new_node->next->prev = temp;
    temp->next = new_node->next;
    new_node->next=new_node->prev=NULL;
    free(new_node);
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
    printf("give the index of the element that you want to delete:");
    scanf("%d",&idx);

    delete(&head, &tail, idx);
    display_direct(head);
    return 0;
}