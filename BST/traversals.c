#include "BST.c"

void postorder(node* BST){
    if(BST==NULL){
        return;
    }
    postorder(BST->left);
    postorder(BST->right);
    printf("%d ",BST->data);
}


void preorder(node* BST){
    if(BST == NULL){
        return;
    }
    printf("%d ",BST->data);
    preorder(BST->left);
    preorder(BST->right);
}

int main(){
    node* BST = take_tree();
    printf("inorder traversal of BSt is:\n");
    display(BST);
    printf("\n");
    printf("preorder traversasl of BST is:\n");
    preorder(BST);
    printf("\n");
    printf("postorder traversal of BST is:\n");
    postorder(BST);
    printf("\n");
    return 0;
}