#include "push_swap.h"

void	reverse_rotate_stack(t_stack **stack)
{
	t_stack	*before_last;
	t_stack	*last;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	before_last = *stack;
	while (before_last->next->next != NULL)
		before_last = before_last->next;
	last = before_last->next;
	before_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_stack **stack_a, int bonus)
{
	reverse_rotate_stack(stack_a);
	if (bonus != 0)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b, int bonus)
{
	reverse_rotate_stack(stack_b);
	if (bonus != 0)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b, int bonus)
{
	reverse_rotate_stack(stack_a);
	reverse_rotate_stack(stack_b);
	if (bonus != 0)
		write(1, "rrr\n", 4);
}
