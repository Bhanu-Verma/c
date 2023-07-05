#include <stdio.h>
#include <stdlib.h>

typedef struct Node node;

struct Node{
    int data;
    node* left;
    node* right;
};


void display(node* BST){
    if(BST==NULL){
        return;
    }
    display(BST->left);
    printf("%d ",BST->data);
    display(BST->right);    
}

node* insert(node* BST, int key){
    node* new_node = (node*) malloc(sizeof(node));
    new_node->data = key;
    new_node->left = NULL;
    new_node -> right = NULL;
    if(BST==NULL){
       // printf("I am NULL now\n");
        return new_node;
    }
    if(key < BST->data){
        BST -> left = insert(BST -> left, key);
    }else{
        BST -> right = insert(BST -> right, key);
    }
    return BST;
}

node* take_tree(){
    node* BST =(node*) malloc(sizeof(node));
    BST = NULL;
    int n;
    printf("give the number of elements that you want to insert:");
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        int x;
        
        scanf("%d",&x);
      
        BST=insert(BST,x);
    }
    return BST;
}

