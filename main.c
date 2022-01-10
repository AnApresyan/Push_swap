#include "push_swap.h"

int main(void)
{
	t_stack *a;
	a = (t_stack*)malloc(sizeof(t_stack));
	a->top = NULL;
	a->size = 0;

	pushing(a, 1);
	
	pushing(a, 100);
	

        t_stack *b;
        b = (t_stack*)malloc(sizeof(t_stack));
        b->top = NULL;
        b->size = 0;


	pushing(b, 13);
	pushing(b, 22);
	pushing(b, 43);
	pushing(b, 4);
	pushing(b, 24);
	pushing(b, 12);
	pushing(b, 87);
	pushing(b, 23);
	
	print_stack(a);
	print_stack(b);
	
	//rrr(a, b);
	calculate(a, b);
	//rr(a, b);
	print_stack(a);
	print_stack(b);
	//
	//printf("min: %d", find_min(a));
	//bring_up_min(a);
	//print_stack(a);
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
