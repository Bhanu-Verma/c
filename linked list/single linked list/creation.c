#include "ll.c"


int main(){
    node* head=(node*) malloc(sizeof(node));
    head=NULL;
    while(1){
        int choice;
        printf("give 1 if you want to input:");
        scanf("%d",&choice);
        if(choice!=1){
            break;
        }else{
            int ele;
            printf("give the number that you want to insert:");
            scanf("%d",&ele);
            insert_at_tail(&head,ele);
        }
    }
    display(head);
    return 0;
}