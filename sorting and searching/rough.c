#include "circular_queue.c"

int main(){

    cqueue* q = (cqueue*) malloc(sizeof(cqueue));
    q->f=-1;
    q->r=-1;
    for(int i=1; i<=4; i++){
        push(q,i);
    }
    pop(q);
    pop(q);
    for(int i=1; i<=3; i++){
        push(q,i);
    }
 //  print(q);
  printf("done successfully");
    return 0;
}