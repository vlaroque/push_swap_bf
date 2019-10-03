/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_r_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 22:55:00 by vlaroque          #+#    #+#             */
/*   Updated: 2019/09/22 22:55:23 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		rotate_a(t_tab *tab)
{
	op_add_new(&(tab->ops), RA);
	return (rotate(tab->a));
}

int		rotate_b(t_tab *tab)
{
	op_add_new(&(tab->ops), RB);
	return (rotate(tab->b));
}

int		revrotate_a(t_tab *tab)
{
	op_add_new(&(tab->ops), RRA);
	return (rev_rotate(tab->a));
}

int		revrotate_b(t_tab *tab)
{
	op_add_new(&(tab->ops), RRB);
	return (rev_rotate(tab->b));
}
