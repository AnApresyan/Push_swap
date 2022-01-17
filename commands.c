#include "push_swap.h"

int	g_glob;

void	sa(t_stack *a, int print)
{
	if (print)
		ft_putstr("sa\n");
	swap(a);
}

void	sb(t_stack *b, int print)
{
	if (print)
		ft_putstr("sb\n");
	swap(b);
}

void	ss(t_stack *a, t_stack *b, int print)
{
	sa(a, print);
	sb(b, print);
}

void	pa(t_stack *a, t_stack *b, int print)
{
	g_glob++;
	if (print)
		ft_putstr("pa\n");
	if (b->size != 0)
		push(a, pop(b));
}

void	pb(t_stack *a, t_stack *b, int print)
{	
	g_glob++;
	if (print)
		ft_putstr("pb\n");
	if (a->size != 0)
		push(b, pop(a));
}
