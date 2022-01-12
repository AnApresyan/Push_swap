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
	printf("\n");

	/*printf("mid number: %d", mid_num(a));
	t_stack *not_move = should_not_push(0, 98, a);
	int cheapest = next_cheapest(a, mid_num(a), not_move);
	printf("\nCheapest: %d", cheapest);
	printf("\nNot Move: ");
	print_stack(not_move);*/
	print_stack(a);
	mv_to_b(a, b, num);
	//print_stack(a);
	//printf("\n");
	//print_stack(b);

	//printf("starting main algo");
	//printf("%d", find_where_insert(a, 12));
	//calculate(a, b);
	main_algo(a, b);
		
	printf("Num of operations: %d\n", glob);
	//printf("\na, b");
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

*/
	/*pushing(a, 1);
	pushing(a, 92);
	pushing(a, 73);
	pushing(a, 58);
	pushing(a, 22);

	pushing(b, 13);
	pushing(b, 22);
	pushing(b, 43);
	pushing(b, 4);
	pushing(b, 12);
	pushing(b, 87);
	pushing(b, 23);
	
	print_stack(a);
	//insert_second_version(a, b, 2, 43);
	print_stack(b);
	printf("%d\n", find_where_insert(a, 43));
	rotate_a(a, find_where_insert(a, 43));
	insert_second_version(a, b, 2, 43);
	print_stack(a);

	print_stack(b);*/
	/*print_stack(a);
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
		j= i + 1;
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
	t_stack *not_move;

	while (i < a->size)
	{
		if (num[i] < min)
			min = num[i];
		if (num[i] > max)
			max = num[i];
		i++;
	}

	not_move = should_not_push(min, max, a);
	size = a->size - not_move->size;
	while (b->size != size)
	{	
		right_order(not_move, a, b);


		//insert_to_b(not_move, next_cheapest(), a, b);
		/*if (not_push(a->top->data, not_move))
			ra(a);
		else
			pb(a, b);*/
	}
	//bring_up_max(max, a);
}

void right_order(t_stack *not_move, t_stack *a, t_stack *b)
{
	int mid;
	int cheapest;

	mid = mid_num(a);
	cheapest = next_cheapest(a, mid, not_move);
	if(cheapest == -1)
	{
		if (not_push(a->top->data, not_move))
                        ra(a);
                else
                        pb(a, b);
	}
	else
		insert_to_b(cheapest, a, b);
		
}

/*int mid_num(t_stack *a)
{
	int i;
	int j;
	int mid;
	t_node *temp;
	int current_smallest;
	
	i = 0;
	while (i != a->size /2)
	{
		j = 1;
		temp = a->top->next;
		current_smallest = a->top->data; 
		while (j < a->size)
		{
			if ((temp->data < current_smallest || current_smallest <= mid) && (i == 0 || temp->data > mid))
				current_smallest = temp->data;
			temp = temp->next;
			j++;
		}
		mid = current_smallest;
		i++;
	}
	return (mid);
}*/

int mid_num(t_stack *a)
{
	int i;
	t_node *temp;
	int arr[a->size];

	i = 0;
	temp = a->top;
	while(i < a->size)
	{
		arr[i] = temp->data;
		i++;
		temp = temp->next;
	}
	return sort(arr, a->size);
}

int sort(int arr[], int size)
{
	int temp;
	int min;
	int i;
	int j;

	i = 0;
	while (i < size - 1)
	{
		min = i;
		j = i+1;
		while(j < size)
		{
			if (arr[j] < arr[min])
				min = j;
			j++;
		}
		temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
		i++;
	}
	return arr[size/2];
}

void insert_to_b(int cheapest, t_stack *a, t_stack *b)
{
	rotate_a(a, cheapest);
	pb(a, b);
}

int next_cheapest(t_stack *a, int mid, t_stack *not_move)
{
	int numOperations;
	t_node *temp;
	int i;
	int j;

	j = -1;
	i = 0;
	temp = a->top;
	while (i < a->size)
	{
		if (temp->data <= mid && !not_push(temp->data, not_move))
		{
			if (j == -1 || operations(a, i) < numOperations)
			{
				j = i;
				numOperations = operations(a, i);
			}
		}
		temp = temp->next;
		i++;
	}
	return (j);
}

/*void bring_up_max(int max, t_stack *a)
{
 	int i;
	t_node *temp;

	i = 0;
	temp = a->top;
	while (temp->data != max)
	{
		temp = temp->next;
		i++;
	}	
        if (i <= a->size/2)
        {
                while(i != 0)
		{
                        ra(a);
			i--;
        	}
	}
        else
	{
                while(i != a->size)
		{
                        rra(a);
			i++;
		}
	}
}*/

int not_push(int num, t_stack *stack)
{
	int i;
	t_node *temp;

	i = 0;
	temp = stack->top;
	while(i < stack->size)
	{
		if (temp->data == num)
			return (1);
		temp = temp->next;
		i++;
	}
	return (0);
}

t_stack *should_not_push(int min, int max, t_stack *a)
{
	int i;
	t_node *temp;

	i = 0;
	temp = a->top;
	while(i < a->size)
	{	
		if(temp->data == min)
			return min_to_max(max, temp);
		i++;
		temp = temp->next;
	}
	return NULL;
}

t_stack *min_to_max(int max, t_node *temp)
{

        t_stack *stack;
        stack = (t_stack*)malloc(sizeof(t_stack));
        stack->top = NULL;
        stack->size = 0;
	push(stack, temp->data);
	temp = temp->next;
        while(temp->data != max)
        {
                if (temp->data > stack->top->data && temp->data < max)
                        push(stack, temp->data);
                temp = temp->next;
        }
        push(stack, temp->data);
        return stack;
}
/*t_stack *max_to_min(int min, int max, t_node *temp)
{

        t_stack *stack;
        stack = (t_stack*)malloc(sizeof(t_stack));
        stack->top = NULL;
        stack->size = 0;
	push(stack, temp->data);
	temp = temp->next;
        while(temp->data != min)
        {
                if (temp->data < stack->top->data && temp->data > min)
                        push(stack, temp->data);
                temp = temp->next;
        }
        push(stack, temp->data);
        return stack;
}*/


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
