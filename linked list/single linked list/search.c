#include "ll.c"

int search(node* head, int key){
    int ans = 0;
    while(head!=NULL){
       // printf("entered");
        if(head -> data == key){
            return ans;
            
        }
        ans++;
        head = head -> next;
    }
    return -1;
}

int main(){
    node* head = (node*) malloc(sizeof(node));
    head = NULL;
    for(int i=1; i<=10; i++){
        insert_at_tail(&head,i);
    }

    display(head);
    int key;
    printf("enter the element that you want to be searched:");
    scanf("%d",&key);
    int index = search(head, key);
    if(index == -1){
        printf("Element is not present.\n");
    }else{
        printf("Element is present at the index %d\n",index);
    }
    return 0;
}