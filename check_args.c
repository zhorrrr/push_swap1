#include "push_swap.h"

void	parse_all_args(int argc, char **argv, t_stack **stack_a)
{
	int		i;
	int		value;
	char	**numbers;

	if (argc < 2)
		return ;
	if (argc == 2)
		numbers = ft_split(argv[1], ' ');
	else
		numbers = argv + 1;
	i = 0;
	while (numbers[i] != NULL)
	{
		value = parse_int(numbers[i]);
		stack_add_back(stack_a, stack_new(value));
		i++;
	}
	if (argc == 2)
		free_split(numbers);
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
