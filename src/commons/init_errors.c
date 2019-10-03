/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <louregni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 00:52:53 by vlaroque          #+#    #+#             */
/*   Updated: 2019/09/22 22:58:22 by vlaroque         ###   ########.fr       */
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
