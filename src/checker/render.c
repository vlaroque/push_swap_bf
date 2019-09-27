/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 11:14:45 by vlaroque          #+#    #+#             */
/*   Updated: 2019/09/27 11:56:49 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>
#include "push_swap.h"

int end(int a)
{
	if (a < 2)
		SDL_Quit();
	return(-1);
}

int colorize_win(SDL_Renderer *render, SDL_Color color)
{
	if (SDL_SetRenderDrawColor(render, color.r, color.g, color.b, color.a))
		return (-1);
	if (SDL_RenderClear(render))
		return (-1);
	SDL_RenderPresent(render);
	return 0;
}

/********************************************/

SDL_Color	rect_col(int index, int index_max)
{
	int				col;
	SDL_Color		color;

	ft_bzero(&color, sizeof(SDL_Color));
	col = index * 1529 / index_max;
	SDL_Color	orange = {255, 127, 40, 255};
	if (col <= 256 || col >= 1275)
		color.r = 255;
	else if(col > 255 && col < 510)
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
	return(color);
}

int		draw_rect(t_data *data, SDL_Rect rect, SDL_Color col)
{
	if(SDL_SetRenderDrawColor(data->render, col.r, col.g, col.b, col.a))
		return (-1);
	SDL_RenderFillRect(data->render, &rect);
}

int		print_pile(t_list *a, t_data *data, int xm)
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
		rect.w = 1 + (((data->elem_half_max * 2) * (head->index + 1)) / (data->index_max + 1));
		rect.x = xm - (rect.w / 2);
		draw_rect(data, rect, rect_col(head->index, data->index_max));
		head = head->next;
		y += data->elem_h;
		i++;
	}
	return (1);
}

int		show_a_snap(t_tab *tab, t_data *data)
{
	print_pile(tab->a, data, data->x_max / 4);
	print_pile(tab->b, data, (data->x_max * 3) / 4);
	SDL_RenderPresent(data->render);
			return (1);
}

/********************************************/

int		init_vars(t_tab *tab, t_data *data)
{
	data->max_elem = tab->a->size;
	data->y_max = 1400;
	data->x_max = 2500;
	data->elem_h = (data->y_max - 100) / data->max_elem;
	data->elem_width_max = data->x_max / 3;
	data->elem_half_max = data->elem_width_max / 2;
	data->index_max = data->max_elem - 1;
	return (0);
}

int		render(t_tab *tab)
{
	t_data			data;
	SDL_Color		orange = {255, 127, 40, 255};
	SDL_Color		black = {0, 0, 0, 255};
	SDL_Event		event;

	if(SDL_Init(SDL_INIT_EVERYTHING))
		return (end(1));
	if (!(data.win = SDL_CreateWindow("non", SDL_WINDOWPOS_CENTERED,
					SDL_WINDOWPOS_CENTERED, 2500, 1400, SDL_WINDOW_SHOWN)))
		return (end(1));
	if(!(data.render = SDL_CreateRenderer(data.win, -1, 0)))
		return(end(1));
	colorize_win(data.render, black);
	init_vars(tab, &data);
	SDL_RaiseWindow(data.win);
	push_b(tab);
	show_a_snap(tab, &data);
	SDL_PollEvent(&event);
	SDL_Delay(5000);

	SDL_DestroyRenderer(data.render);
	SDL_DestroyWindow(data.win);
	SDL_Quit();
	return (0);
}
