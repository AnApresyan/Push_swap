#include "push_swap.h"
/*void swap(t_list *list)
{
	if (list != NULL && list->next != NULL)
	{
		int a = list->data;
		list->data = list->next->data;
		list->next->data = a;
	}
}

void sa(t_list *a)
{
	swap(a);
}

void sb(t_list *b)
{
	swap(b);
}

void ss(t_list *a, t_list *b)
{
	swap(a);
	swap(b);
}*/

int main(void)
{
	t_stack *a;
	a = (t_stack*)malloc(sizeof(t_stack));
	a->top = NULL;
	a->size = 0;

	pushing(a, 8);
	
	pushing(a, 20);
	
	pushing(a, 2);
	pushing(a, 6);
	pushing(a, 10);
	pushing(a, 11);
	pushing(a, 79);
	pushing(a, 123);
	pushing(a, 0);

        t_stack *b;
        b = (t_stack*)malloc(sizeof(t_stack));
        b->top = NULL;
        b->size = 0;


	pushing(b, 1);
	pushing(b, 2);
	pushing(b, 3);
	pushing(b, 4);
	
	print_stack(a);
	print_stack(b);
	
	rrr(a, b);

	//rr(a, b);
	print_stack(a);
	print_stack(b);
}

void pushing(t_stack *stack, int a)
{
	//printf("\nPushing %d\n", a);
        push(stack, a);
        //printf("Size: %d\n", stack->size);
        //printf("Top: %d\n", top(stack));
}

void print_stack(t_stack *stack)
{
	t_node *temp = stack->top;
	int size = stack->size;
	printf("\n");
	while (size > 0)
	{
		printf("%d ", temp->data);
		temp = temp->next;
		size--;
	}
	printf("\n");

}
