/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <louregni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 01:23:08 by vlaroque          #+#    #+#             */
/*   Updated: 2019/06/27 20:44:34 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

int		indexator(t_list *list)
{
	t_elem	**tab;
	int		i;
	t_elem	*elem;

	i = 0;
	elem = list->start;
	if (!(tab = malloc(sizeof(t_elem *) * list->size)))
		return (-1);
	while (i < list->size)
	{
		tab[i] = elem;
		elem = elem->next;
		i++;
	}
	quick_sort(tab, 0, list->size - 1);
	i = -1;
	while (++i < list->size)
		tab[i]->index = i;
	return (1);
}

int		is_ordered(t_list *list)
{
	int		i;
	t_elem	*elem;

	i = 0;
	elem = list->start;
	while(i < list->size - 1)
	{
		if (elem->nbr > elem->next->nbr)
			return (0);
		i++;
	}
	return (1);
}

int		post_op(t_list *list)
{
	if (is_ordered(list))
		return (-1);
	indexator(list);
	return (1);
}
