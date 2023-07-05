#include "BST.c"

int get_max(node* BST){
    if(BST->right==NULL){
        return BST->data;
    }
    get_max(BST->right);
}

node* del(node* BST, int val){
    if(BST == NULL){
        return BST;
    }
    if(BST->data==val){
        if(BST->left == NULL && BST->right == NULL){
            free(BST);
            return NULL;
        }else{
            if(BST->right==NULL){
                node* temp = BST->left;
                BST->left = NULL;
                free(BST);
                
                return temp;
            }else if(BST->left==NULL){
                node* temp = BST->right;
                BST->right = NULL;
                free(BST);
                
                return temp;
            }else{
                int x = get_max(BST->left);
                BST->data = x;
                BST->left = del(BST->left,x);
            }
        }
    }else{
        if(val <= BST->data){
            BST->left = del(BST->left,val);
        }else{
            BST->right = del(BST->right,val);
        }
    }
}


int main(){
    node* BST = take_tree();
    display(BST);
    int ele;
    printf("give the element that you want to delete from the BST:");
    scanf("%d",&ele);
    BST = del(BST,ele);
    display(BST);
    return 0;
}