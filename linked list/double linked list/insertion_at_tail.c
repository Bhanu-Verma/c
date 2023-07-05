#include "dll.c"

int main(){
    node* head = (node*) malloc(sizeof(node));
    node* tail = (node*) malloc(sizeof(node));
    head = NULL;
    tail = NULL;
    for(int i=1; i<=10; i++){
        insertion_at_tail(&head,&tail,i);
    }
   // printf("done");
    display_direct(head);
    return 0;
}