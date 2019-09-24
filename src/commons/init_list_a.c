/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 22:32:52 by vlaroque          #+#    #+#             */
/*   Updated: 2019/09/24 20:45:44 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

static int		add_to_list(t_list *list, int nbr)
{
	t_elem		*new;
	t_elem		*first;
	t_elem		*last;

	if (!(new = (t_elem *)malloc(sizeof(t_elem))))
		return (-1);
	if (list->size < 1)
	{
		first = new;
		last = new;
		list->start = new;
	}
	else
	{
		first = list->start;
		last = list->start->prev;
		first->prev = new;
		last->next = new;
	}
	new->nbr = nbr;
	new->data = 0;
	new->next = first;
	new->prev = last;
	list->size += 1;
	return (0);
}

static int		read_arg_atoi(char *str, int *i, int *nbr)
{
	long long	sign;

	sign = 1;
	*nbr = 0;
	while (str[*i] && str[*i] == ' ')
		(*i)++;
	if (str[*i] && (str[*i] == '-' || str[*i] == '+'))
	{
		if (str[*i] && str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	if (!(str[*i] >= '0' && str[*i] <= '9'))
		return (-1);
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		*nbr = *nbr * 10 + (str[*i] - '0');
		if (*nbr * sign > 2147483647 || *nbr * sign < -2147483648)
			return (-1);
		(*i)++;
	}
	while (str[*i] && str[*i] == ' ')
		(*i)++;
	*nbr = (int)(*nbr * sign);
	return (0);
}

static int		read_arg(t_list *list, char *str)
{
	int			i;
	int			nbr;

	i = 0;
	while (str[i])
	{
		if (read_arg_atoi(str, &i, &nbr))
			return (-1);
		if (add_to_list(list, nbr))
			return (-1);
	}
	return (0);
}

t_list			*init_list_a(int ac, char **av)
{
	int			i;
	t_list		*list;

	i = 1;
	if (!(list = (t_list *)malloc(sizeof(t_list))))
		exit(1);
	ft_bzero(list, sizeof(t_list));
	list->size = 0;
	while (i < ac)
	{
		if (read_arg(list, av[i]))
		{
			free_list(list);
			return (NULL);
		}
		i++;
	}
	if (!(post_op(list)))
	{
		free_list(list);
		return (NULL);
	}
	return (list);
}
