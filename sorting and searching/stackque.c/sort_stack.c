#include "stack.c"

void sorted_insert(stack* st, int x){
    if(isEmpty(st)){
        push(st,x);
        return;
    }
    if(peek(st)<=x){
        push(st,x);
        return;
    }

    int y=peek(st);
    pop(st);
   // reverse(st);
    sorted_insert(st,x);
    push(st,y);
}

void sort_stack(stack* st){
    if(isEmpty(st)){
        return;
    }

    int x=peek(st);
    pop(st);
    sort_stack(st);
    sorted_insert(st,x);
}

int main(){
    stack* st = (stack*) malloc(sizeof(stack));
    st->top=-1;
    for(int i=1; i<=9; i++){
        push(st,10-i);
       
    }
    print(st);
    sort_stack(st);
    print(st);


    return 0;
}