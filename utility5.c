#include "push_swap.h"

void	errors_and_elements(int argc, char **argv, int *num)
{
	int	i;

	i = 1;
	if (argc == 1)
		exit (1);
	while (i < argc)
	{
		if (!check(argv[i]))
			exit(error_message());
		else
			num[i - 1] = ft_atoi(argv[i]);
		i++;
	}	
	if (!check_dupls(num, argc - 1))
		exit(error_message());
}

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

int	check(char *str)
{
	long	num;

	if (is_number(str))
	{
		num = ft_atoi(str);
		if (num >= -2147483648 && num <= 2147483647)
			return (1);
	}	
	return (0);
}

int	check_dupls(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
