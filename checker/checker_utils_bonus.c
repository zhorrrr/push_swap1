#include "checker.h"

void read_and_execute(t_stack **a, t_stack **b)
{
    char *line;

    line = get_next_line(0);
    while (line != NULL)
    {
        if (execute_instruction(line, a, b) == 0)
        {
            write(2, "Error\n", 6);
            free(line);
            exit(1);
        }
        free(line);
        line = get_next_line(0);
    }
}

int    execute_instruction(char *line, t_stack **a, t_stack **b)
{
    if (line == NULL)
        found_error();

    if (strcmp(line, "sa\n") == 0)
        sa(a, 0);
    else if (strcmp(line, "sb\n") == 0)
        sb(b, 0);
    else if (strcmp(line, "ss\n") == 0)
        ss(a, b, 0);
    else if (strcmp(line, "pa\n") == 0)
        pa(a, b, 0);
    else if (strcmp(line, "pb\n") == 0)
        pb(a, b, 0);
    else if (strcmp(line, "ra\n") == 0)
        ra(a, 0);
    else if (strcmp(line, "rb\n") == 0)
        rb(b, 0);
    else if (strcmp(line, "rr\n") == 0)
        rr(a, b, 0);
    else if (strcmp(line, "rra\n") == 0)
        rra(a, 0);
    else if (strcmp(line, "rrb\n") == 0)
        rrb(b, 0);
    else if (strcmp(line, "rrr\n") == 0)
        rrr(a, b, 0);
    else
        return (0);
    return (1);
}