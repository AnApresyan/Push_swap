#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>


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
int calculate(t_stack *a, t_stack *b);
void insert(t_stack *a, t_stack *b, int i);
void bring_up_min(t_stack *a);
int find_min(t_stack *a);
#endif
