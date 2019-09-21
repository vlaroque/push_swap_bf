#include "push_swap.h"
#include <unistd.h>

int		push_a(t_tab *tab)
{
	op_add_new(&(tab->ops), PA);
	//write(1, "pa\n", 3);
	return (push(tab->b, tab->a));
}

int		push_b(t_tab *tab)
{
	op_add_new(&(tab->ops), PB);
	//write(1, "pb\n", 3);
	return (push(tab->a, tab->b));
}

int		swap_a(t_tab *tab)
{
	op_add_new(&(tab->ops), SA);
	//write(1, "sa\n", 3);
	return (swap(tab->a));
}

int		swap_b(t_tab *tab)
{
	op_add_new(&(tab->ops), SB);
	//write(1, "sb\n", 3);
	return (swap(tab->b));
}

int		sswap(t_tab *tab)
{
	op_add_new(&(tab->ops), SS);
	//write(1, "ss\n", 3);
	return(swap(tab->a) * swap(tab->b));
}
