#include "push_swap.h"
#include <unistd.h>

int		push_a(t_tab *tab)
{
	write(1, "PA\n", 3);
	return (push(tab->b, tab->a));
}

int		push_b(t_tab *tab)
{
	write(1, "PB\n", 3);
	return (push(tab->a, tab->b));
}

int		swap_a(t_tab *tab)
{
	write(1, "SA\n", 3);
	return (swap(tab->a));
}

int		swap_b(t_tab *tab)
{
	write(1, "SB\n", 3);
	return (swap(tab->b));
}

int		sswap(t_tab *tab)
{
	write(1, "SS\n", 3);
	return(swap(tab->a) * swap(tab->b));
}
