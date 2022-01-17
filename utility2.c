/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapresya <anahit.apresyan7@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:08:39 by aapresya          #+#    #+#             */
/*   Updated: 2022/01/17 19:08:41 by aapresya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	less_than_five(t_stack *a, t_stack *b, int size)
{
	if (size == 1)
		return ;
	if (size == 2)
	{
		if (a->top->data > a->top->next->data)
			sa(a, 1);
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
		rra(a, 1);
	else if (top > next && next > prev)
	{	
		sa(a, 1);
		rra(a, 1);
	}
	else if (top > next && next < prev && top > prev)
		ra(a, 1);
	else if (!(top < next && next < prev))
	{
		ra(a, 1);
		sa(a, 1);
		if (a->top->data < a->top->next->data)
			rra(a, 1);
		else
			ra(a, 1);
	}
}

void	size_four(t_stack *a, t_stack *b)
{
	if (check_four_correct(a->top))
		return ;
	bring_up_min(a);
	pb(a, b, 1);
	size_three(a, a->top->next->data, a->top->prev->data);
	pa(a, b, 1);
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
	pb(a, b, 1);
	size_four(a, b);
	pa(a, b, 1);
}
