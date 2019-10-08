/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 23:13:26 by vlaroque          #+#    #+#             */
/*   Updated: 2019/09/22 23:24:59 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	is_pivot(t_elem *elem)
{
	elem->data = PIVOT;
}

int		choose_pivot(t_list *list)
{
	t_elem	*head;
	int		min;
	int		max;

	head = list->start;
	min = head->index;
	max = head->index;
	while (head->data != PIVOT)
	{
		if (head->nbr < min)
			min = head->index;
		if (head->nbr > max)
			max = head->index;
		head = head->next;
		if (head == list->start)
			break ;
	}
	return ((min + max) / 2);
}
