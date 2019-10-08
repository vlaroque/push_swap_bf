/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_checker.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 01:20:29 by vlaroque          #+#    #+#             */
/*   Updated: 2019/10/08 03:46:22 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_CHECKER_H
# define VISUAL_CHECKER_H

# include "SDL.h"

typedef struct s_data	t_data;
struct					s_data
{
	SDL_Window		*win;
	SDL_Renderer	*render;
	int				index_max;
	int				y_max;
	int				x_max;
	int				max_elem;
	int				elem_h;
	int				elem_width_max;
	int				elem_half_max;
	int				ops_max;
	int				delay;
};

int						show_a_snap(t_tab *tab, t_data *data);
int						eventer(t_tab *tab, t_data *data);
int						show_op(t_tab *tab, int i);

#endif
