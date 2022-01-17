#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "./libft/libft.h"

# define BUFFER_SIZE 1

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}			t_node;

typedef struct s_stack
{
	int				size;
	struct s_node	*top;
}			t_stack;

int			top(t_stack *stack);
int			pop(t_stack *stack);
int			find_min(t_stack *a);
int			is_number(char *str);
int			check(char *str);
int			check_dupls(int *arr, int size);
int			check_four_correct(t_node *temp);
int			operations(t_stack *stack, int i);
int			operations_a(t_stack *a, int num);
int			find_where_insert(t_stack *a, int num);
int			not_push(int num, t_stack *stack);
int			mid_num(t_stack *a);
int			next_cheapest(t_stack *a, int mid, t_stack *not_move);
int			sort(int arr[], int size);
int			error_message(void);
//int			get_next_line(char **line);
int			same(char *line, char *command);
int			get_next_line(int fd, char **line);
char		*ft_strjoin_gln(char *s1, char *s2);
//char		*ft_strchr(char *s, int c);
size_t		ft_strlen_gln(char *str);
char		*leftover(char *tmp);
char		*the_line(char *tmp);
void		push(t_stack *stack, int a);
void		print_stack(t_stack *stack);
void		swap(t_stack *stack);
void		sa(t_stack *a, int print);
void		sb(t_stack *b, int print);
void		ss(t_stack *a, t_stack *b, int print);
void		pa(t_stack *a, t_stack *b, int print);
void		pb(t_stack *a, t_stack *b, int print);
void		ra(t_stack *a, int print);
void		rb(t_stack *b, int print);
void		rr(t_stack *a, t_stack *b, int print);
void		rra(t_stack *a, int print);
void		rrb(t_stack *b, int print);
void		rrr(t_stack *a, t_stack *b, int print);
void		insert(t_stack *a, t_stack *b, int i);
void		bring_up_min(t_stack *a);
void		init(t_stack *a, int *num, int size);
void		mv_to_b(t_stack *a, t_stack *b, int *num);
void		less_than_five(t_stack *a, t_stack *b, int size);
void		size_three(t_stack *a, int next, int prev);
void		size_four(t_stack *a, t_stack *b);
void		size_five(t_stack *a, t_stack *b);
void		main_algo(t_stack *a, t_stack *b);
void		insert_second_version(t_stack *a, t_stack *b, int i, int num);
void		rotate_b(t_stack *b, int i);
void		rotate_a(t_stack *a, int i);
void		bring_up_max(int max, t_stack *a);
void		right_order(t_stack *not_move, t_stack *a, t_stack *b);
void		insert_to_b(int cheapest, t_stack *a, t_stack *b);
void		main_helper(int argc, t_stack *a, t_stack *b, int *num);
void		checker(t_stack *a);
void		errors_and_elements(int argc, char **argv, int *num);
void		read_commands(char *line, t_stack *a, t_stack *b);
t_stack		*init_stack(void);
t_stack		*should_not_push(int min, int max, t_stack *a);
t_stack		*min_to_max(int max, t_node *temp);
#endif
