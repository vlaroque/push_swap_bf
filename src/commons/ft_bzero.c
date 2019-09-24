/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 14:52:58 by vlaroque          #+#    #+#             */
/*   Updated: 2019/09/24 19:51:02 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "stdio.h"

void	ft_bzero(void *s, size_t n)
{
	while (n > 8)
	{
		*((long long int *)s) = 0x00;
		n = n - 8;
		s = (long long int *)s + 1;
	}
	while (n > 0)
	{
		*((char *)s) = 0x00;
		s = (char *)s + 1;
		n--;
	}
}
