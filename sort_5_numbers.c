#include "push_swap.h"

int	find_min_value(t_stack *stack)
{
	int	min;

	if (stack == NULL)
		return (0);
	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

int	find_index_value(t_stack *stack, int value)
{
	int	index;

	index = 0;
	while (stack)
	{
		if (stack->value == value)
			return (index);
		stack = stack->next;
		index++;
	}
	return (-1);
}

void	move_min_to_top(t_stack **stack_a)
{
	int	min;
	int	index;
	int	size;

	min = find_min_value(*stack_a);
	index = find_index_value(*stack_a, min);
	size = stack_size(*stack_a);
	if (index <= size / 2)
	{
		while ((*stack_a)->value != min)
			ra(stack_a, 1);
	}
	else
	{
		while ((*stack_a)->value != min)
			rra(stack_a, 1);
	}
}

void	sort_5_numbers(t_stack **stack_a, t_stack **stack_b)
{
	while (stack_size(*stack_a) > 3)
	{
		move_min_to_top(stack_a);
		pb(stack_a, stack_b, 1);
	}
	sort_3_numbers(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b, 1);
}
