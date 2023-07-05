#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Node node;

struct Node{
    int data;
	node* left;
    node* right;
    bool thread; 
};


node* newnode(int x){
	node* y = (node*) malloc(sizeof(node));
	y->data = x;
	y->left = NULL;
	y->right = NULL;
	y->thread = true;
	return y;
}

node* insert(node* root, int ele)
{
	node* ptr = root;
	node* par = NULL;
	while(ptr!=NULL){
		par = ptr;
		if(ele < ptr->data){
			ptr = ptr->left;
		}else if(ele > ptr->data){
			if(ptr->thread == false){
				ptr = ptr->right;

			}else{
				break;
			}
		}
	}
	node* tmp = newnode(ele);
	if(par == NULL){
		root = tmp;
		tmp -> left = NULL;
		tmp -> right = NULL;
		printf("insert1\n");
	}else if(ele < par->data){
		tmp->left = par->left;
		tmp -> right = par;
		par -> left = tmp;
		printf("insert2\n");
	}else{
		tmp -> right = par -> right;
		par -> right = tmp;
		par -> thread = false;
		tmp -> left = NULL;
		printf("insert3\n");
	}
	return root;
}

void inorder_rec(node* root){
	if(root == NULL) return;
	inorder_rec(root->left);
	printf("%d ",root->data);
	if(root->thread != true)
		inorder_rec(root->right);
}

node* inorder_succ(node* root){
	if(root==NULL){
		return NULL;
	}

	if(root->thread == true){
		return root->right;
	}

	root = root->right;
	while(root->left!=NULL){
		root = root->left;
	}
	return root;
}

void inorder(node* root){
	if(root == NULL){
		return;
	}

	node* tmp = root;
	while(tmp -> left != NULL){
		tmp = tmp -> left;
	}

	while(tmp != NULL){
		printf("%d ",tmp->data);
		tmp = inorder_succ(tmp);
	}
	printf("\n");
}


int main(){	
	node* root = (node*) malloc(sizeof(node));
	root = NULL;
	int arr[6] = {1,-9,2,89,-10,3};
	for(int i=0; i<6; i++){
		//printf("done\n");
		root = insert(root,arr[i]);
	}
	inorder(root);
	inorder_rec(root);
    return 0;
}



