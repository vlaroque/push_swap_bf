#include "push_swap.h"
#include <unistd.h>

int		rotate_a(t_tab *tab)
{
	write(1, "ra\n", 3);
	return (rotate(tab->a));
}

int		rotate_b(t_tab *tab)
{
	write(1, "rb\n", 3);
	return (rotate(tab->b));
}

int		revrotate_a(t_tab *tab)
{
	write(1, "rra\n", 4);
	return (rev_rotate(tab->a));
}

int		revrotate_b(t_tab *tab)
{
	write(1, "rrb\n", 4);
	return (rev_rotate(tab->b));
}
