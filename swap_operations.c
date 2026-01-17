#include "push_swap.h"

void	swap_stack(t_stack **stack)
{
	t_stack	*node1;
	t_stack	*node2;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	node1 = *stack;
	node2 = node1->next;
	node1->next = node2->next;
	node2->next = node1;
	*stack = node2;
}

void	sa(t_stack **stack_a, int bonus)
{
	swap_stack(stack_a);
	if (bonus != 0)
		write(1, "sa\n", 3);
}

void	sb(t_stack **stack_b, int bonus)
{
	swap_stack(stack_b);
	if (bonus != 0)
		write(1, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b, int print)
{
	swap_stack(stack_a);
	swap_stack(stack_b);
	if (print != 0)
		write(1, "ss\n", 3);
}
