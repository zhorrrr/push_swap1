#include "push_swap.h"

int	get_sign(char *str, int *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

int	parse_digits(char *str, int i, int sign)
{
	int	save;
	int	digit;

	save = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			found_error();
		digit = str[i] - '0';
		if (sign == 1 && save > (INT_MAX - digit) / 10)
			found_error();
		if (sign == -1 && save > ((long)INT_MAX + 1 - digit) / 10)
			found_error();
		save = save * 10 + digit;
		i++;
	}
	return (save);
}

int	parse_int(char *str)
{
	int	i;
	int	sign;
	int	value;

	if (!str || !str[0])
		found_error();
	i = 0;
	sign = get_sign(str, &i);
	if (!str[i])
		found_error();
	value = parse_digits(str, i, sign);
	return (value * sign);
}

void	found_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
