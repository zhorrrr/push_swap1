#include "push_swap.h"

int	is_digit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	found_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	parse_int(char *str)
{
	int	i;
	int	sign;
	int	save;
	int	digit;

	i = 0;
	sign = 1;
	save = 0;
	if (str == NULL || str[0] == '\0')
		found_error();
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] == '\0')
		found_error();
	while (str[i] != '\0')
	{
		if (is_digit(str[i]) != 1)
			found_error();
		digit = str[i] - '0';
		if (sign == 1 && save > (INT_MAX - digit) / 10)
			found_error();
		if (sign == -1 && save > ((long)INT_MAX + 1 - digit) / 10)
			found_error();
		save = save * 10 + digit;
		i++;
	}
	return ((int)(save * sign));
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
int	count_word(char const *s, char c)
{
	size_t	i;
	size_t	found;

	i = 0;
	found = 0;
	while (s[i] != 0)
	{
		while (s[i] == c)
		{
			i++;
		}
		if (s[i] != 0)
		{
			found++;
		}
		while (s[i] != 0 && s[i] != c)
		{
			i++;
		}
	}
	return (found);
}

char	*get_word(const char *s, char c, size_t *i)
{
	size_t	len;
	size_t	j;
	size_t	start;
	char	*str;

	len = 0;
	j = 0;
	while (s[*i] == c && s[*i] != 0)
		(*i)++;
	start = *i;
	while (s[*i] && s[*i] != c)
		(*i)++;
	len = *i - start;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (j < len)
	{
		str[j++] = s[start++];
	}
	str[j] = '\0';
	return (str);
}

void	ft_free(char **result, size_t j)
{
	while (j--)
		free(result[j]);
	free(result);
}

char	**ft_split(char const *s, char c)
{
	size_t	words_count;
	size_t	j;
	size_t	i;
	char	**result;

	j = 0;
	i = 0;
	words_count = count_word(s, c);
	result = malloc((words_count + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	while (j < words_count)
	{
		result[j] = get_word(s, c, &i);
		if (result[j] == NULL)
		{
			ft_free(result, j);
			return (NULL);
		}
		j++;
	}
	result[j] = NULL;
	return (result);
}
