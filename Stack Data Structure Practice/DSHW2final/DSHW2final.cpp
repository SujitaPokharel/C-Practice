#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stacksADT.h"

//function definition
//STACK* destroyStack(STACK* stack);
//bool fullStack(STACK* stack);
//bool emptyStack(STACK* stack);
//void* popStack(STACK* stack);
//bool pushStack(STACK* stack, void* dataInPtr);
//STACK* createStack(void);


int main(void)
{
	// Local Definitions
	bool done = false;
	int* dataPtr;

	STACK* stack;

	// Create a stack and allocate memory for data
	stack = createStack();



	// Fill stack
	while (!done)
	{
		dataPtr = (int*)malloc(sizeof(int));
		printf("Enter a number: <EOF> to stop: ");
		if ((scanf_s("%d", dataPtr)) == EOF || fullStack(stack))
			done = true;
		else
			pushStack(stack, dataPtr);
	} // while



	// Now print numbers in reverse
	printf("\n\nThe list of numbers reversed:\n");
	while (!emptyStack(stack))
	{
		dataPtr = (int*)popStack(stack);
		printf("%3d\n", *dataPtr);
		free(dataPtr);
	} // while
	// Destroying Stack
	destroyStack(stack);
	return 0;
	/*system("pause");*/
}

//create stack module
//STACK* createStack(void)
//{
//
//STACK* stack;
//
//stack = (STACK*)malloc(sizeof(STACK));
//if (stack)
//{
//stack->count = 0;
//stack->top = NULL;
//}
//return stack;
//}
////push stack module
//bool pushStack(STACK* stack, void* dataInPtr)
//{
//
//STACK_NODE* newPtr;
//
//newPtr = (STACK_NODE*)malloc(sizeof(STACK_NODE));
//if (!newPtr)
//return false;
//newPtr->dataPtr = dataInPtr;
//newPtr->link = stack->top;
//stack->top = newPtr;
//(stack->count)++;
//return true;
//}
//
////pop stack module
//void* popStack(STACK* stack)
//{
//
//void* dataOutPtr;
//STACK_NODE* temp;
//
//if (stack->count == 0)
//dataOutPtr = NULL;
//else
//{
//temp = stack->top;
//dataOutPtr = stack->top->dataPtr;
//stack->top = stack->top->link;
//free(temp);
//(stack->count)--;
//}
//return dataOutPtr;
//}
//
////destroy stack moduel
//STACK* destroyStack(STACK* stack)
//{
//
//STACK_NODE* temp;
//
//if (stack)
//{
//
//while (stack->top != NULL)
//{
//
//free(stack->top->dataPtr);
//temp = stack->top;
//stack->top = stack->top->link;
//free(temp);
//}
//
//free(stack);
//}
//return NULL;
//}
//
////full stack module
//bool fullStack(STACK* stack)
//{
//
//STACK_NODE* temp;
//
//if ((temp =
//(STACK_NODE*)malloc(sizeof(*(stack->top)))))
//{
//free(temp);
//return false;
//}
//
//return true;
//}
//
//
//
////empty stack module
//bool emptyStack(STACK* stack)
//{
//
//return (stack->count == 0);
//}
