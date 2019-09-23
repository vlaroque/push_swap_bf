/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_distances.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 23:04:42 by vlaroque          #+#    #+#             */
/*   Updated: 2019/09/22 23:05:55 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		dist_neg_pivot(t_list *list, int pivot)
{
	t_elem	*head;
	int		dist;
	int		res;

	res = 0;
	dist = 0;
	head = list->start;
	while (head->data != PIVOT)
	{
		if (head->index <= pivot)
			res = dist;
		head = head->prev;
		dist++;
		if (head == list->start)
			break ;
	}
	printf("dist neg pivot = %d\n", res);
	return (res);
}

int		dist_pivot(t_list *list, int pivot, char p_m)
{
	t_elem	*head;
	int		dist;
	int		res;

	res = 0;
	dist = 0;
	head = list->start;
	while (head->data != PIVOT)
	{
		if (p_m == '-' && head->index <= pivot)
			res = dist;
		else if (p_m == '+' && head->index >= pivot)
			res = dist;
		head = head->next;
		dist++;
		if (head == list->start)
			break ;
	}
	return (res);
}

int		rev_dist_pivot(t_list *list, int pivot, char p_m)
{
	t_elem	*head;
	int		dist;
	int		res;

	res = 0;
	dist = 0;
	head = list->start;
	while (head->data != PIVOT)
	{
		if (p_m == '-' && head->index <= pivot)
			res = dist;
		else if (p_m == '+' && head->index >= pivot)
			res = dist;
		head = head->prev;
		dist++;
		if (head == list->start)
			break ;
	}
	return (res);
}

int		best_dist(int pos, int neg)
{
	if (pos <= neg)
		return (pos + 1);
	else
		return (-(neg + 1));
}
