#include "push_swap.h"
#include <unistd.h>

int		rrotate(t_tab *tab)
{
	op_add_new(&(tab->ops), RR);
	return(rotate(tab->a) * rotate(tab->b));
}

int		rrevrotate(t_tab *tab)
{
	op_add_new(&(tab->ops), RRR);
	return(rev_rotate(tab->a) * rev_rotate(tab->b));
}
