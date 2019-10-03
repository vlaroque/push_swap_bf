/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 19:43:41 by vlaroque          #+#    #+#             */
/*   Updated: 2019/10/03 15:25:24 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

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

void	free_both_lists(t_tab *tab)
{
	free_list(tab->a);
	free_list(tab->b);
}

void	free_op_list(t_op **begin)
{
	t_op	*next;
	t_op	*head;

	if (begin == NULL)
		return ;
	head = *begin;
	while (head != NULL)
	{
		next = head->next;
		free(head);
		head = next;
	}
}
