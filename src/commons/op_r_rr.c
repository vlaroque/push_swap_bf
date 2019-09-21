#include "push_swap.h"
#include <unistd.h>

int		rotate_a(t_tab *tab)
{
	op_add_new(&(tab->ops), RA);
	return (rotate(tab->a));
}

int		rotate_b(t_tab *tab)
{
	op_add_new(&(tab->ops), RB);
	return (rotate(tab->b));
}

int		revrotate_a(t_tab *tab)
{
	op_add_new(&(tab->ops), RRA);
	return (rev_rotate(tab->a));
}

int		revrotate_b(t_tab *tab)
{
	op_add_new(&(tab->ops), RRB);
	return (rev_rotate(tab->b));
}
