#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Node node;



struct Node{
    int data;
    int data2;
    node* next;
};


void display(node* head){
    if(head == NULL){
        printf("\n");
        return;
    }

    while(head!=NULL){
        printf("[%d %d]",head->data,head->data2);
        head = head -> next;

    }
    printf("\n");
}

void insert_at_tail(node** head, int ele, int ele2){
    node* new_node = (node*) malloc(sizeof(node));
    new_node->data = ele;
    new_node->data2 = ele2;
    new_node->next = NULL;

    if(*head == NULL){
       // printf("ENTERED\n");
        *head = new_node;
        return;
    }else{
        node* temp = *head;
        while(temp->next != NULL){
            temp = temp -> next;
        }
        temp->next = new_node;
        return;
    }
    
}

int main(){
    int type;
    printf("enter 0 of undirected and 1 for directed graph:");
    scanf("%d",&type);

    
    int n;
    printf("enter number of nodes in the graph:");
    scanf("%d",&n);
    node** graph = (node**) calloc(n+1,sizeof(node*));
    for(int i=0; i<n+1; i++){
        graph[i] = (node*) malloc(sizeof(node));
        graph[i] = NULL;
    }
    

    int e;
    printf("enter the number of edges in the graph:");
    scanf("%d",&e);
    printf("enter the information about the nodes:");
    for(int i=0; i<e; i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        if(type == 0){
            insert_at_tail(&graph[u],v,w);
            insert_at_tail(&graph[v],u,w);
        }else{
            insert_at_tail(&graph[u],v,w);
        }
    }

    // node* head = (node*) malloc(sizeof(node));
    // head = NULL;

    // for(int i=1; i<=9; i++){
    //     insert_at_tail(&head,i);
    // }

    // graph[1] = head;

    for(int i=1; i<=n; i++){
        printf("%d -> ",i);
        display(graph[i]);
    }

    // display(graph[1]);
    return 0;
}