#include "push_swap.h"

void	less_than_five(t_stack *a, t_stack *b, int size)
{
	if (size == 1)
		return ;
	if (size == 2)
	{
		if (a->top->data > a->top->next->data)
			sa(a);
	}
	else if (size == 3)
		size_three(a, a->top->next->data, a->top->prev->data);
	else if (size == 4)
		size_four(a, b);
	else
		size_five(a, b);
}

void	size_three(t_stack *a, int next, int prev)
{
	int	top;

	top = a->top->data;
	if (top < next && top > prev)
		rra(a);
	else if (top > next && next > prev)
	{	
		sa(a);
		rra(a);
	}
	else if (top > next && next < prev && top > prev)
		ra(a);
	else if (!(top < next && next < prev))
	{
		ra(a);
		sa(a);
		if (a->top->data < a->top->next->data)
			rra(a);
		else
			ra(a);
	}
}

void	size_four(t_stack *a, t_stack *b)
{
	if (check_four_correct(a->top))
		return ;
	bring_up_min(a);
	pb(a, b);
	size_three(a, a->top->next->data, a->top->prev->data);
	pa(a, b);
}

int	check_four_correct(t_node *temp)
{
	int	i;

	i = 1;
	while (i < 4 && temp->data < temp->next->data)
	{
		temp = temp->next;
		i++;
	}
	if (i == 4)
		return (1);
	return (0);
}

void	size_five(t_stack *a, t_stack *b)
{
	if (check_four_correct(a->top->next) && a->top->data < a->top->next->data)
		return ;
	bring_up_min(a);
	pb(a, b);
	size_four(a, b);
	pa(a, b);
}
