#include "push_swap.h"

void push(t_stack *stack, int a)
{
	t_node *node;
	node = (t_node*)malloc(sizeof(t_node));
	node->data = a;
	if(stack->size == 0)
	{
		node->next = node;
		node->prev = node;
	}
	else
	{
		node->next = stack->top;
		node->prev = stack->top->prev;
		stack->top->prev = node;
		node->prev->next = node;
	}
	stack->top = node;
	stack->size++;
}

int pop(t_stack *stack)
{
	int value;

	if(stack->size != 0)
	{
		value = stack->top->data;
		stack->top->next->prev = stack->top->prev;
		stack->top->prev->next = stack->top->next;
		t_node *temp = stack->top;
		stack->top = stack->top->next;
		stack->size--;
		free(temp);
		return value;
	}
	printf("The stack is empty");
	return 0;
}

int top(t_stack *stack)
{
	if (stack->size != 0)
		return (stack->top->data);
	printf("The stack is empty");
	return 0;
}
