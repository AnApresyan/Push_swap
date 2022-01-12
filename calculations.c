#include "push_swap.h"

/*void calculate(t_stack *a, t_stack *b)
{
	int num_of_operations = -1;
	int i;
	int size;
	t_node *temp;

	while(b->size > 0)
	{
		temp = b->top;
		size = b->size;
		i = -1;
		while (size > 0)
		{
			if(temp->data < a->top->data && temp->data > a->top->prev->data)
			{
				int current_ops = (b->size - size) < (b->size)/2 ? b->size - size : size;
				if (i == -1 || current_ops < num_of_operations)
				{
					i = b->size - size;
					num_of_operations = current_ops;
				}
				if (i == 0)
					break;
			}
			temp = temp->next;
			size--;
		}
		if (i != -1)
			insert(a, b, i);
		else
			ra(a);
		//print_stack(a);
		//print_stack(b);	
	}
	bring_up_min(a);
}*/

void	main_algo(t_stack *a, t_stack *b)
{
	int		t;
	int		i;
	int		j;
	int		num;
	t_node	*temp;

	while (b->size > 0)
	{
		i = -1;
		temp = b->top;
		j = 0;
		while (j < b->size)
		{
			if (i == -1 || operations(b, j) + operations_a(a, temp->data) < t)
			{
				t = operations(b, j) + operations_a(a, temp->data);
				i = j;
				num = temp->data;
			}
			temp = temp->next;
			j++;
		}
		insert_second_version(a, b, i, num);
	}
	bring_up_min(a);
}

int	operations(t_stack *stack, int i)
{
	if (i <= stack->size / 2)
		return (i);
	return (stack->size - i);
}

int	operations_a(t_stack *a, int num)
{
	return (operations(a, find_where_insert(a, num)));
}

int	find_where_insert(t_stack *a, int num)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = a->top;
	while (i < a->size)
	{
		if (num < temp->data && num > temp->prev->data)
			break ;
		temp = temp->next;
		i++;
	}
	return (i);
}

int	find_min(t_stack *a)
{
	int		i;
	int		temp_min;
	int		size;
	t_node	*temp;

	i = 0;
	temp = a->top;
	temp_min = temp->data;
	size = a->size;
	while (size > 0)
	{
		if (temp->data < temp_min)
		{
			i = a->size - size;
			temp_min = temp->data;
		}
		temp = temp->next;
		size--;
	}
	return (i);
}
