#include "push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b, int bonus)
{
	t_stack	*take_top;

	if (stack_b == NULL || *stack_b == NULL)
		return ;
	take_top = *stack_b;
	*stack_b = take_top->next;
	take_top->next = *stack_a;
	*stack_a = take_top;
	if (bonus != 0)
		write(1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b, int bonus)
{
	t_stack	*take_top;

	if (stack_a == NULL || *stack_a == NULL)
		return ;
	take_top = *stack_a;
	*stack_a = take_top->next;
	take_top->next = *stack_b;
	*stack_b = take_top;
	if (bonus != 0)
		write(1, "pb\n", 3);
}
