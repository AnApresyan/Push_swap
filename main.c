#include "push_swap.h"

int glob;

int main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	int num[argc - 1];
	int i = 1;
	
	glob = 0;
	//printf("%d", check(argv[1]));
	while(i < argc)
	{
		if (!check(argv[i]))
		{
			printf("ERROR\n");
			return (-1);
		}
		else
			num[i-1] = ft_atoi(argv[i]);
		i++;
	}
	
	if (!check_dupls(num, argc - 1))
	{
		printf("ERROR\n");
		return (-1);
	}


	a = (t_stack*)malloc(sizeof(t_stack));
        a->top = NULL;
        a->size = 0;

	b = (t_stack*)malloc(sizeof(t_stack));
        b->top = NULL;
        b->size = 0;

	init(a, num, argc - 1);
	
	//printf("\n");
	//print_stack(a);
	if(argc <= 6)
	{
		//printf("less");
		less_than_five(a, b, argc - 1);
		print_stack(a);
		printf("Num of operations: %d", glob);
		return (1);
	}
	mv_to_b(a, b, num);
	calculate(a, b);

		
	printf("Num of operations: %d", glob);
	printf("\na, b");
	print_stack(a);
	print_stack(b);


	/*t_stack *a;
	a = (t_stack*)malloc(sizeof(t_stack));
	a->top = NULL;
	a->size = 0;

	pushing(a, 1);
	
	pushing(a, 100);
	

        t_stack *b;
        b = (t_stack*)malloc(sizeof(t_stack));
        b->top = NULL;
        b->size = 0;


	pushing(b, 13);
	pushing(b, 22);
	pushing(b, 43);
	pushing(b, 4);
	pushing(b, 12);
	pushing(b, 87);
	pushing(b, 23);
	
	print_stack(a);
	print_stack(b);
	
	//rrr(a, b);
	calculate(a, b);
	//rr(a, b);
	print_stack(a);
	print_stack(b);
	//
	//printf("min: %d", find_min(a));
	//bring_up_min(a);
	//print_stack(a);
	*/
}

void pushing(t_stack *stack, int a)
{
	//printf("\nPushing %d\n", a);
        push(stack, a);
        //printf("Size: %d\n", stack->size);
        //printf("Top: %d\n", top(stack));
}

void print_stack(t_stack *stack)
{
	t_node *temp = stack->top;
	int size = stack->size;
	//printf("\n");
	while (size > 0)
	{
		printf("%d ", temp->data);
		temp = temp->next;
		size--;
	}
	printf("\n");

}

int is_number(char *str)
{
	int i = 0;
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

int check(char *str)
{
	long num;

	if (is_number(str))
	{
		num = ft_atoi(str);
		if (num >= -2147483648 && num <= 2147483647)
			return (1);
	}	
	return (0);
}

int check_dupls(int *arr, int size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < size)
	{
		j++;
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

void init(t_stack *a, int *num, int size)
{
	int i = size - 1;
	while(i >= 0)
	{
		push(a, num[i]);
		i--;
	}
}

void mv_to_b(t_stack *a, t_stack *b, int *num)
{
	int i = 0;
	int min = num[i];
	int max = num[i];
	int size;

	while (i < a->size)
	{
		if (num[i] < min)
			min = num[i];
		if (num[i] > max)
			max = num[i];
		i++;
	}

	size = a->size - 2;
	while (b->size != size)
	{
		if (a->top->data != min && a->top->data != max)
			pb(a, b);
		ra(a);
	}
	if (a->top->data < a->top->next->data)
		ra(a);
}

void less_than_five(t_stack *a, t_stack *b, int size)
{
	if (size == 1) return;
	if (size == 2)
	{
		if (a->top->data > a->top->next->data)
			sa(a);
	}
	else if (size == 3)
		size_three(a, a->top->next->data, a->top->prev->data);
	else if (size == 4)
		size_four(a, b);
	else
		size_five(a, b);
}

void size_three(t_stack *a, int next, int prev)
{
	int top;

	top = a->top->data;
	if (top < next && top > prev)
		rra(a);
	else if	(top > next && next > prev)
	{	
		sa(a);
		rra(a);
	}
	else if(top > next && next < prev && top > prev)
		ra(a);
	else if (!(top < next && next < prev))
	{
		ra(a);
		sa(a);
		if (a->top->data < a->top->next->data)
			rra(a);
		else
			ra(a);
	}
}

void size_four(t_stack *a, t_stack *b)
{
	if (check_four_correct(a->top))
		return;
	bring_up_min(a);
	pb(a, b);
	size_three(a, a->top->next->data, a->top->prev->data);
	pa(a, b);
}

int check_four_correct(t_node *temp)
{
	int i = 1;
	while(i < 4 && temp->data < temp->next->data)
        {
                temp = temp->next;
                i++;
        }
	if (i == 4)
		return (1);
	return (0);
}
void size_five(t_stack *a, t_stack *b)
{
	if (check_four_correct(a->top->next) && a->top->data < a->top->next->data)
		return;
	bring_up_min(a);
	pb(a, b);
	size_four(a, b);
	pa(a, b);
}
