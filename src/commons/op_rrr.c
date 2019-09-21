#include "push_swap.h"
#include <unistd.h>

int		rrotate(t_tab *tab)
{
	op_add_new(&(tab->ops), RR);
	//write(1, "rr\n", 3);
	return(rotate(tab->a) * rotate(tab->b));
}

int		rrevrotate(t_tab *tab)
{
	op_add_new(&(tab->ops), RRR);
	//write(1, "rrr\n", 4);
	return(rev_rotate(tab->a) * rev_rotate(tab->b));
}
