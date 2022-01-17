#include "push_swap.h"

extern int	g_glob;

void	ra(t_stack *a, int print)
{	
	g_glob++;
	if (print)
		ft_putstr("ra\n");
	if (a->size > 1)
		a->top = a->top->next;
}

void	rb(t_stack *b, int print)
{
	g_glob++;
	if (print)
		ft_putstr("rb\n");
	if (b->size > 1)
		b->top = b->top->next;
}

void	rr(t_stack *a, t_stack *b, int print)
{
	ra(a, print);
	rb(b, print);
}

void	rra(t_stack *a, int print)
{
	g_glob++;
	if (print)
		ft_putstr("rra\n");
	if (a->size > 1)
		a->top = a->top->prev;
}

void	rrb(t_stack *b, int print)
{
	g_glob++;
	if (print)
		ft_putstr("rrb\n");
	if (b->size > 1)
		b->top = b->top->prev;
}
