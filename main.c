#include "push_swap.h"

extern int	g_glob;

int	main(int argc, char **argv)
{
	//int		i;
	int		*num;
	t_stack	*a;
	t_stack	*b;

	//i = 1;
	g_glob = 0;
	num = malloc(4 * (argc - 1));
	errors_and_elements(argc, argv, num);
	a = init_stack();
	b = init_stack();
	main_helper(argc, a, b, num);
	//checker(a);
	free(num);
}

void	main_helper(int argc, t_stack *a, t_stack *b, int *num)
{
	init(a, num, argc - 1);
	if (argc <= 6)
	{
		less_than_five(a, b, argc - 1);
		//print_stack(a);
		//printf("Num of operations: %d", g_glob);
		return ;
	}
	mv_to_b(a, b, num);
	main_algo(a, b);
	//printf("Num of operations: %d\n", g_glob);
	//print_stack(a);
}
