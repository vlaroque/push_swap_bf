/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 22:49:29 by vlaroque          #+#    #+#             */
/*   Updated: 2019/09/15 22:54:10 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "push_swap.h"

static int		exec_read_four(char *buff, t_tab *tab)
{
	if (!(buff[0] == 'r' && buff[1] == 'r'))
		return (-1);
	if (buff[2] == 'a' && buff[3] == '\n')
		revrotate_a(tab);
	else if (buff[2] == 'b' && buff[3] == '\n')
		revrotate_b(tab);
	else if (buff[2] == 'r' && buff[3] == '\n')
		rrevrotate(tab);
	else
		return (-1);
	return (0);
}


static int		exec_read_three(char *buff, t_tab *tab)
{
	if (buff[0] == 'r' && buff[1] == 'a' && buff[2] == '\n')
		rotate_a(tab);
	else if (buff[0] == 'r' && buff[1] == 'b' && buff[2] == '\n')
		rotate_b(tab);
	else if (buff[0] == 'r' && buff[1] == 'r' && buff[2] == '\n')
		rrotate(tab);
	else if (buff[0] == 'p' && buff[1] == 'a' && buff[2] == '\n')
		push_a(tab);
	else if (buff[0] == 'p' && buff[1] == 'b' && buff[2] == '\n')
		push_b(tab);
	else if (buff[0] == 's' && buff[1] == 'a' && buff[2] == '\n')
		swap_a(tab);
	else if (buff[0] == 's' && buff[1] == 'b' && buff[2] == '\n')
		swap_b(tab);
	else if (buff[0] == 's' && buff[1] == 's' && buff[2] == '\n')
		sswap(tab);
	else
		return (-1);
	return (0);
}

int		reader(t_tab *tab)
{
	char		buff[4];
	ssize_t		ret;

	while (1)
	{
		ret = read(0, buff, 3);
		if (ret == 0)
			return (0);
		if (ret != 3)
			return (-1);
		if (buff[2] == '\n')
			if ((exec_read_three(buff, tab)))
				return (-1);
		if (buff[2] != '\n')
		{
			ret = read(0, buff + 3, 1);
			if (ret != 1 && buff[3] != '\n')
				return (-1);
			if((exec_read_four(buff, tab)))
				return (-1);
		}
	}
}

int		main(int ac, char **av)
{
	t_tab	tab;
	t_tab	*ptr;

	if (!(tab.a = init_list_a(ac, av)))
		return (0); /* ajouter l'erreur */
	tab.b = init_empty_list();
	ptr = &tab;
	if (reader(ptr))
		return (-1);
	if (ptr->b->size == 0 && is_ordered(ptr->a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}
