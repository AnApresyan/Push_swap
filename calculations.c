#include "push_swap.h"

/*void calculate(t_stack *a, t_stack *b)
{
	int num_of_operations = -1;
	int i;
	int size;
	t_node *temp;

	while(b->size > 0)
	{
		temp = b->top;
		size = b->size;
		i = -1;
		while (size > 0)
		{
			if(temp->data < a->top->data && temp->data > a->top->prev->data)
			{
				int current_ops = (b->size - size) < (b->size)/2 ? b->size - size : size;
				if (i == -1 || current_ops < num_of_operations)
				{
					i = b->size - size;
					num_of_operations = current_ops;
				}
				if (i == 0)
					break;
			}
			temp = temp->next;
			size--;
		}
		if (i != -1)
			insert(a, b, i);
		else
			ra(a);
		//print_stack(a);
		//print_stack(b);	
	}
	bring_up_min(a);
}*/

void main_algo(t_stack *a, t_stack *b)
{
	int total_ops;
	int i;
	int j;
	t_node *temp;
	int num;

	while (b->size > 0)
	{
		i = -1;
		temp = b->top;
		j = 0;
		while(j < b->size)
		{
			if (i == -1 || operations(b, j) + operations_a(a, temp->data) < total_ops)
			{
				total_ops = operations(b, j) + operations_a(a, temp->data);
				i = j;
				num = temp->data;
			}
			temp = temp->next;
			j++;
		}
		insert_second_version(a, b, i, num);
		//print_stack(a);
	}
	bring_up_min(a);
}

void insert_second_version(t_stack *a, t_stack *b, int i, int num)
{
	rotate_b(b, i);
	rotate_a(a, find_where_insert(a, num));
	pa(a, b);
}
int operations(t_stack *stack, int i)
{
	if (i <= stack->size / 2)
		return (i);
	return (stack->size - i);
}

int operations_a(t_stack *a, int num)
{
	return (operations(a, find_where_insert(a, num)));
}

int find_where_insert(t_stack *a, int num)
{
        t_node *temp;
        int i;

        i = 0;
        temp = a->top;
        while(i < a->size)
        {
                if (num < temp->data && num > temp->prev->data)
                        break;
                temp = temp->next;
                i++;
        }
	return (i);
}
void insert(t_stack *a, t_stack *b, int i)
{
	if (i < b->size / 2)
	{
		while (i != 0)
		{
			if (i == 1)
				sb(b);
			else
				rb(b);
			//printf("l\n");	
			i--;
		}	
	}
	else
	{
		while (b->size - i != 0)
		{
			rrb(b);
			//printf("m\n");
			i++;
		}
	}
	pa(a, b);
}

void rotate_b(t_stack *b, int i)
{
        if (i <= b->size / 2)
        {
                while (i != 0)
                {
                        if (i == 1)
                                sb(b);
                        else
                                rb(b);
                        //printf("l\n");        
                        i--;
                }
        }
        else
        {
                while (b->size - i != 0)
                {
                        rrb(b);
                        //printf("m\n");
                        i++;
                }
        }
}

void rotate_a(t_stack *a, int i)
{	
        if (i < a->size / 2)
        {
                while (i != 0)
                {

			ra(a);
                        //printf("l\n");        
                        i--;
                }
        }
        else
        {
                while (a->size - i != 0)
                {
                        rra(a);
                        //printf("m\n");
                        i++;
                }
        }

}
void bring_up_min(t_stack *a)
{
	int min;
	
	min = find_min(a);

	if (min <= a->size/2)
	{
		while(min-- != 0)
			ra(a);
	}
	else
		while(min++ != a->size)
			rra(a);

}


int find_min(t_stack *a)
{
	int i = 0;
	t_node *temp = a->top;
	int temp_min = temp->data;
	int size = a->size;
	while (size > 0)
	{
		if (temp->data < temp_min)
		{
			i = a->size - size;
			temp_min = temp->data;
		}
		temp = temp->next;
		size--;
	}
	return (i);
}
