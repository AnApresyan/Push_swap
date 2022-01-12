#include "push_swap.h"

extern int	g_glob;

void	swap(t_stack *stack)
{
	int	a;

	g_glob++;
	if (stack->top != NULL && stack->top->next != NULL)
	{
		a = top(stack);
		stack->top->data = stack->top->next->data;
		stack->top->next->data = a;
	}
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}

int	error_message(void)
{
	ft_putstr("ERROR\n");
	return (0);
}

void	print_stack(t_stack *stack)
{
	int		size;
	t_node	*temp;

	temp = stack->top;
	size = stack->size;
	while (size > 0)
	{
		printf("%d ", temp->data);
		temp = temp->next;
		size--;
	}
	printf("\n");
}
