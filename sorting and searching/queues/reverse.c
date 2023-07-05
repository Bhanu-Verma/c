#include"queue.c"
#include"C:\Users\Dev IIT\Documents\sorting and searching\stack.c"

void reverse(queue* q){
    stack* st=(stack*) malloc(sizeof(stack));
    st->top=-1;

    while(!isEmpty(q)){
        int x=front(q);
        pop(q);
        push(st,x);
    }

    while(!isEmpty(st)){
        int x=peek(st);
        push(q,x);
        pop(st);
    }
}

int main(){
    queue* q = (queue*) malloc(sizeof(queue));
    q->f=-1;
    q->r=-1;

    for(int i=1; i<=10; i++){
        push(q,i);
    }
    print(q);
    reverse(q);
    print(q);
    return 0;
}