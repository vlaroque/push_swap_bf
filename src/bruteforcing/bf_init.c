#include "header.h"

int     init_bf(int *cmb, int len)
{
	int i;
	t_tabs  tab;

	bzero(&tab, sizeof(t_tabs));
	i = 0;
	while(i < len)
	{
		tab.b[cmb[i] - 1] = 1 << i;
		i++;
	}
	tab.b_max = 1 << len;
	tab.a_max = 1;
	tab.a_lock = 1;
	tab.a_head = 1;
	bf_printtab(&tab);
	rec_bruteforce(&tab);
}
