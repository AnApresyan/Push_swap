/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapresya <anahit.apresyan7@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:34:28 by aapresya          #+#    #+#             */
/*   Updated: 2022/01/17 20:34:29 by aapresya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

<<<<<<< HEAD
#include "push_swap.h"

=======
>>>>>>> 574643a1a178ec051adfd7fbeb1b1f70a3ed4fe5
void	insert_second_version(t_stack *a, t_stack *b, int i, int num)
{
	rotate_b(b, i);
	rotate_a(a, find_where_insert(a, num));
	pa(a, b, 1);
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

void	rotate_b(t_stack *b, int i)
{
	if (i <= b->size / 2)
	{
		while (i != 0)
		{
			if (i == 1)
				sb(b, 1);
			else
				rb(b, 1);
			i--;
		}
	}
	else
	{
		while (b->size - i != 0)
		{
			rrb(b, 1);
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
			ra(a, 1);
			i--;
		}
	}
	else
	{
		while (a->size - i != 0)
		{
			rra(a, 1);
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
			ra(a, 1);
	}
	else
		while (min++ != a->size)
			rra(a, 1);
}
