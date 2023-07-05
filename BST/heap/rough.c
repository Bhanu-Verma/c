#include<stdio.h>
#include<stdlib.h>
typedef struct node node;
struct stud{
    char* name;
    char* roll;
    float cgpa;
};


struct node{
    struct stud data;
    node* next;
};


node* newnode(char* name, char* roll, float cgpa){
    node* new_node = (node*) malloc(sizeof(node));
    new_node -> data.name  = name;
    new_node -> data.roll = roll;
    new_node -> data.cgpa = cgpa;
    new_node -> next = NULL;
    return new_node;
}

int main(){
    node* a = newnode("Bhanu","22075021",9.63);
    node* b = newnode("Ramu","22015027",8.9);
    node* c = newnode("vishnu","22075094",9.43);
    a->next = b;
    b->next = c;
    while(a!=NULL){
        printf("%s",a->data.name);
        a = a->next;
    }

    return 0;
}