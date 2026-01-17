#include "push_swap.h"

int	*stack_to_array(t_stack *stack, size_t size)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * size);
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (stack != NULL)
	{
		arr[i] = stack->value;
		stack = stack->next;
		i++;
	}
	return (arr);
}

void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	put_indexes(t_stack *stack, int *arr, int size)
{
	int	i;

	while (stack != 0)
	{
		i = 0;
		while (i < size)
		{
			if (stack->value == arr[i])
			{
				stack->index = i;
				break ;
			}
			i++;
		}
		stack = stack->next;
	}
}

void	assign_indexes(t_stack *stack)
{
	int	*arr;
	int	size;

	size = stack_size(stack);
	arr = stack_to_array(stack, size);
	if (arr == NULL)
		return ;
	sort_array(arr, size);
	put_indexes(stack, arr, size);
	free(arr);
}
