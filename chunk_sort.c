#include "push_swap.h"

void push_chunks(t_stack **a, t_stack **b)
{
    int size;
    int chunk;
    int pushed;

    size = stack_size(*a);
    chunk = get_chunk_size(size);
    pushed = 0;

    while (*a)
    {
        if ((*a)->index < pushed)
        {
            pb(a, b, 1);
            rb(b, 1);
            pushed++;
        }
        else if ((*a)->index < pushed + chunk)
        {
            pb(a, b, 1);
            pushed++;
        }
        else
            ra(a, 1);
	}
}

void push_back_to_a(t_stack **a, t_stack **b)
{
    int max;
    int pos;
    int size;

    while (*b)
    {
        size = stack_size(*b);
        max = find_max_index(*b);
        pos = position_of_index(*b, max);

        if (pos <= size / 2)
        {
            while ((*b)->index != max)
                rb(b, 1);
        }
        else
        {
            while ((*b)->index != max)
                rrb(b, 1);
        }
        pa(a, b, 1);
    }
}

void chunk_sort(t_stack **a, t_stack **b)
{
    push_chunks(a, b);
    push_back_to_a(a, b);
}

