typedef struct node
{
	int num, val;
	struct node *next;
}NodeBase, *Node;

Node add(Node previous, int num); 
void insert(Node first, Node newNode, int index); 
int list_length(Node first); 
void printList(Node first); 
int find_value(Node first);
void last_node(Node first);
void sort_list(Node first);
void freeList(Node first); 
