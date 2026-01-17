#include "push_swap.h"

int position_of_index(t_stack *stack, int index)
{
    int pos = 0;

	while (stack)
	{
		if (stack->index == index)
			return (pos);
		stack = stack->next;
		pos++;
    	}
	return (-1);
}

int	get_chunk_size(int size)
{
	if (size <= 100)
		return (15);
	return (30);
}

int find_max_index(t_stack *stack)
{
    int max;

    max = stack->index;
    while (stack)
    {
        if (stack->index > max)
            max = stack->index;
        stack = stack->next;
    }
    return (max);
}

