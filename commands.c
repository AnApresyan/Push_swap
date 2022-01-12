#include "push_swap.h"

extern int	g_glob;

void	sa(t_stack *a)
{
	ft_putstr("sa\n");
	swap(a);
}

void	sb(t_stack *b)
{
	ft_putstr("sb\n");
	swap(b);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}

void	pa(t_stack *a, t_stack *b)
{
	g_glob++;
	ft_putstr("pa\n");
	if (b->size != 0)
		push(a, pop(b));
}

void	pb(t_stack *a, t_stack *b)
{	
	g_glob++;
	ft_putstr("pb\n");
	if (a->size != 0)
		push(b, pop(a));
}
