#include "ll.c"

void reverse(node** head){
    node* prev = NULL;
    node* next = NULL;
    node* curr = *head;

    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;

}

node* r_reverse(node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    node* a_list_head = r_reverse(head->next);
    insert_at_tail(&a_list_head, head->data);
    return a_list_head;
}

node* reverse_rec(node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    node* head_of_reversed_list = reverse_rec(head->next);
    head->next->next = head;
    head->next = NULL;
        return head_of_reversed_list;   
}

int main(){
     node* head = (node*) malloc(sizeof(node));
    head = NULL;

    for(int i=1; i<=9; i++){
        insert_at_tail(&head,i);
    }

    node* reversed = reverse_rec(head);
    display(reversed);
    return 0;
}