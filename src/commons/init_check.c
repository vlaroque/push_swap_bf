/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <louregni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 01:23:08 by vlaroque          #+#    #+#             */
/*   Updated: 2019/10/09 20:28:57 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

int		indexator(t_list *list, int i)
{
	t_elem	**tab;
	t_elem	*elem;

	elem = list->start;
	if (!(tab = (t_elem **)malloc(sizeof(t_elem *) * list->size)))
		return (-1);
	while (++i < list->size)
	{
		tab[i] = elem;
		elem = elem->next;
	}
	quick_sort(tab, 0, list->size - 1);
	i = -1;
	while (++i < list->size)
	{
		if (i != 0 && tab[i]->nbr == tab[i - 1]->nbr)
		{
			free(tab);
			return (-1);
		}
		tab[i]->index = i;
	}
	free(tab);
	return (1);
}

int		is_ordered(t_list *list)
{
	int		i;
	t_elem	*elem;

	i = 0;
	elem = list->start;
	while (i < list->size - 1)
	{
		if (elem->nbr > elem->next->nbr)
			return (0);
		elem = elem->next;
		i++;
	}
	return (1);
}

int		post_op(t_list *list)
{
	if (indexator(list, -1) == -1)
		return (0);
	return (1);
}
