#include "push_swap.h"

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	if (stack_a == NULL || *stack_a == NULL)
		return ;
	size = stack_size(*stack_a);
	if (size <= 1)
		return ;
	if (size == 2)
		sort_2_numbers(stack_a);
	else if (size == 3)
		sort_3_numbers(stack_a);
	else if (size <= 5)
		sort_5_numbers(stack_a, stack_b);
	else
		chunk_sort(stack_a, stack_b);
}

