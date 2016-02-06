#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK 10

typedef struct{
    int top;
    int ST[MAX_STACK];
}StackType, *Stack;

Stack initStack()
{
    Stack s = (Stack) malloc(sizeof(StackType));
    s -> top = -1;
    return s;
}

int empty(Stack stack)
{
    return (stack -> top == -1); 
}
void push(Stack stack, int n)
{
    if(stack -> top == MAX_STACK-1){
        printf("Stack overflow\n");
        exit(1);
    }
    ++(stack -> top);
    stack -> ST[stack -> top] = n;
}
int pop(Stack stack)
{
    if(empty(stack)){
        return -9999;
    }
    int hold = stack -> ST[stack -> top];
    --(stack -> top);
    return hold;
}
int main(void)
{
    int n;
    Stack s = initStack();
    scanf("%d", &n);
    while(n != 0){
        push(s, n);
        scanf("%d", &n);
    }
    while(!empty(s))
    {
        printf("%d\n", pop(s));
    }
        printf("\n");
        free(s);
}
