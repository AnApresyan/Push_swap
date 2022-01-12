#include "push_swap.h"

int	g_glob;

int	main(int argc, char **argv)
{
	int		i;
	int		*num;
	t_stack	*a;
	t_stack	*b;

	i = 1;
	g_glob = 0;
	num = malloc(4 * (argc - 1));
	while (i < argc)
	{
		if (!check(argv[i]))
			return (error_message());
		else
			num[i - 1] = ft_atoi(argv[i]);
		i++;
	}	
	if (!check_dupls(num, argc - 1))
		return (error_message());
	a = init_stack();
	b = init_stack();
	main_helper(argc, a, b, num);
	free(num);
}

void	main_helper(int argc, t_stack *a, t_stack *b, int *num)
{
	init(a, num, argc - 1);
	if (argc <= 6)
	{
		less_than_five(a, b, argc - 1);
		print_stack(a);
		printf("Num of operations: %d", g_glob);
		return ;
	}
	mv_to_b(a, b, num);
	main_algo(a, b);
	printf("Num of operations: %d\n", g_glob);
	print_stack(a);
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
