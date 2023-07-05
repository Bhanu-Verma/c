#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000

struct stack{
    int arr[SIZE];
    int top;

    
};
typedef struct stack stack;
void print(stack* st){
    for(int i=st->top; i>=0; i--){
        printf("%d ",st->arr[i]);
    }
    printf("\n");
}


void push(stack* st,int ele){   
        if(st -> top==SIZE-1){
            printf("stack overflow.\n");
            return;
        }else{
           // (st -> top)+=1;
        //   printf("st -> st -> top=%d",*st -> st -> top);
            st->arr[++(st -> top)]=ele;
        }
      
}

    void pop(stack* st){
        if(st -> top==-1){
            printf("stack is already empty");
            return;
        }
        st -> top-=1;
    }

    int peek(stack* st){
        if(st -> top==-1){
            printf("stack is empty");
        }else{
            return st->arr[st -> top];
        }
    }

    int isEmpty(stack* st){
        if(st -> top==-1){
            return 1;
        }else{
            return 0;
        }
    }

int size(stack* st){
    int ans=(st->top)+1;
    return ans;
}
