/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 11:14:45 by vlaroque          #+#    #+#             */
/*   Updated: 2019/10/08 01:25:13 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>
#include "push_swap.h"
#include "visual_checker.h"

int		end(int a)
{
	if (a < 2)
		SDL_Quit();
	return (-1);
}

int		op_max(t_tab *tab)
{
	t_op	*head;
	int		i;

	i = 0;
	head = tab->ops;
	while (head != NULL)
	{
		head = head->next;
		i++;
	}
	return (i);
}

int		init_vars(t_tab *tab, t_data *data)
{
	data->max_elem = tab->a->size;
	data->y_max = 1400;
	data->x_max = 2500;
	data->elem_h = (data->y_max - 100) / data->max_elem;
	data->elem_width_max = data->x_max / 3;
	data->elem_half_max = data->elem_width_max / 2;
	data->index_max = data->max_elem - 1;
	data->ops_max = op_max(tab);
	if (data->ops_max > 0)
		data->delay = 30000 / data->ops_max;
	else
		data->delay = 1;
	if (data->delay > 500)
		data->delay = 500;
	return (0);
}

int		show_op(t_tab *tab, int i)
{
	t_op	*head;

	head = tab->ops;
	while (i)
	{
		head = head->next;
		if (head == 0)
			return (0);
		i--;
	}
	return (head->op);
}

int		rerender(t_tab *tab)
{
	t_data			data;

	if (SDL_Init(SDL_INIT_EVERYTHING))
		return (end(1));
	if (!(data.win = SDL_CreateWindow("non", SDL_WINDOWPOS_CENTERED,
					SDL_WINDOWPOS_CENTERED, 2500, 1400, SDL_WINDOW_SHOWN)))
		return (end(1));
	if (!(data.render = SDL_CreateRenderer(data.win, -1, 0)))
		return (end(1));
	init_vars(tab, &data);
	SDL_RaiseWindow(data.win);
	eventer(tab, &data);
	SDL_DestroyRenderer(data.render);
	SDL_DestroyWindow(data.win);
	SDL_Quit();
	return (0);
}
