#include "push_swap.h"

extern int glob;
void swap(t_stack *stack)
{
	glob++;
        if (stack->top != NULL && stack->top->next != NULL)
        {
        	int a = top(stack);
                stack->top->data = stack->top->next->data;
                stack->top->next->data = a;

        }
}

void sa(t_stack *a)
{
	ft_putstr("sa\n");
        swap(a);
}

void sb(t_stack *b)
{
	
	ft_putstr("sb\n");
        swap(b);
}

void ss(t_stack *a, t_stack *b)
{
        sa(a);
        sb(b);
}

void pa(t_stack *a, t_stack *b)
{
	glob++;	
	ft_putstr("pa\n");
	if (b->size != 0)
		push(a, pop(b));
}

void pb(t_stack *a, t_stack *b)
{	
	glob++;
	ft_putstr("pb\n");
	if (a->size != 0)
		push(b, pop(a));

}

void ra(t_stack *a)
{	
	glob++;
	ft_putstr("ra\n");
	if (a->size > 1)
		a->top = a->top->next;
}

void rb(t_stack *b)
{
	glob++;
	ft_putstr("rb\n");
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
	glob++;
	ft_putstr("rra\n");
        if (a->size > 1)
                a->top = a->top->prev;
}

void rrb(t_stack *b)
{
	glob++;
	ft_putstr("rrb\n");
        if (b->size > 1)
                b->top = b->top->prev;
}

void rrr(t_stack *a, t_stack *b)
{
        rra(a);
        rrb(b);
}

