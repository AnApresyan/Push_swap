/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapresya <anahit.apresyan7@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:08:43 by aapresya          #+#    #+#             */
/*   Updated: 2022/01/17 19:08:47 by aapresya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_to_b(int cheapest, t_stack *a, t_stack *b)
{
	rotate_a(a, cheapest);
	pb(a, b, 1);
}

int	next_cheapest(t_stack *a, int mid, t_stack *not_move)
{
	t_node	*temp;
	int		num_operations;
	int		i;
	int		j;

	j = -1;
	i = 0;
	temp = a->top;
	while (i < a->size)
	{
		if (temp->data <= mid && !not_push(temp->data, not_move))
		{
			if (j == -1 || operations(a, i) < num_operations)
			{
				j = i;
				num_operations = operations(a, i);
			}
		}
		temp = temp->next;
		i++;
	}
	return (j);
}

int	not_push(int num, t_stack *stack)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = stack->top;
	while (i < stack->size)
	{
		if (temp->data == num)
			return (1);
		temp = temp->next;
		i++;
	}
	return (0);
}

t_stack	*should_not_push(int min, int max, t_stack *a)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = a->top;
	while (i < a->size)
	{	
		if (temp->data == min)
			return (min_to_max(max, temp));
		i++;
		temp = temp->next;
	}
	return (NULL);
}

t_stack	*min_to_max(int max, t_node *temp)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->top = NULL;
	stack->size = 0;
	push(stack, temp->data);
	temp = temp->next;
	while (temp->data != max)
	{
		if (temp->data > stack->top->data && temp->data < max)
			push(stack, temp->data);
		temp = temp->next;
	}
	push(stack, temp->data);
	return (stack);
}
