#include "push_swap.h"

void	rotate_stack(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
}

void	rb(t_stack **stack_b, int bonus)
{
	rotate_stack(stack_b);
	if (bonus != 0)
		write(1, "rb\n", 3);
}

void	ra(t_stack **stack_a, int bonus)
{
	rotate_stack(stack_a);
	if (bonus != 0)
		write(1, "ra\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b, int bonus)
{
	rotate_stack(stack_a);
	rotate_stack(stack_b);
	if (bonus != 0)
		write(1, "rr\n", 3);
}
