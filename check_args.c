#include "push_swap.h"

void	parse_all_args(int argc, char **argv, t_stack **stack_a)
{
	int		i;
	int		value;
	char	**numbers;
	int		j;

	i = 1;
	if (argc < 2)
		return ;
	while (i < argc)
	{
		numbers = ft_split(argv[i], ' ');
		if (numbers == NULL || numbers[0] == NULL)
			found_error();
		j = 0;
		while (numbers[j] != NULL)
		{
			value = parse_int(numbers[j]);
			stack_add_back(stack_a, stack_new(value));
			j++;
		}
		free_split(numbers);
		i++;
	}
	check_duplicates(*stack_a);
}

void	free_split(char **ptr)
{
	int	i;

	if (ptr == NULL)
		return ;
	i = 0;
	while (ptr[i] != NULL)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

int	check_duplicates(t_stack *stack_a)
{
	t_stack	*node1;
	t_stack	*node2;

	node1 = stack_a;
	while (node1 != NULL)
	{
		node2 = node1->next;
		while (node2 != NULL)
		{
			if (node1->value == node2->value)
				return (1);
			node2 = node2->next;
		}
		node1 = node1->next;
	}
	return (0);
}
