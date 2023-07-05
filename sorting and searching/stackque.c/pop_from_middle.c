#include "stack.c"

void pop_middle(stack* st, int s, int i){
    if(i==s){
        pop(st);
        
        return;
    }

    int x=peek(st);
    pop(st);
    print(st);
    pop_middle(st,s,i+1);
    push(st,x);
}

int main(){
    stack* st = (stack*) malloc(sizeof(stack));
    st->top=-1;
    for(int i=1; i<=9; i++){
        push(st,i);
        printf("top=%d\n",st->top);
    }
   // print(st);
    printf("size=%d",size(st));
    int s=size(st)/2;

    pop_middle(st,s,0);
    print(st);
    return 0;
}