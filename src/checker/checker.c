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

int		exec_read(char *buff, int ret)
{

	return (0);
}

int		reader(void)
{
	char		buff[4];
	ssize_t		ret;

	while (1)
	{
		ret = read(1, buff, 3);
		if (ret != 3)
			return (-1);
		if (buff[2] != '\n')
		{
			ret = read(1, buff + 3, 1);
			if (ret != 1 && buff[3] != '\n')
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
	return (0);
}
