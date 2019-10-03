/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 22:52:58 by vlaroque          #+#    #+#             */
/*   Updated: 2019/09/22 23:00:49 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		rrotate(t_tab *tab)
{
	op_add_new(&(tab->ops), RR);
	return (rotate(tab->a) * rotate(tab->b));
}

int		rrevrotate(t_tab *tab)
{
	op_add_new(&(tab->ops), RRR);
	return (rev_rotate(tab->a) * rev_rotate(tab->b));
}
