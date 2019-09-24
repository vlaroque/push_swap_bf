/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 19:18:19 by vlaroque          #+#    #+#             */
/*   Updated: 2019/09/24 19:20:34 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "bf_header.h"

void	read_seed(int *seed, t_tab *tab, int i)
{
	while (seed[++i] && i < SEEDLEN)
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
	}
}

int		init_a_unlocked_bf(int *cmb, int len, t_tab *piles)
{
	int		i;
	t_tabs	tab;
	int		seed[SEEDLEN];

	ft_bzero(seed, sizeof(int) * SEEDLEN);
	ft_bzero(&tab, sizeof(t_tabs));
	i = 0;
	while (i < len)
	{
		tab.a[cmb[i] - 1] = 1 << i;
		i++;
	}
	tab.a_max = 1 << len;
	tab.b_max = 1;
	tab.a_lock = 0;
	tab.a_head = 1;
	rec_bruteforce(&tab, seed);
	read_seed(seed, piles, -1);
	return (1);
}
