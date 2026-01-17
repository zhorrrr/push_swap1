#include "push_swap.h"

void	sort_2_numbers(t_stack **stack_a)
{
	if (stack_a == NULL || *stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a, 1);
}

void	sort_3_numbers(t_stack **stack_a)
{
	int	j;
	int	i;
	int	x;

	if (stack_a == NULL || *stack_a == NULL || is_sorted(*stack_a) == 1)
		return ;
	if ((*stack_a)->next == NULL || (*stack_a)->next->next == NULL)
		return ;
	j = (*stack_a)->value;
	i = (*stack_a)->next->value;
	x = (*stack_a)->next->next->value;
	sort_3_cases(stack_a, j, i, x);
}

void	sort_3_cases(t_stack **stack_a, int j, int i, int x)
{
	if (j < i && i > x && j > x)
		rra(stack_a, 1);
	else if (j > i && i < x && j > x)
		ra(stack_a, 1);
	else if (j > i && i > x)
	{
		sa(stack_a, 1);
		rra(stack_a, 1);
	}
	else if (j > i && i < x && j < x)
		sa(stack_a, 1);
	else if (j < i && i > x && j < x)
	{
		sa(stack_a, 1);
		ra(stack_a, 1);
	}
}
