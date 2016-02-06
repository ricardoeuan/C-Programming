#ifndef queues
#define queues

#include <stdlib.h>
#define MaxQ 10

//Queue, consta del head y el tail y el arreglo que tendra los elementos de la fila.
typedef struct{
    int head, tail;
    int QA[MaxQ];
}QueueType, *Queue;  //8 bytes -> 56 bytes

//Metodo de inicializacion

Queue init_queue()
{
    //Si no hago el cast (Queue) yo tengo un: (void*)
    //Si quiero acceder a Q->head sin el cast me marcaria 
    //error porque el puntero no conoce las variables de la estructura.
    Queue Q = (Queue)malloc(sizeof(QueueType));
    Q->head = 0;
    Q->tail = 0;
    return Q;
}

int empty(Queue Q)
{
    return(Q->head == Q->tail);
}

//Metodo para insertar elementos
void enqueue(Queue Q, int num)
{
    //Incrementar variable de tail
    if(Q->tail == MaxQ - 1){
        Q->tail = 0;
    }else{
        (Q->tail)++;
    }
    //Revisar que mi Queue no este llena
    if(Q->tail == Q->head){
        printf("Queue is full");
        exit(1);
    }else{
    //Insertar elemento
        Q->QA[Q->tail] = num;
    }
}

int dequeue(Queue Q)
{
    //Verificar que el queue no este vacio
    if(empty(Q)){
        printf("Attempting to remove from an empty Queue.");
        exit(1);
    }
    //Incrementar Head
    if(Q->head == MaxQ - 1){
        Q->head = 0;
    }else{
        (Q->head)++;
    }
    int hold = Q->QA[Q->head];
    return hold;
}
#endif
