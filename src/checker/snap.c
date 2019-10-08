/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 10:50:21 by vlaroque          #+#    #+#             */
/*   Updated: 2019/10/08 01:29:45 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>
#include "push_swap.h"
#include "visual_checker.h"

SDL_Color	rect_col(int index, int index_max)
{
	int				col;
	SDL_Color		color;

	ft_bzero(&color, sizeof(SDL_Color));
	col = index * 1529 / (index_max + 1);
	if (col <= 256 || col >= 1275)
		color.r = 255;
	else if (col > 255 && col < 510)
		color.r = -(col - 510);
	else if (col > 1020 && col < 1275)
		color.r = col - 1020;
	if (col >= 255 && col <= 765)
		color.g = 255;
	else if (col > 0 && col < 255)
		color.g = col - 255;
	else if (col > 765 && col < 1020)
		color.g = -(col - 765);
	if (col >= 765 && col <= 1275)
		color.b = 255;
	else if (col > 510 && col < 765)
		color.b = col - 510;
	else if (col > 1275 && col < 1530)
		color.b = -(col - 1530);
	return (color);
}

int			draw_rect(t_data *data, SDL_Rect rect, SDL_Color col)
{
	if (SDL_SetRenderDrawColor(data->render, col.r, col.g, col.b, col.a))
		return (-1);
	SDL_RenderFillRect(data->render, &rect);
	return (0);
}

int			print_pile(t_list *a, t_data *data, int xm)
{
	int			i;
	int			y;
	t_elem		*head;
	SDL_Rect	rect;

	rect.h = data->elem_h;
	i = 0;
	y = (data->y_max - (a->size * data->elem_h)) / 2;
	head = a->start;
	while (i < a->size)
	{
		rect.y = y;
		rect.w = 1 + (((data->elem_half_max * 2) * (head->index + 1))
				/ (data->index_max + 1));
		rect.x = xm - (rect.w / 2);
		draw_rect(data, rect, rect_col(head->index, data->index_max));
		head = head->next;
		y += data->elem_h;
		i++;
	}
	return (1);
}

int			black_window(SDL_Renderer *render)
{
	if (SDL_SetRenderDrawColor(render, 0, 0, 0, 255))
		return (-1);
	if (SDL_RenderClear(render))
		return (-1);
	return (0);
}

int			show_a_snap(t_tab *tab, t_data *data)
{
	black_window(data->render);
	if (tab->a->size > 0)
		print_pile(tab->a, data, data->x_max / 4);
	if (tab->b->size > 0)
		print_pile(tab->b, data, (data->x_max * 3) / 4);
	SDL_RenderPresent(data->render);
	return (1);
}
