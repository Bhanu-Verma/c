#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
typedef struct Node node;


struct edge{
    int u;
    int v;
    int w;
};

void make(int n, int parent[], int size[]){
    for(int i=0; i<n; i++){
        parent[i]=i;
        size[i] = 1;
    } 
}

int find(int x, int parent[], int size[]){
    if(x==parent[x]) return x;
    return parent[x] = find(parent[x],parent,size);
}

int Union(int a, int b, int parent[], int size[]){
    a = find(a,parent,size);
    b = find(b,parent,size);
    if(size[a] < size[b]){
        int t = b;
        b = a;
        a = t;
    }

    parent[b] = a;
    size[a] += size[b];
}

int comparator(const void* p1, const void* p2)
{
    int l = ((struct edge*) p1) -> w;
    int r = ((struct edge*) p2) -> w;

    return (l-r);
}

int main(){
    
    int n;
    printf("enter the number of vertices in the graph: ");
    scanf("%d",&n);

    //to store the information of the mst
    int parent[n];
    int size[n];


    int e;
    printf("enter the number of edges in the graph: ");
    scanf("%d",&e);
    struct edge edges[e];
    printf("give the information about the edges of the graph:\n");
    for(int i=0; i<e; i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        edges[i].u = u;
        edges[i].v = v;
        edges[i].w = w;
    }
    //sort the edges
    qsort((void*) edges, e, sizeof(edges[0]), comparator);
    //check if they have been sorted or not
    for(int i=0; i<e; i++){
        printf("%d ",edges[i].u);
        printf("%d ",edges[i].v);
        printf("%d ",edges[i].w);
        printf("\n");
    }
    make(n,parent,size);
    for(int i=0; i<e; i++){
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;
        if(find(u,parent,size) == find(v,parent,size)){
            continue;
        }
        else{
           Union(u,v,parent,size);
           printf("%d %d\n",u,v);
        }
    }

    return 0;
}