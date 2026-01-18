#ifndef CHECKER_H
# define CHECKER_H

#include "checker.h"
# include "push_swap.h"
# include "get_next_line.h"
# include <unistd.h>
# include <stdlib.h>

void	read_and_execute(t_stack **a, t_stack **b);
int		execute_instruction(char *line, t_stack **a, t_stack **b);
void    parse_all_args(int argc, char **argv, t_stack **a);


char		*ft_strjoin_gcl(char *s1, char *s2);
char		*get_next_line(int fd);
#endif
