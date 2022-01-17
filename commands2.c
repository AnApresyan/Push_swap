/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapresya <anahit.apresyan7@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:09:03 by aapresya          #+#    #+#             */
/*   Updated: 2022/01/17 19:09:04 by aapresya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a, int print)
{
	if (print)
		ft_putstr("ra\n");
	if (a->size > 1)
		a->top = a->top->next;
}

void	rb(t_stack *b, int print)
{
	if (print)
		ft_putstr("rb\n");
	if (b->size > 1)
		b->top = b->top->next;
}

void	rr(t_stack *a, t_stack *b, int print)
{
	ra(a, print);
	rb(b, print);
}

void	rra(t_stack *a, int print)
{
	if (print)
		ft_putstr("rra\n");
	if (a->size > 1)
		a->top = a->top->prev;
}

void	rrb(t_stack *b, int print)
{
	if (print)
		ft_putstr("rrb\n");
	if (b->size > 1)
		b->top = b->top->prev;
}
