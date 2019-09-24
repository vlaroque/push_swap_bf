/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_op_dbl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 14:23:54 by vlaroque          #+#    #+#             */
/*   Updated: 2019/09/24 14:26:22 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bf_header.h"

int		bf_rotate_ab(t_tabs *tab)
{
	return (bf_rotate_a(tab) * bf_rotate_b(tab));
}

int		bf_revrotate_ab(t_tabs *tab)
{
	return (bf_revrotate_a(tab) * bf_revrotate_b(tab));
}

int		bf_swap_ab(t_tabs *tab)
{
	return (bf_swap_a(tab) * bf_swap_b(tab));
}
