
/*-----------------------------------SOFTWARE DOCUMENTATION --------
|  
|  Author: Ricardo Euán Romo    
|  https://ricardoeu.url.ph
|  
|  Requires: strImplementation.h | binaryEFDS.in
|
|  Description:  ExamenFinalDS.c is an arithmetic expression tree 
|  program that reads post-ordered data from a .in or .txt file 
|  and performs the in-order and pre-order visits to the three to 
|  print their respective data accomodation.
|  The program implements a Stack to insert values from the
|  tree struct, and finally performs a method to calculate the 
|  entered operation.
|
|  Bugs: Only reads one digit values inside the expression. E.g.
|  (In the following format)
| 
|  FILE INPUT            EQUIVALENT
|  (In post-order)       (In in-order)
|
|  84/3+         ->     (8/4) + 3
|  41-55**       ->     (4-1) * (5*5)
|  18+54+-31+-   ->     (1+8) - (5+4) - (13+1)
|  44/885*+      ->     (4/4) + (8/8*5)
*-------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "strImplementation.h"

int main()
{
    char expr[MAX_SIZE];
    struct treeNode* root;
        
    FILE *infile;
    infile = fopen("binaryEFDS.in", "r");
    if(infile == NULL)
    printf("File not found.");
    else
    fscanf(infile, "%s", expr);
        
    root = initPostOrder(expr);
            
    printf("Tree data in In-order: ");
    in_order(root);
    printf("\nTree data in Pre-order: ");
    pre_order(root);
    printf("\nTree data in Post-order: %s", expr);
    printf("\nResult: %d\n", getResult(root));    
    
    free(root->left);
    free(root->right);
    free(root);
}    

    struct treeNode* initPostOrder(char* expr){         
    struct treeNode* left_path, *right_path, *nodePtr;
    while(*expr)
    {
        nodePtr = (struct treeNode*)malloc(sizeof(struct treeNode));
        nodePtr->data = *expr;
        if(*expr == ADD || *expr == SUB || *expr == MUL || *expr == DIV)
        {
            right_path = pop(Stack);
            left_path = pop(Stack);
            
            nodePtr->left = left_path;
            nodePtr->right = right_path;
        }
        else
        {
            nodePtr->left = NULL;  
            nodePtr->right = NULL;     
        }
        push(Stack, nodePtr);
        expr++;
    }
    return pop(Stack);
}   

void in_order(struct treeNode* treeData)
{
    if(treeData != NULL)
    {
        in_order(treeData->left);
        printf("%c", treeData->data);
        in_order(treeData->right);
    }    
}

void pre_order(struct treeNode* treeData)
{
    if(treeData != NULL)
    {        
        printf("%c", treeData->data);
        pre_order(treeData->left);
        pre_order(treeData->right);
    }    
}

void push(struct treeNode** Stack, struct treeNode* n)
{
    if(top == MAX_SIZE - 1)
        printf("\nStack Overflow\n");
        else
        {
            top++;
            Stack[top] = n;
        }
}

struct treeNode* pop(struct treeNode** Stack){
          if (top == -1)
                {
                printf("\nStack is empty\n") ;
                    return 0 ;
                }
                else
                {
                    struct treeNode* n = Stack[top] ;
                    top-- ;
                    return n;
                }
}

int getResult(struct treeNode* treeData)
{
        int leftVal, rightVal, finalVal;
            if (treeData != NULL)
                {
                if ( treeData->data == ADD || treeData->data == SUB || treeData->data == MUL || treeData->data == DIV)
                    {
                    leftVal = getResult(treeData -> left);
                    rightVal = getResult(treeData -> right);
                             
                    if(treeData->data == ADD)
                    finalVal = leftVal + rightVal;
                    else if (treeData->data == SUB)
                    finalVal = leftVal - rightVal;
                    else if (treeData->data == MUL)
                    finalVal = leftVal * rightVal;
                    else if (treeData->data == DIV)
                    finalVal = leftVal / rightVal;
                                                                                                
                    return finalVal;                     
                    }                    
                    return (treeData->data-48) ;        
                    }        
        return 0;
}  
