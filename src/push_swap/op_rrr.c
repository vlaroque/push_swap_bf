#include "push_swap.h"
#include <unistd.h>

int		rrotate(t_tab *tab)
{
	write(1, "rr\n", 3);
	return(rotate(tab->a) * rotate(tab->b));
}

int		rrevrotate(t_tab *tab)
{
	write(1, "rrr\n", 4);
	return(rev_rotate(tab->a) * rev_rotate(tab->b));
}
