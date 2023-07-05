#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



int main(){
    int type;
    printf("enter 0 of undirected and 1 for directed graph:");
    scanf("%d",&type);


    int n;
    printf("enter number of nodes in the graph:");
    scanf("%d",&n);
    int** graph = (int**) calloc(n+1,sizeof(int*));
    for(int i=0; i<n+1; i++){
        graph[i] = (int*) calloc(n+1,sizeof(int));
    }


    int e;
    printf("enter the number of edges in the graph:");
    scanf("%d",&e);
    printf("enter the information about the nodes:");
    for(int i=0; i<e; i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        if(type==0){
            graph[u][v] = w; 
        }else{
             graph[u][v] = w; 
             graph[v][u] = w;
        }
    }

    for(int i=1; i<n+1; i++){
        printf("%d ->",i);
        for(int j=1; j<n+1; j++){
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
    return 0;
}