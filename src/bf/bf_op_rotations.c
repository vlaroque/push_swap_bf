/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_op_rotations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 14:26:54 by vlaroque          #+#    #+#             */
/*   Updated: 2019/09/24 14:31:11 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bf_header.h"

int		bf_rotate_a(t_tabs *tab)
{
	int i;

	i = 0;
	if (tab->a_lock && (tab->a_head == tab->a_max))
		return (0);
	if (tab->a_max <= 2)
		return (0);
	while (i < TABLEN)
	{
		if (tab->a[i] == 1)
			tab->a[i] = tab->a_max >> 1;
		else if (tab->a[i])
			tab->a[i] >>= 1;
		i++;
	}
	tab->a_head <<= 1;
	return (1);
}

int		bf_rotate_b(t_tabs *tab)
{
	int i;

	i = 0;
	if (tab->b_max <= 2)
		return (0);
	while (i < TABLEN)
	{
		if (tab->b[i] == 1)
			tab->b[i] = tab->b_max >> 1;
		else if (tab->a[i])
			tab->b[i] >>= 1;
		i++;
	}
	return (1);
}

int		bf_revrotate_a(t_tabs *tab)
{
	int i;

	i = 0;
	if (tab->a_lock && (tab->a_head == 1))
		return (0);
	if (tab->a_max <= 2)
		return (0);
	while (i < TABLEN)
	{
		tab->a[i] = tab->a[i] << 1;
		if (tab->a[i] == tab->a_max)
			tab->a[i] = 1;
		i++;
	}
	tab->a_head >>= 1;
	return (1);
}

int		bf_revrotate_b(t_tabs *tab)
{
	int i;

	i = 0;
	if (tab->b_max <= 2)
		return (0);
	while (i < TABLEN)
	{
		tab->b[i] = tab->b_max << 1;
		if (tab->b[i] == tab->b_max)
			tab->b[i] = 1;
		i++;
	}
	return (1);
}
