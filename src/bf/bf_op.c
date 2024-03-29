/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 14:24:07 by vlaroque          #+#    #+#             */
/*   Updated: 2019/09/24 20:45:50 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bf_header.h"

int		bf_push_a(t_tabs *tab)
{
	int i;

	i = 0;
	if (tab->b_max <= 1)
		return (0);
	while (i < TABLEN)
	{
		tab->a[i] <<= 1;
		if (tab->b[i] == 1)
			tab->a[i] = 1;
		tab->b[i] >>= 1;
		i++;
	}
	tab->a_max <<= 1;
	tab->b_max >>= 1;
	return (1);
}

int		bf_push_b(t_tabs *tab)
{
	int i;

	i = 0;
	if (tab->a_lock && (tab->a_head & tab->a_max))
		return (0);
	if (tab->a_max <= 1)
		return (0);
	while (i < TABLEN)
	{
		tab->b[i] <<= 1;
		if (tab->a[i] == 1)
			tab->b[i] = 1;
		tab->a[i] >>= 1;
		i++;
	}
	tab->a_max >>= 1;
	tab->b_max <<= 1;
	return (1);
}

int		bf_swap_a(t_tabs *tab)
{
	int i;

	i = 0;
	if (tab->a_lock && (tab->a_head >= (tab->a_max >> 1)))
		return (0);
	if (tab->a_max < 3)
		return (0);
	while (i < TABLEN)
	{
		if (tab->a[i] == 1)
			tab->a[i] = 2;
		else if (tab->a[i] == 2)
			tab->a[i] = 1;
		i++;
	}
	return (1);
}

int		bf_swap_b(t_tabs *tab)
{
	int i;

	i = 0;
	if (tab->b_max < 3)
		return (0);
	while (i < TABLEN)
	{
		if (tab->b[i] == 1)
			tab->b[i] = 2;
		else if (tab->b[i] == 2)
			tab->b[i] = 1;
		i++;
	}
	return (1);
}
