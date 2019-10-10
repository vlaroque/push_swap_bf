/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 22:49:29 by vlaroque          #+#    #+#             */
/*   Updated: 2019/10/10 05:48:58 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "push_swap.h"
#include "visual_checker.h"

static int		exec_read_four(char *buff, t_tab *tab)
{
	if (!(buff[0] == 'r' && buff[1] == 'r'))
		return (-1);
	if (buff[3] != '\n')
		return (rtrash(-1));
	if (buff[2] == 'a')
		revrotate_a(tab);
	else if (buff[2] == 'b')
		revrotate_b(tab);
	else if (buff[2] == 'r')
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

int				reader(t_tab *tab)
{
	char		buff[4];
	ssize_t		ret;

	while (1)
	{
		ret = read(0, buff, 3);
		if (ret == -1)
			continue;
		if (!ret)
			return (0);
		if (ret != 3)
			return (-1);
		if (buff[2] == '\n')
			if (exec_read_three(buff, tab))
				return (-1);
		if (buff[2] != '\n')
		{
			if (!(ret = read(0, buff + 3, 1)))
				return (-1);
			if (buff[3] != '\n')
				return (rtrash(-1));
			if (exec_read_four(buff, tab))
				return (-1);
		}
	}
}

int				visual_checker(int ac, char **av)
{
	t_tab		tab;

	ft_bzero(&tab, sizeof(t_tab));
	if (!(tab.a = init_list_a(ac, av)))
		return (0);
	tab.b = init_empty_list();
	if (visual_reader(&tab))
	{
		free_all(&tab);
		return (error(-1));
	}
	rerender(&tab);
	free_op_list(&(tab).ops);
	free_both_lists(&tab);
	return (0);
}

int				main(int ac, char **av)
{
	t_tab		tab;

	ft_bzero(&tab, sizeof(t_tab));
	if (ac < 2)
		return (0);
	if (av[1][0] == '-' && av[1][1] == 'v')
	{
		if (ac < 3)
			return (0);
		return (visual_checker(ac - 1, av + 1));
	}
	if (!(tab.a = init_list_a(ac, av)))
		return (free_all(&tab));
	tab.b = init_empty_list();
	if (reader(&tab))
		return (error(-1));
	if (tab.b->size == 0 && is_ordered(tab.a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_all(&tab);
	return (0);
}
