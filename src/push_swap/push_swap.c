/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 14:33:22 by vlaroque          #+#    #+#             */
/*   Updated: 2019/06/21 16:54:43 by vlaroque         ###   ########.fr       */
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
	rotate(ptr->a);
	print_tabs(ptr);
	push(ptr->a, ptr->b);
	print_tabs(ptr);
	rev_rotate(ptr->a);
	print_tabs(ptr);
	swap(ptr->a);
	print_tabs(ptr);
	printlist(ptr->a);
	push(ptr->b, ptr->a);
	print_tabs(ptr);
	return (0);
}
