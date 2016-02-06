#define MAX_SIZE 50
#define ADD 43
#define SUB 45
#define MUL 42
#define DIV 47

int top =-1;

struct treeNode{
    char data;
    struct treeNode* left;
    struct treeNode* right;
} *Stack[MAX_SIZE]; 

struct treeNode* initPostOrder(char*);

void pre_order(struct treeNode* treeData);
void in_order(struct treeNode* treeData);

void push(struct treeNode**, struct treeNode*);
struct treeNode* pop(struct treeNode**);

int getResult(struct treeNode* treeData);

