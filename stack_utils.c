#include "push_swap.h"

t_stack	*stack_new(int value)
{
	t_stack	*node;
	node = malloc(sizeof(t_stack));
	if (node == NULL)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	return (node);
}

void	stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*tmp;

	if (new == NULL)
		return ;
	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	tmp = *stack;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = new;
}

int	stack_size(t_stack *stack)
{
	int	len;

	len = 0;
	while (stack != NULL)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

int	is_sorted(t_stack *stack)
{
	t_stack	*node1;

	node1 = stack;
	if (stack == NULL || stack->next == NULL)
		return (1);
	while (node1->next != NULL)
	{
		if (node1->value > node1->next->value)
		{
			return (0);
		}
	node1 = node1->next;
	}
	return (1);
}

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;

	while (stack != 0)
        {
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}
