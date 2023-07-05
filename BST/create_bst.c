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

int i_search(node* BST, int key){
    node* curr = BST;
    while(curr!=NULL){
        if(curr->data==key){
            return 1;
        }else if(curr->data < key){
            curr = curr -> right;
        }else{
            curr = curr -> left;
        }
    }
    return 0;
}

node* i_insert(node* BST, int key){
    node* curr = BST;
    node* new_node = (node*) malloc(sizeof(node));
    new_node->data = key;
    new_node->left = NULL;
    new_node -> right = NULL;

    if(curr == NULL){
        return new_node;
    }

    while(curr!=NULL){
        if((curr->data < key) && (curr->right == NULL)){
            curr -> right = new_node;
            break;
        }else if((curr->data >= key) && (curr->left == NULL)){
            curr->left = new_node;
            break;
        }
       // if(curr -> left != NULL && curr -> right != NULL){
            if(curr -> data < key){
                curr = curr ->right;
            }else{
                curr = curr -> left;
            }
       // }
    }

    return BST;
}

int search(node* BST, int key){
    if(BST==NULL){
        return 0;
    }
    if(BST->data == key){
        return 1;
    }else if(BST->data < key){
        return search(BST->right, key);
    }else{
        return search(BST->left, key);
    }
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

int main(){
    node* BST =(node*) malloc(sizeof(node));
    BST = NULL;
    int n;
    printf("give the number of elements that you want to insert:");
    scanf("%d",&n);
    printf("give the element of the tree:\n");
    for(int i=0; i<n; i++){
        int x;
        
        scanf("%d",&x);
      //  printf("x=%d\n",x);
        BST=i_insert(BST,x);
    }
    display(BST);

    printf("\n");
    printf("````````````````````````````````````````````````````````````");
    printf("\n");
    
    while(1){
        int ele;
        printf("give the element that you want to search:");
        scanf("%d",&ele);
        search(BST,ele)? printf("element is present\n"):printf("element is not present\n");
        i_search(BST,ele)? printf("element is present\n"):printf("element is not present\n");
    }
    return 0;
}