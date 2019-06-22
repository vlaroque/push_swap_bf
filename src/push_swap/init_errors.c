/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <louregni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 00:52:53 by vlaroque          #+#    #+#             */
/*   Updated: 2019/06/21 09:32:25 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	printlist(t_list *list)
{
	t_elem	*elem;
	int i = 0;

	elem = list->start;
	while (i < list->size)
	{
		printf("%10d <<< %10d >>> %10d ind = %d\n", elem->prev->nbr, elem->nbr, elem->next->nbr, elem->index);
		elem = elem->next;
		i++;
	}
}

void	free_list(t_list *list)
{
	int		i;
	t_elem	*elem;
	t_elem	*next;

	i = 0;
	elem = list->start;
	while (i < list->size)
	{
		next = elem->next;
		free(elem);
		elem = next;
		i++;
	}
	free(list);
}
