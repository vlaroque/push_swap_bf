/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 11:14:45 by vlaroque          #+#    #+#             */
/*   Updated: 2019/09/25 21:53:30 by vlaroque         ###   ########.fr       */
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

int		print_pile(t_tab *tab, t_data *data, int s)
{
	int		i;
	int		xm;
	int		y;
	t_elem	*head;
	SDL_Color	orange = {255, 127, 40, 255};
	SDL_Rect	rect;
	int res;

	write(1, "lol1\n",5);
	rect.h = data->elem_h;
	i = 0;
	xm = data->y_max / 4;
	y = (data->y_max - (tab->a->size * data->elem_h)) / 2;
	head = tab->a->start;
	write(1, "lol2\n", 5);
	res = SDL_SetRenderDrawColor(data->render, orange.r, orange.g, orange.b, orange.a);
	fprintf(stderr, "Erreur SDL_SetRenderDrawColor : %s", SDL_GetError());
	printf("res = %d\n", res);
	/*{
	write(1, "lol9\n", 5);
		return (-1);
	}*/
	write(1, "lol3\n", 5);
	while (i < tab->a->size)
	{
		rect.y = y;
		rect.w = 1 + (((data->elem_half_max * 2) * head->index) / data->index_max);
		rect.x = xm - (rect.w / 2);
		printf("rest = x %d, y %d, h %d, w %d\n", rect.x, rect.y, rect.h, rect.w);
		SDL_RenderDrawRect(data->render, &rect);
		head = head->next;
		y += data->elem_h;
		i++;
	}
	write(1, "lol4\n", 5);
	SDL_RenderPresent(data->render);
	return (1);
}
/*
int		show_a_snap(t_tab *tab, t_data *data)
{
	
}
*/
int		init_vars(t_tab *tab, t_data *data)
{
	data->max_elem = tab->a->size;
	data->y_max = 2500;
	data->x_max = 1400;
	data->elem_h = (data->y_max - 100) / data->max_elem;
	data->elem_width_max = data->x_max / 3;
	data->elem_half_max = data->elem_width_max / 2;
	data->index_max = data->max_elem - 1;
	printf("\nmax_elem = %d, ymax %d, xmax %d, heigh %d, widthmax %d, index_max %d\n",data->max_elem, data->y_max, data->x_max, data->elem_h, data->elem_width_max, data->index_max);
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
	printf("lol2\n");
	init_vars(tab, &data);
	print_pile(tab, &data, 1);

	SDL_PollEvent(&event);
	SDL_Delay(3000);

	SDL_DestroyRenderer(data.render);
	SDL_DestroyWindow(data.win);
	SDL_Quit();
	return (0);
}
/*
int		main(int ac, char **av)
{
	render(1);
	return (0);
}*/
