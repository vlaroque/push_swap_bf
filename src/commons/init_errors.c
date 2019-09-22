/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <louregni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 00:52:53 by vlaroque          #+#    #+#             */
/*   Updated: 2019/09/22 14:14:04 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

int		error(int i)
{
	if (i == 1)
		write(1, "Error\n", 6);
	return (0);
}

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


