#include <stdio.h>
#include <stdlib.h>

//create a node
struct node
{
	int amount;
	struct node *next;
};
typedef struct node NodeType;

// create a linked list
struct list
{
	int count;
	NodeType* listhead;
};

typedef struct list ListType;

// create the first node (i.e. head) of a linked list
ListType* CreateList(void);
//Add an item to a list
void InsertNode(ListType *list, int amount);
// Print all elements in a list
void PrintList(ListType *list);

ListType* CreateList()
{
	ListType *list;
	list = (ListType*) malloc(sizeof(ListType));
	list -> count = 0;
	list -> listhead = NULL;
	return list;
}

void InsertNode(ListType *list, int amount)
{
	NodeType *current;
	current = (NodeType*) malloc(sizeof(NodeType));
	current->amount = amount;
	current->next = list->listhead;
	list->listhead = current;
	list->count ++;
}

void PrintList(ListType *list)
{
	NodeType *ptr;
	ptr = list ->listhead;
	while (ptr != NULL)
	{
		printf("%d, ", ptr->amount);
		ptr = ptr->next;
	}
}

void main()
{
	//create a list, count = 0, listhead = NULL
	//then keep receiving donations until -9999 is entered
	int val;
	ListType *list;
	list = CreateList();
	printf("Enter each element, end with -9999:");
	scanf("%d", &val);
	while (val != -9999)
	{
		InsertNode(list, val);
		scanf("%d", &val);
	}
	PrintList(list);
	printf("\ntotal donations received %d\n", list->count);
}