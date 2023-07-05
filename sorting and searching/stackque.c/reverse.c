#include "stack.c"

void insert_at_last(stack* st, int x){
    if(isEmpty(st)){
        push(st,x);
        return;
    }

    int r=peek(st);
    pop(st);
    insert_at_last(st,x);
    push(st,r);
}

void reverse(stack* st){
    if(isEmpty(st)){
        return;
    }

    int x=peek(st);
    pop(st);
    reverse(st);
    insert_at_last(st,x);
}

int main(){
    stack* st = (stack*) malloc(sizeof(stack));
    st->top=-1;
    for(int i=1; i<=9; i++){
        push(st,i);
       // printf("top=%d\n",st->top);
    }

    printf("stack before reversing:\n");
    print(st);
    reverse(st);

    printf("stack after revrsing:\n");
    print(st);
    return 0;

}