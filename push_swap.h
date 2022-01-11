#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include "./libft/libft.h"

typedef struct s_node
{
	int data;
	struct s_node *next;
	struct s_node *prev;
}	t_node;

typedef struct s_stack
{
	int size;
	struct s_node *top;
}	t_stack;


int top(t_stack *stack);
int pop(t_stack *stack);
void push(t_stack *stack, int a);
void pushing(t_stack *stack, int a);
//void popping(t_stack *stack);
void print_stack(t_stack *stack);
void sa(t_stack *a);
void sb(t_stack *b);
void ss(t_stack *a, t_stack *b);
void pa(t_stack *a, t_stack *b);
void pb(t_stack *a, t_stack *b);
void ra(t_stack *a);
void rb(t_stack *b);
void rr(t_stack *a, t_stack *b);
void rra(t_stack *a);
void rrb(t_stack *b);
void rrr(t_stack *a, t_stack *b);
//void calculate(t_stack *a, t_stack *b);
void insert(t_stack *a, t_stack *b, int i);
void bring_up_min(t_stack *a);
int find_min(t_stack *a);
int is_number(char *str);
int check(char *str);
int check_dupls(int *arr, int size);
void init(t_stack *a, int *num, int size);
void mv_to_b(t_stack *a, t_stack *b, int *num);
void less_than_five(t_stack *a, t_stack *b, int size);
void size_three(t_stack *a, int next, int prev);
void size_four(t_stack *a, t_stack *b);
int check_four_correct(t_node *temp);
void size_five(t_stack *a, t_stack *b);
void main_algo(t_stack *a, t_stack *b);
void insert_second_version(t_stack *a, t_stack *b, int i, int num);
int operations(t_stack *stack, int i);
int operations_a(t_stack *a, int num);
int find_where_insert(t_stack *a, int num);
void rotate_b(t_stack *b, int i);
void rotate_a(t_stack *a, int i);
int not_push(int num, t_stack *stack);
t_stack *should_not_push(int min, int max, t_stack *a);
t_stack *min_to_max(int min, int max, t_node *temp);
t_stack *max_to_min(int min, int max, t_node *temp);
void bring_up_max(int max, t_stack *a);
#endif
