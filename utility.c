#include "push_swap.h"

void swap(t_stack *stack)
{
        if (stack->top != NULL && stack->top->next != NULL)
        {
        	int a = top(stack);
                stack->top->data = stack->top->next->data;
                stack->top->next->data = a;

        }
}

void sa(t_stack *a)
{
        swap(a);
}

void sb(t_stack *b)
{
        swap(b);
}

void ss(t_stack *a, t_stack *b)
{
        swap(a);
        swap(b);
}

void pa(t_stack *a, t_stack *b)
{
	if (b->size != 0)
		push(a, pop(b));
}

void pb(t_stack *a, t_stack *b)
{
	if (a->size != 0)
		push(b, pop(a));

}

void ra(t_stack *a)
{
	if (a->size > 1)
		a->top = a->top->next;
}

void rb(t_stack *b)
{
	if (b->size > 1)
		b->top = b->top->next;
}

void rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}

void rra(t_stack *a)
{
        if (a->size > 1)
                a->top = a->top->prev;
}

void rrb(t_stack *b)
{
        if (b->size > 1)
                b->top = b->top->prev;
}

void rrr(t_stack *a, t_stack *b)
{
        rra(a);
        rrb(b);
}

