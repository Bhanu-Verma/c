#include <stdio.h>
#include <stdlib.h>
typedef struct Node node;

struct Node
{
    int data;
    node* left;
    node* right;
    int size;
};

int max(int a, int b){
    if(a>=b) return a;
    else return b;
}

int sz(node* x){
    if(x==NULL) return 0;
    else return x->size;
}


node* rr_rotate(node* y){
    printf("called rr\n");
    if(y==NULL){
        return NULL;
    }
    node* x = y->right;
    node* t2 = x->left;

    x->left = y;
    y->right = t2;

    y->size = 1+max(sz(y->left),sz(y->right));
    x->size = 1+max(sz(x->left),sz(x->right));
    return x;
}

node* ll_rotate(node* y){
    printf("called ll\n");
    if(y==NULL){
        return NULL;
    }
    node* x = y->left;
    node* t2 = x->right;
    
    x->right = y;
    y->left = t2;

    y->size = 1+max(sz(y->left),sz(y->right));
    x->size = 1+max(sz(x->left),sz(x->right));
    return x;
}

node* insert(node* Atree, int x){
    node* new_node = (node*) malloc(sizeof(node));
    new_node->data = x;
    new_node->left = NULL;
    new_node -> right = NULL;
    new_node -> size = 1;
    if(Atree == NULL){
        printf("entered\n");
        return new_node;
    }
        
    if(x <= Atree->data){
        Atree->left = insert(Atree->left,x);
    }else{
        printf("I am also called\n");
        Atree->right = insert(Atree->right,x);
    }

    Atree->size = max(sz(Atree->left),sz(Atree->right))+1;
    int b = sz(Atree->left) - sz(Atree->right);

    if(b>=-1 && b<=1){
        return Atree;
    }
    else if(b<-1 && x > Atree->right->data){
        return rr_rotate(Atree);
    }else if(b<-1 && x <= Atree->right->data){
        Atree->right=ll_rotate(Atree->right);
        return rr_rotate(Atree);
    }else if(b>1 && x < Atree->left->data){
        return ll_rotate(Atree);
    }else if(b>1 && x >= Atree->left->data){
        Atree->left = rr_rotate(Atree->left);
        return ll_rotate(Atree);
    }
    
}

void inorder(node* Atree){
    if(Atree == NULL){
        return;
    }

    inorder(Atree->left);
    printf("%d ",Atree->data);
    inorder(Atree->right);
}

int main(){
    node* Atree = (node*) malloc(sizeof(node));
    Atree = NULL;
    int n;
    printf("Give the number of elements that you want to insert in the tree:");
    scanf("%d",&n);
    printf("give the elements of the tree\n");
    
    for(int i=0; i<n; i++){
        int x;
        scanf("%d",&x);
        Atree = insert(Atree,x);
        inorder(Atree);
    }
    
    return 0;
}