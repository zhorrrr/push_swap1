#include "checker.h"

static char	*read_bytes_stsh(int fd, char *stash)
{
	ssize_t	read_bytes;
	char	*buffer;

	buffer = malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	if (stash == NULL)
	{
		stash = ft_strdup("");
		if (!stash)
			return (free(buffer), NULL);
	}
	read_bytes = 1;
	while (ft_strchr(stash, '\n') == NULL && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes < 0)
			return (free(buffer), free(stash), NULL);
		buffer[read_bytes] = '\0';
		stash = ft_strjoin_gcl(stash, buffer);
		if (stash == NULL)
			return (free(buffer), NULL);
	}
	return (free(buffer), stash);
}

static char	*extract_theline(char *stash)
{
	char	*line;
	int		len;

	len = 0;
	if (stash == NULL || stash[0] == '\0')
		return (NULL);
	while (stash[len] != 0 && stash[len] != '\n')
	{
		len++;
	}
	if (stash[len] == '\n')
		len += 1;
	line = ft_substr(stash, 0, len);
	if (line == NULL)
		return (NULL);
	return (line);
}

static char	*left_over_stash(char *stash)
{
	char	*pp;
	int		k;

	k = 0;
	if (stash == NULL)
		return (NULL);
	while (stash[k] != '\0' && stash[k] != '\n')
	{
		k++;
	}
	if (stash[k] == '\0')
	{
		free(stash);
		return (NULL);
	}
	pp = ft_substr(stash, k + 1, ft_strlen(stash) - (k + 1));
	free(stash);
	if (pp == NULL)
		return (NULL);
	return (pp);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_bytes_stsh(fd, stash);
	if (stash == NULL)
		return (NULL);
	line = extract_theline(stash);
	stash = left_over_stash(stash);
	return (line);
}
