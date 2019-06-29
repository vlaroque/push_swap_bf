#include "push_swap.h"
#include <unistd.h>

int		rotate_a(t_tab *tab)
{
	write(1, "RA\n", 3);
	return (rotate(tab->a));
}

int		rotate_b(t_tab *tab)
{
	write(1, "RB\n", 3);
	return (rotate(tab->b));
}

int		revrotate_a(t_tab *tab)
{
	write(1, "RRA\n", 4);
	return (rev_rotate(tab->a));
}

int		revrotate_b(t_tab *tab)
{
	write(1, "RRB\n", 4);
	return (rev_rotate(tab->b));
}
