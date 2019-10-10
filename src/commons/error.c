/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:56:00 by vlaroque          #+#    #+#             */
/*   Updated: 2019/10/10 00:03:13 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

int		error(int i)
{
	write(2, "Error\n", 6);
	return (i);
}

int		rtrash(int i)
{
	char trash;

	while (read(0, &trash, 1) != 0 && trash != '\n')
		;
	return (i);
}
