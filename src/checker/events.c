/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 16:43:22 by vlaroque          #+#    #+#             */
/*   Updated: 2019/10/08 01:30:31 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>
#include "push_swap.h"
#include "visual_checker.h"

int				apply_op(t_tab *tab, int op)
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

int				reverse(int op)
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

static int		play(t_tab *tab, t_data *data, int *i)
{
	SDL_Event		event;

	while (*i < data->ops_max)
	{
		apply_op(tab, show_op(tab, *i));
		show_a_snap(tab, data);
		SDL_Delay(data->delay);
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

static int		go_to(t_tab *tab, t_data *data, int *i, int dir)
{
	if (dir > 0)
		while (*i < data->ops_max)
			apply_op(tab, show_op(tab, (*i)++));
	else
		while (*i > 0)
			apply_op(tab, reverse(show_op(tab, --(*i))));
	return (0);
}

int				eventer(t_tab *tab, t_data *data)
{
	SDL_Event		ev;
	int				i;

	i = 0;
	while (42)
	{
		show_a_snap(tab, data);
		while (!SDL_PollEvent(&ev))
			;
		if (ev.type == SDL_QUIT || (ev.type == SDL_KEYUP
					&& ev.key.keysym.sym == SDLK_ESCAPE))
			return (0);
		if (ev.type == SDL_KEYUP && ev.key.keysym.sym == SDLK_SPACE)
			if (play(tab, data, &i))
				return (0);
		if (ev.type == SDL_KEYDOWN && ev.key.keysym.sym == SDLK_LEFT && i > 0)
			apply_op(tab, reverse(show_op(tab, --i)));
		if (ev.type == SDL_KEYDOWN && ev.key.keysym.sym == SDLK_RIGHT
				&& i < data->ops_max)
			apply_op(tab, show_op(tab, i++));
		if (ev.type == SDL_KEYDOWN && ev.key.keysym.sym == SDLK_UP)
			go_to(tab, data, &i, -1);
		if (ev.type == SDL_KEYDOWN && ev.key.keysym.sym == SDLK_DOWN)
			go_to(tab, data, &i, 1);
	}
}
