#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <string.h>

typedef struct s_stack
{
	int		value;
	int		index;
	struct s_stack	*next;
}	t_stack;

void	pa(t_stack **stack_a, t_stack **stack_b, int bonus);
void	pb(t_stack **stack_a, t_stack **stack_b, int bonus);

void	rotate_stack(t_stack **stack);
void	rb(t_stack **stack_b, int bonus);
void	ra(t_stack **stack_a, int bonus);
void	rr(t_stack **stack_a, t_stack **stack_b, int bonus);

void	reverse_rotate_stack(t_stack **stack);
void	rrb(t_stack **stack_b, int bonus);
void	rra(t_stack **stack_a, int bonus);
void	rrr(t_stack **stack_a, t_stack **stack_b, int bonus);

void	swap_stack(t_stack **stack);
void	sb(t_stack **stack_b, int bonus);
void	sa(t_stack **stack_a, int bonus);
void	ss(t_stack **stack_a, t_stack **stack_b, int print);

t_stack	*stack_new(int value);
void	stack_add_back(t_stack **stack, t_stack *new);
int	stack_size(t_stack *stack);
int	is_sorted(t_stack *stack);
void	free_stack(t_stack *stack);

int	position_of_index(t_stack *stack, int index);
int	get_chunk_size(int size);
int	find_max_index(t_stack *stack);

void push_chunks(t_stack **a, t_stack **b);
void push_back_to_a(t_stack **a, t_stack **b);
void push_back_to_a(t_stack **a, t_stack **b);
void chunk_sort(t_stack **a, t_stack **b);

int     *stack_to_array(t_stack *stack, size_t size);
void sort_array(int *arr, int size);
void    put_indexes(t_stack *stack, int *arr, int size);
void    assign_indexes(t_stack *stack);

void    sort_2_numbers(t_stack **stack_a);
void    sort_3_numbers(t_stack **stack_a);
int     find_min_value(t_stack *stack);
void    move_min_to_top(t_stack **stack_a);
void    sort_5_numbers(t_stack **stack_a, t_stack **stack_b);

void    sort_stack(t_stack **stack_a, t_stack **stack_b);

void free_split(char **ptr);
int parse_int(char *str);
void found_error(void);
int is_digit(int c);

char    **ft_split(char const *s, char c);
void    ft_free(char **result, size_t j);
char    *get_word(const char *s, char c, size_t *i);
int     count_word(char const *s, char c);
void    free_split(char **ptr);

#endif

