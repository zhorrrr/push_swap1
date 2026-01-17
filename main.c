#include "push_swap.h"

static void	init_stack_from_args(int argc, char **argv, t_stack **a)
{
	int		i;
	int		j;
	int		value;
	char	**split;

	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			found_error();
		j = 0;
		while (split[j])
		{
			value = parse_int(split[j]);
			stack_add_back(a, stack_new(value));
			j++;
		}
		free_split(split);
		i++;
	}
}

static int	has_duplicates(t_stack *stack)
{
	t_stack	*i;
	t_stack	*j;

	i = stack;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->value == j->value)
				return (1);
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);

	init_stack_from_args(argc, argv, &a);

	if (has_duplicates(a))
	{
		free_stack(a);
		found_error();
	}

	assign_indexes(a);

	if (!is_sorted(a))
		sort_stack(&a, &b);

	free_stack(a);
	return (0);
}

