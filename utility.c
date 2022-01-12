#include "push_swap.h"

extern int	g_glob;

void	insert_second_version(t_stack *a, t_stack *b, int i, int num)
{
	rotate_b(b, i);
	rotate_a(a, find_where_insert(a, num));
	pa(a, b);
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

/*void	insert(t_stack *a, t_stack *b, int i)
{
	if (i < b->size / 2)
	{
		while (i != 0)
		{
			if (i == 1)
				sb(b);
			else
				rb(b);
			i--;
		}
	}
	else
	{
		while (b->size - i != 0)
		{
			rrb(b);
			i++;
		}
	}
	pa(a, b);
}*/

void	rotate_b(t_stack *b, int i)
{
	if (i <= b->size / 2)
	{
		while (i != 0)
		{
			if (i == 1)
				sb(b);
			else
				rb(b);
			i--;
		}
	}
	else
	{
		while (b->size - i != 0)
		{
			rrb(b);
			i++;
		}
	}
}

void	rotate_a(t_stack *a, int i)
{	
	if (i < a->size / 2)
	{
		while (i != 0)
		{
			ra(a);
			i--;
		}
	}
	else
	{
		while (a->size - i != 0)
		{
			rra(a);
			i++;
		}
	}
}

void	bring_up_min(t_stack *a)
{
	int	min;

	min = find_min(a);
	if (min <= a->size / 2)
	{
		while (min-- != 0)
			ra(a);
	}
	else
		while (min++ != a->size)
			rra(a);
}
