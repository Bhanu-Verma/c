#include "ll.c"

void sort(node** head){
    int size = 0;
    node* temp = *head;
    while(temp != NULL){
        temp = temp -> next;
        size++;

    }
    node* temp2 = *head;
    printf("sizeof the linked list is %d\n",size);
    int count = 1;
    while(count<=size-1){
       // printf("entered");
        temp2 = *head;
        int j=0;
        while(j<size-count){
            if((temp2->data)>(temp2->next->data)){
              //  printf("good");
                int t = temp2 ->data;
                temp2->data = temp2 ->next ->data;
                temp2 ->next ->data = t;
            }
            temp2 = temp2 -> next;
            j++;
        }

        count++;
    }
}

int main(){
    node* head =(node*) malloc(sizeof(node));
    head = NULL;
    int n;
    printf("Enter the number of elements that you want to insert in ll:");
    scanf("%d",&n);
    printf("Enter elements of the linked list:\n");
    for(int i=0; i<n; i++){
        int ele;
        scanf("%d",&ele);
        insert_at_tail(&head, ele);
    }

    sort(&head);
    printf("sorted linked list is:\n");
    display(head);
    return 0;
}