#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		*num;
	t_stack	*a;
	t_stack	*b;

	num = malloc(4 * (argc - 1));
	errors_and_elements(argc, argv, num);
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
		return ;
	}
	mv_to_b(a, b, num);
	main_algo(a, b);
}
