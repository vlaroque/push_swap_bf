/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 14:33:22 by vlaroque          #+#    #+#             */
/*   Updated: 2019/06/27 20:55:44 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
int		push_swap()
{
}*/


int		main(int ac, char **av)
{
	t_tab	tab;
	t_tab	*ptr;

	if(!(tab.a = init(ac, av)))
		return (0); /* ajouter l'erreur */
	tab.b = init_empty_list();
	ptr = &tab;
	print_tabs(ptr);
	algo(ptr);
	print_tabs(ptr);
	return (0);
}
