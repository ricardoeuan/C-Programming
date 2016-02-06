#include <stdio.h>
#include "queues2.h"

int main()
{
    int n;
    Queue Q = init_queue();
    scanf("%d", &n);
    while(n>0){
        enqueue(Q, n%10);
        n = n / 10;
    }
    printf("Print elements in reverse order: \n");
    while(!empty(Q)){
        printf("%d", dequeue(Q));
    }
    printf("\n");
    free (Q);
    return 0;    
}
