#include "ll.c"

int main(){
    node* head = (node*) malloc(sizeof(node));
    head = NULL;
    for(int i=1; i<=5; i++){
        insert_at_tail(&head,i);
    }

    
    return 0;
}