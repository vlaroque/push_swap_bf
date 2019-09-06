#include "bf_header.h"

/*
 * a_lock don't care about the last position
 */

int     init_bf(int *cmb, int len)
{
	int i;
	t_tabs  tab;

	bzero(&tab, sizeof(t_tabs));
	i = 0;
	while(i < len)
	{
		tab.a[cmb[i] - 1] = 1 << i;
		i++;
	}
	tab.a_max = 1 << len;
	tab.b_max = 1;
	tab.a_lock = 1;
	tab.a_head = 1;
	rec_bruteforce(&tab);
}

int     init_a_unlocked_bf(int *cmb, int len)
{
	int i;
	t_tabs  tab;

	bzero(&tab, sizeof(t_tabs));
	i = 0;
	while(i < len)
	{
		tab.a[cmb[i] - 1] = 1 << i;
		i++;
	}
	tab.a_max = 1 << len;
	tab.b_max = 1;
	tab.a_lock = 0;
	tab.a_head = 1;
	rec_bruteforce(&tab);
}

int     init_a_locked_bf(int *cmb, int len)
{
	int i;
	t_tabs  tab;

	bzero(&tab, sizeof(t_tabs));
	i = 0;
	while(i < len)
	{
		tab.a[cmb[i] - 1] = 1 << i;
		i++;
	}
	tab.a_max = 1 << len;
	tab.b_max = 1;
	tab.a_lock = 1;
	tab.a_head = 1;
	rec_bruteforce(&tab);
}

int     init_b_locked_bf(int *cmb, int len)
{
	int i;
	t_tabs  tab;

	bzero(&tab, sizeof(t_tabs));
	i = 0;
	while(i < len)
	{
		tab.a[cmb[i] - 1] = 1 << i;
		i++;
	}
	tab.a_max = 1 << len;
	tab.b_max = 1;
	tab.a_lock = 1;
	tab.a_head = 1;
	rec_bruteforce(&tab);
}
