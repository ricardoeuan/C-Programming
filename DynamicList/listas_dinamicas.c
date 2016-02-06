#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

int main(void)
{    
	int n;
	Node first = (Node) malloc(sizeof(NodeBase));
    first -> num = -1;
    first -> next = NULL;    
    
    Node current = first;
	printf("Inserte numeros, para terminar introduzca 0:\n");
	scanf("%d", &n);
	while(n != 0) {
		current = add(current, n);
		scanf("%d", &n);
	}
	printf("Los elementos de la lista son:\n");
	printList(first);
	printf("La longitud de la lista es:\n");
    printf("%d\n", list_length(first));
    printf("Insertando un nuevo nodo (999) en la posicion 2\n");
    Node toInsert = (Node) malloc(sizeof(NodeBase));
    toInsert -> num = 999;
    insert(first, toInsert, 2);
    printf("La lista con el nuevo elemento: \n");
    printList(first);
    printf("Valor encontrado en la posicion: \n%d\n", find_value(first));
    printf("Valor del ultimo nodo: \n");
    last_node(first);
    printf("La lista ordenada: \n");
    sort_list(first);
	freeList(first);
	return 0;
}

Node add(Node previous, int num)
{
	if (previous -> num == -1)
	{
		previous -> num = num;
        return previous;
	} else {
		Node node = (Node) malloc(sizeof(NodeBase));
		node -> num = num;
		node -> next = NULL;
		previous -> next = node;
        return node;
	}
}

void insert(Node first, Node newNode, int index)
{
    if (first == NULL) {
        printf("La lista esta vacia");
    }
    if (index > list_length(first) - 1) {
        printf("El indice esta fuera de los limites de la lista\n");
        exit(1);
    }
    Node current = first; 
    Node previous = NULL; 
    int i = 1;
    while (current != NULL && i < index) {
        previous = current;
        current = current -> next;
        i++;
    }
    
    if (current -> next != NULL) {
        previous -> next = newNode;
        newNode -> next = current;
    } else {
        current -> next = newNode;
        newNode -> next = NULL;
    }    
}

int list_length(Node first)
{
    int length = 0;
    Node current = first;
    while (current != NULL) {
        length++;
        current = current -> next;
    }
    return length;
}

void printList(Node first)
{
	Node current = first;
	while(current != NULL) {
		printf("%d ", current -> num);
		current = current -> next;
	}
	printf("\n");
}

int find_value(Node first)
{
    int index = 1;
    Node current = first;
    Node val = (Node)5;
    while (current != NULL) {
        if(current -> num == (int)val)
        return index;
        index++;        
        current = current -> next;
    }
    return 1;
}

void last_node(Node first)
{
    Node previous = NULL;
    Node current = first;
    int i = 0;
    while (current != NULL && i < list_length(first)-1) {
        previous = current;
        current = current -> next;
        i++;
    }          
    printf("%d", current -> num);
  	printf("\n");
}

void sort_list(Node first)
{
    Node current = first;
    Node previous = NULL;
    Node temp;
	for (; current->next != NULL; current = current->next){
	    for(previous = current -> next; previous != NULL; previous= previous->next){
	        if(current->num > previous->num){
	            temp = (Node)current -> num;
	            current -> num = previous -> num;
	            previous -> num = (int)temp;
	        }
	    }
	    	printf("%d ", current->num);
	}	
	printf("\n");
}
void freeList(Node first)
{
	Node current = first;
	Node tmp; 
	while(current != NULL) { 
		tmp = current -> next; 
		free(current);
		current = tmp; 
	}
}
