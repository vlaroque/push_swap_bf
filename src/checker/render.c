/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 11:14:45 by vlaroque          #+#    #+#             */
/*   Updated: 2019/10/02 14:14:49 by vlaroque         ###   ########.fr       */
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


int		apply_op(t_tab *tab, int op)
{
	if (op == RA)
		return (rotate(tab->a));
	else if (op == RB)
		return (rotate(tab->b));
	else if (op == RR)
		return (rotate(tab->a) * rotate(tab->b));
	else if (op == RRA)
		return (rev_rotate(tab->a));
	else if (op == RRB)
		return (rev_rotate(tab->b));
	else if (op == RRR)
		return (rev_rotate(tab->a) * rev_rotate(tab->b));
	else if (op == SA)
		return (swap(tab->a));
	else if (op == SB)
		return (swap(tab->b));
	else if (op == SS)
		return (swap(tab->a) * swap(tab->b));
	else if (op == PA)
		return (push(tab->b, tab->a));
	else if (op == PB)
		return (push(tab->a, tab->b));
	return (-1);
}

int		reverse(int op)
{
	if (op == RA)
		return (RRA);
	else if (op == RRA)
		return (RA);
	else if (op == RB)
		return (RRB);
	else if (op == RRB)
		return (RB);
	else if (op == RR)
		return (RRR);
	else if (op == RRR)
		return (RR);
	else if (op == PA)
		return (PB);
	else if (op == PB)
		return (PA);
	return (op);
}

int		play(t_tab *tab, t_data *data, int *i)
{
	SDL_Event		event;
	SDL_Color		black = {0, 0, 0, 255};

	while (*i < data->ops_max)
	{
		printf("in play %d\n", *i);
		apply_op(tab, show_op(tab, *i));
		show_a_snap(tab, data);
		SDL_Delay(10);
		(*i)++;
		if (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				return (-1);
			if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_SPACE)
				return (0);
		}
	}
	return (0);
}

int		eventer(t_tab *tab, t_data *data)
{
	SDL_Event		event;
	int				i;
	int				quit;

	i = 0;
	quit = 0;
	while (!quit)
	{
		printf("BOUCLE\n");
		show_a_snap(tab, data);
		while (!SDL_PollEvent(&event))
			;
		if (event.type == SDL_QUIT)
			quit = 1;
		if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_SPACE)
			if (play(tab, data, &i))
				return (0);
		if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_LEFT && i > 0)
			apply_op(tab, reverse(show_op(tab, --i)));
		if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RIGHT && i < data->ops_max)
			apply_op(tab, show_op(tab, i++));
		printf("   BOUCLE out\n");
	}
	return (0);
}

int		render(t_tab *tab)
{
	t_data			data;
	SDL_Color		orange = {255, 127, 40, 255};

	if(SDL_Init(SDL_INIT_EVERYTHING))
		return (end(1));
	if (!(data.win = SDL_CreateWindow("non", SDL_WINDOWPOS_CENTERED,
					SDL_WINDOWPOS_CENTERED, 2500, 1400, SDL_WINDOW_SHOWN)))
		return (end(1));
	if(!(data.render = SDL_CreateRenderer(data.win, -1, 0)))
		return(end(1));
	init_vars(tab, &data);
	SDL_RaiseWindow(data.win);
	eventer(tab, &data);
	//SDL_DestroyRenderer(data.render);
	//SDL_DestroyWindow(data.win);
	SDL_Quit();
	return (0);
}
