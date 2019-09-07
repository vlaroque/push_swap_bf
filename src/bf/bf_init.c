#include "push_swap.h"
#include "bf_header.h"

/*
 * a_lock don't care about the last position
 */

void	read_seed(int *seed, t_tab *tab)
{
	int i;

	i = 0;
	while(seed[i] && i < SEEDLEN)
	{
		if (seed[i] == PA)
			push_a(tab);
		else if (seed[i] == PB)
			push_b(tab);
		else if (seed[i] == SA)
			swap_a(tab);
		else if (seed[i] == SB)
			swap_b(tab);
		else if (seed[i] == SS)
			sswap(tab);
		else if (seed[i] == RA)
			rotate_a(tab);
		else if (seed[i] == RB)
			rotate_b(tab);
		else if (seed[i] == RR)
			rrotate(tab);
		else if (seed[i] == RRA)
			revrotate_a(tab);
		else if (seed[i] == RRB)
			revrotate_b(tab);
		else if (seed[i] == RRR)
			rrevrotate(tab);
		i++;
	}
}

int     init_bf(int *cmb, int len)
{
	int		i;
	t_tabs	tab;
	int		seed[SEEDLEN] = {0};

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
	rec_bruteforce(&tab, seed);
}

int     init_a_unlocked_bf(int *cmb, int len, t_tab *piles)
{
	int		i;
	t_tabs	tab;
	int		seed[SEEDLEN] = {0};

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
	rec_bruteforce(&tab, seed);
}

int     init_a_locked_bf(int *cmb, int len, t_tab *piles)
{
	int		i;
	t_tabs	tab;
	int		seed[SEEDLEN] = {0};

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
	//printf("nbr send %d | %d | %d | %d| %d  len = %d\n", cmb[0], cmb[1], cmb[2], cmb[3], cmb[4], len);
	rec_bruteforce(&tab, seed);
	read_seed(seed, piles);
	return (1);
}

int     init_b_locked_bf(int *cmb, int len, t_tab *piles)
{
	int		i;
	t_tabs	tab;
	int		seed[SEEDLEN] = {0};

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
	rec_bruteforce(&tab, seed);
}
