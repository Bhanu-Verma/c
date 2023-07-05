#include "ll.c"

int getSize(node* head){
    node* temp = head;
    int size=0;
    while(temp!=NULL){
        size++;
        temp=temp->next;
    }
    printf("size of linked list is : %d\n",size);
    return size;
}

void delete_middle(node** head, int size){
    node* temp = *head;
    if(size==0){
        return;
    }
    if(size%2==0){
        size = size/2;
        int i=1;
        while(i!=size-1){
            temp=temp->next;
            i++;
        }
        node* node1 = temp->next;
        node* node2 = node1->next;
        temp->next = node2->next;
        node2->next = NULL;
        node1->next = NULL;
        free(node1);
        free(node2);
    }else{
        size = (size+1)/2;
        int i=1;
        while(i!=size-1){
            temp = temp -> next;
            i++;
        }
        node* ex = temp -> next;
        temp -> next = temp -> next -> next;
        ex -> next = NULL;
        free(ex);
    }
}

int main(){
    node* head = (node*) malloc(sizeof(node));
    head = NULL;

    for(int i=1; i<=4; i++){
        insert_at_tail(&head,i);
    }

    int size = getSize(head);
    delete_middle(&head, size);
    display(head);
    return 0;
}