/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_p_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 22:54:29 by vlaroque          #+#    #+#             */
/*   Updated: 2019/09/22 22:54:43 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		push_a(t_tab *tab)
{
	op_add_new(&(tab->ops), PA);
	return (push(tab->b, tab->a));
}

int		push_b(t_tab *tab)
{
	op_add_new(&(tab->ops), PB);
	return (push(tab->a, tab->b));
}

int		swap_a(t_tab *tab)
{
	op_add_new(&(tab->ops), SA);
	return (swap(tab->a));
}

int		swap_b(t_tab *tab)
{
	op_add_new(&(tab->ops), SB);
	return (swap(tab->b));
}

int		sswap(t_tab *tab)
{
	op_add_new(&(tab->ops), SS);
	return (swap(tab->a) * swap(tab->b));
}
