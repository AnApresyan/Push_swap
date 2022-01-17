#include "push_swap.h"

void	swap(t_stack *stack)
{
	int	a;

	if (stack->top != NULL && stack->top->next != NULL)
	{
		a = top(stack);
		stack->top->data = stack->top->next->data;
		stack->top->next->data = a;
	}
}

void	rrr(t_stack *a, t_stack *b, int print)
{
	rra(a, print);
	rrb(b, print);
}

int	error_message(void)
{
	ft_putstr("ERROR\n");
	return (0);
}
