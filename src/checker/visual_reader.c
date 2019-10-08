/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_reader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 17:23:57 by vlaroque          #+#    #+#             */
/*   Updated: 2019/10/08 01:27:57 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "push_swap.h"
#include "visual_checker.h"

static int		exec_read_four_v(char *buff, t_tab *tab)
{
	if (!(buff[0] == 'r' && buff[1] == 'r'))
		return (-1);
	if (buff[2] == 'a' && buff[3] == '\n')
		op_add_new(&(tab->ops), RRA);
	else if (buff[2] == 'b' && buff[3] == '\n')
		op_add_new(&(tab->ops), RRB);
	else if (buff[2] == 'r' && buff[3] == '\n')
		op_add_new(&(tab->ops), RRR);
	else
		return (-1);
	return (0);
}

static int		exec_read_three_v(char *buff, t_tab *tab)
{
	if (buff[0] == 'r' && buff[1] == 'a' && buff[2] == '\n')
		op_add_new(&(tab->ops), RA);
	else if (buff[0] == 'r' && buff[1] == 'b' && buff[2] == '\n')
		op_add_new(&(tab->ops), RB);
	else if (buff[0] == 'r' && buff[1] == 'r' && buff[2] == '\n')
		op_add_new(&(tab->ops), RR);
	else if (buff[0] == 'p' && buff[1] == 'a' && buff[2] == '\n')
		op_add_new(&(tab->ops), PA);
	else if (buff[0] == 'p' && buff[1] == 'b' && buff[2] == '\n')
		op_add_new(&(tab->ops), PB);
	else if (buff[0] == 's' && buff[1] == 'a' && buff[2] == '\n')
		op_add_new(&(tab->ops), SA);
	else if (buff[0] == 's' && buff[1] == 'b' && buff[2] == '\n')
		op_add_new(&(tab->ops), SB);
	else if (buff[0] == 's' && buff[1] == 's' && buff[2] == '\n')
		op_add_new(&(tab->ops), SS);
	else
		return (-1);
	return (0);
}

int				visual_reader(t_tab *tab)
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
			if ((exec_read_three_v(buff, tab)))
				return (-1);
		if (buff[2] != '\n')
		{
			ret = read(0, buff + 3, 1);
			if (ret != 1 && buff[3] != '\n')
				return (-1);
			if ((exec_read_four_v(buff, tab)))
				return (-1);
		}
	}
	return (0);
}
