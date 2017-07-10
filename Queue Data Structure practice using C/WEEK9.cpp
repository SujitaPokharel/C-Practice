#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int key;
	struct Node *next;
}NODE_TYPE;

typedef struct link
{
	struct Node *front;
	struct Node *back;
}LINK_TYPE;

LINK_TYPE* CreateQueue()
{
	LINK_TYPE *queue = (LINK_TYPE*)malloc(sizeof(LINK_TYPE));
	queue->front = NULL;
	queue->back = NULL;
	return queue;
}

void Enqueue(LINK_TYPE* link, int value)
{
	NODE_TYPE *node = (NODE_TYPE*)malloc(sizeof(NODE_TYPE));
	node->key = value;
	node->next = NULL;
	if (link->back == NULL)
	{
		link->front = node;
	}
	else
	{
		//node->next = link->back;
		link->back->next = node;
	}
	link->back = node;
}
int Dequeue(LINK_TYPE* link)
{
	int val;
	NODE_TYPE* node;
	node = link->front;
	val = node->key;
	if (node->next == NULL)
	{
		link->front = NULL;
		link->back = NULL;
		free(link);
	}
	else
	{
		link->front = node->next;
	}
	free(node);
	return val;
}
void printQueue(LINK_TYPE* link)
{
	NODE_TYPE* node = link->front;
	while (node != NULL)
	{
		printf("%d \n", node->key);
		node = node->next;
	}
}

void Concatenate(LINK_TYPE* q1, LINK_TYPE* q2)
{
	NODE_TYPE *obj = (NODE_TYPE*)malloc(sizeof(NODE_TYPE));
	obj = q2->front;
	while (obj != NULL)
	{
		Enqueue(q1, obj->key);
		obj = obj->next;
	}

}

int main()
{
	int i, val; char a[10];
	LINK_TYPE *link = CreateQueue();
	//printf("Enqueuing values... \n");
	printf("Enter characters.. \n");
	for (i = 0; i < 10; i++)
	{
		//scanf_s("%c", &a[i]);
		//a[i] = getchar();
		Enqueue(link, i);
	}
	printQueue(link);
	printf("Dequeuing values... \n");
	for (i = 0; i < 10; i++)
	{
		val = Dequeue(link);
		printf("%d \n", val);
	}
	LINK_TYPE* q1 = CreateQueue();
	LINK_TYPE* q2 = CreateQueue();
	for (i = 12; i < 15; i++)
	{
		Enqueue(q1, i);
	}
	Enqueue(q2, 90);
	Enqueue(q2, 80);
	printf("\n Q1 data is: \n");
	printQueue(q1);
	printf("\n Q2 data is: \n");
	printQueue(q2);
	Concatenate(q1, q2);
	printf("\n Q1 data after concatenation is: \n");
	printQueue(q1);
}
