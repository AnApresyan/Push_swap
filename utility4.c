#include "push_swap.h"

void	init(t_stack *a, int *num, int size)
{
	int	i;

	i = size - 1;
	while (i >= 0)
	{
		push(a, num[i]);
		i--;
	}
}

void	mv_to_b(t_stack *a, t_stack *b, int *num)
{
	int		i;
	int		min;
	int		max;
	int		size;
	t_stack	*not_move;

	i = 0;
	min = num[i];
	max = num[i];
	while (i < a->size)
	{
		if (num[i] < min)
			min = num[i];
		if (num[i] > max)
			max = num[i];
		i++;
	}
	not_move = should_not_push(min, max, a);
	size = a->size - not_move->size;
	while (b->size != size)
		right_order(not_move, a, b);
}

void	right_order(t_stack *not_move, t_stack *a, t_stack *b)
{
	int	mid;
	int	cheapest;

	mid = mid_num(a);
	cheapest = next_cheapest(a, mid, not_move);
	if (cheapest == -1)
	{
		if (not_push(a->top->data, not_move))
			ra(a, 1);
		else
			pb(a, b, 1);
	}
	else
		insert_to_b(cheapest, a, b);
}

int	mid_num(t_stack *a)
{
	int		i;
	int		*arr;
	t_node	*temp;

	i = 0;
	temp = a->top;
	arr = malloc(a->size * 4);
	while (i < a->size)
	{
		arr[i] = temp->data;
		i++;
		temp = temp->next;
	}
	return (sort(arr, a->size));
}

int	sort(int arr[], int size)
{
	int	mid;
	int	temp;
	int	min;
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		min = i;
		j = i + 1;
		while (j < size)
		{
			if (arr[j] < arr[min])
				min = j;
			j++;
		}
		temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
		i++;
	}
	mid = arr[size / 2];
	free(arr);
	return (mid);
}
