/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:22:21 by vlaroque          #+#    #+#             */
/*   Updated: 2019/10/07 19:33:32 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BF_HEADER_H
# define BF_HEADER_H

# include <strings.h>
# include "push_swap.h"
# include "binop.h"
# define CMBLENMAX 6
# define SEEDLEN 20
# define TABLEN 5

typedef struct	s_tabs
{
	int			a[TABLEN];
	int			a_max;
	int			b[TABLEN];
	int			b_max;
	int			a_lock;
	int			a_head;
}				t_tabs;

int				bf_push_a(t_tabs *tab);
int				bf_push_b(t_tabs *tab);
int				bf_rotate_a(t_tabs *tab);
int				bf_rotate_b(t_tabs *tab);
int				bf_rotate_ab(t_tabs *tab);
int				bf_revrotate_a(t_tabs *tab);
int				bf_revrotate_b(t_tabs *tab);
int				bf_revrotate_ab(t_tabs *tab);
int				bf_swap_a(t_tabs *tab);
int				bf_swap_b(t_tabs *tab);
int				bf_swap_ab(t_tabs *tab);
int				init_bf(int *cmb, int len);
int				bruteforce(t_tabs *tab);
int				rec_bruteforce(t_tabs *tab, int *seed);
int				init_a_unlocked_bf(int *cmb, int len, t_tab *tab);
int				init_a_locked_bf(int *cmb, int len, t_tab *tab);
int				init_b_locked_bf(int *cmb, int len, t_tab *tab);
int				bf_printtab(t_tabs *tab);
int				bf_printseed(int *seed);
int				bf_is_sorted(t_tabs *tab);

#endif
