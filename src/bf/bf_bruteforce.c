#include "bf_header.h"

int		bf_is_sorted(t_tabs *tab)
{
	int i;
	int revro;

	i = 0;
	revro = tab->a_head;
	if (tab->a_lock)
	{
		if (!(tab->a_head & (tab->a_max >> 1)))
			return (0);
		while (revro > 1)
		{
			bf_revrotate_a(tab);
			revro >>= 1;
		}
	}
	if (!(tab->b_max & 1))
		return (0);
	while (tab->a_max > 1 << i)
	{
		if (tab->a[i] != 1 << i)
			return (0);
		i++;
	}
	return (1);
}

int		bf_seed_try(t_tabs *tab, int *seed)
{
	int		i;
	t_tabs	save;
	t_tabs	*try;
	int		res;

	save = *tab;
	try = &save;
	i = 0;
	res = 0;
	while (seed[i])
	{
		if (seed[i] & PB)
			res = bf_push_b(try);
		else if (seed[i] & PA)
			res = bf_push_a(try);
		else if (seed[i] & RA)
			res = bf_rotate_a(try);
		else if (seed[i] & RB)
			res = bf_rotate_b(try);
		else if (seed[i] & RR)
			res = bf_rotate_ab(try);
		else if (seed[i] & RRA)
			res = bf_revrotate_a(try);
		else if (seed[i] & RRB)
			res = bf_revrotate_b(try);
		else if (seed[i] & RRR)
			res = bf_revrotate_ab(try);
		else if (seed[i] & SA)
			res = bf_swap_a(try);
		else if (seed[i] & SB)
			res = bf_swap_b(try);
		else if (seed[i] & SS)
			res = bf_swap_ab(try);
		else
			return (printf("FTW\n"));
		if (res == 0)
			return (0);
		i++;
	}
	if (bf_is_sorted(try))
	{
		printf("tab = ");
		bf_printtab(try);
		printf("seed = ");
		bf_printseed(seed);
		printf("solution trouvee\n");
		return (1);
	}
	return (0);
}

int		bf_seed_generator(t_tabs *tab, int *seed, int head, int len)
{
	int		op;

	op = 1;
	if (head == len)
	{
		if (bf_seed_try(tab, seed))
		{
			bf_printseed(seed);
			return (1);
		}
		return (0);
	}
	else
	{
		while (op < END)
		{
			seed[head] = op;
			if (bf_seed_generator(tab, seed, head + 1, len))
				return (1);
			op <<= 1;
		}
	}
	return (0);
}

int		bruteforce(t_tabs *tab)
{
	int	seed[SEEDLEN] = {0};
	int seedlen;

	seedlen = 0;
	while(seedlen < 10)
	{
		if(bf_seed_generator(tab, seed, 0, seedlen))
			break ;
		seedlen++;
	}
}
