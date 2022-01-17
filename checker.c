/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapresya <anahit.apresyan7@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:08:23 by aapresya          #+#    #+#             */
/*   Updated: 2022/01/17 19:08:34 by aapresya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		*num;
	int		read;
	t_stack	*a;
	t_stack	*b;
	char	*line;

	num = malloc(4 * (argc - 1));
	errors_and_elements(argc, argv, num);
	a = init_stack();
	b = init_stack();
	init(a, num, argc - 1);
	while (1)
	{
		read = get_next_line(1, &line);
		if (!read)
			break ;
		read_commands(line, a, b);
	}
	checker(a);
}

void	read_commands(char *line, t_stack *a, t_stack *b)
{
	if (same(line, "sa"))
		sa(a, 0);
	else if (same(line, "sb"))
		sb(b, 0);
	else if (same(line, "ss"))
		ss(a, b, 0);
	else if (same(line, "pa"))
		pa(a, b, 0);
	else if (same(line, "pb"))
		pb(a, b, 0);
	else if (same(line, "ra"))
		ra(a, 0);
	else if (same(line, "rb"))
		rb(b, 0);
	else if (same(line, "rr"))
		rr(a, b, 0);
	else if (same(line, "rra"))
		rra(a, 0);
	else if (same(line, "rrb"))
		rrb(b, 0);
	else if (same(line, "rrr"))
		rrr(a, b, 0);
	else
		exit(error_message());
	free(line);
}

int	same(char *line, char *command)
{
	int	i;

	i = 0;
	if (!line || !command)
		return (0);
	if (ft_strlen(line) != ft_strlen(command))
		return (0);
	while (line[i] != '\0')
	{
		if (line[i] != command[i])
			return (0);
		i++;
	}
	return (1);
}

void	checker(t_stack *a)
{
	int		i;
	t_node	*temp;

	if (!a)
	{
		ft_putstr("KO\n");
		return ;
	}
	if (a->size <= 1)
	{
		ft_putstr("OK\n");
		return ;
	}
	i = 1;
	temp = a->top->next;
	while (i < a->size)
	{
		if (temp->data < temp->prev->data)
		{
			ft_putstr("KO\n");
			return ;
		}
		temp = temp->next;
		i++;
	}
	ft_putstr("OK\n");
}
