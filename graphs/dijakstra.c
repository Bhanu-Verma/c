// using 1 based nodes

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
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

bool check(bool st2[], int n){
    for(int i=1; i<n+1; i++){
        if(st2[i] == true){
            return true;
        }
    }
    return false;
}

int get_min(int st1[], bool st2[], int n){
    int mn = 1;
    int mn_value = INT_MAX;
    for(int i=1; i<=n; i++){
        if(st2[i]==true && st1[i]<mn_value){
            mn = i;
        }
    }
    return mn;
}

void display_dist(int dist[], int n){
    for(int i=1; i<=n; i++){
        printf("%d ",dist[i]);
    }
    printf("\n");
}

void dijakstra(node** graph, int src, int dist[], int n){
    dist[src] = 0;
    // here we are not storing the first value of our set as it is already present in dist array
    bool st2[n+1];      //I'll store true or false to know whether this node is inside or not
  
    st2[src] = true;
    
    while(check(st2,n)){
        
        int u = get_min(dist,st2,n);
        printf("min node is %d\n",u);
        st2[u] = false;
        node* x = graph[u];

        while (x!=NULL)
        {
            int v = x->data;
            int more_dist = x->data2;
            int initial_dist = dist[u];

            if(initial_dist + more_dist < dist[v]){
                dist[v] = initial_dist + more_dist;
                st2[v] = true;
                
            }

            x = x->next;
        }
        display_dist(dist,n);
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

    for(int i=1; i<=n; i++){
        printf("%d -> ",i);
        display(graph[i]);
    }

    int dist[n+1];
    for(int i=1; i<n+1; i++){
        dist[i] = INT_MAX;
    }

    dijakstra(graph,1,dist,n);
    printf("minimum distances from node 1 are:\n");
    display_dist(dist,n);
    return 0;
}


