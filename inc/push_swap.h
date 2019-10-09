/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:23:19 by vlaroque          #+#    #+#             */
/*   Updated: 2019/10/09 17:47:32 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "binop.h"
# include <stdlib.h>
# define PIVOT 1

typedef struct s_elem	t_elem;
typedef struct s_op		t_op;

struct					s_elem
{
	int				nbr;
	int				index;
	int				data;
	t_elem			*next;
	t_elem			*prev;
};

typedef struct			s_list
{
	t_elem			*start;
	int				size;
}						t_list;

typedef struct			s_tab
{
	t_list			*a;
	t_list			*b;
	t_op			*ops;
}						t_tab;

void					ft_bzero(void *s, size_t n);

/*
** init
*/
t_list					*init_list_a(int ac, char **av);
void					printlist(t_list *list);
void					quick_sort(t_elem **tab, int first, int last);
int						error(int i);
int						rtrash(int i);

/*
** list commons
*/
t_list					*init_empty_list(void);
void					print_tabs(t_tab *tab);
int						post_op(t_list *list);
int						is_ordered(t_list *list);
void					free_list(t_list *list);
void					free_both_lists(t_tab *tab);
int						error(int i);

/*
** list operations
*/
int						rotate(t_list *list);
int						rev_rotate(t_list *list);
int						swap(t_list *list);
int						push(t_list *from, t_list *to);

/*
** operations
*/
int						rotate_a(t_tab *tab);
int						rotate_b(t_tab *tab);
int						revrotate_a(t_tab *tab);
int						revrotate_b(t_tab *tab);
int						rrotate(t_tab *tab);
int						rrevrotate(t_tab *tab);
int						push_a(t_tab *tab);
int						push_b(t_tab *tab);
int						swap_a(t_tab *tab);
int						swap_b(t_tab *tab);
int						sswap(t_tab *tab);

/*
** algo
*/
int						algo(t_tab *tab);
int						pivot_maker(t_tab *tab);
int						dist_to_next_pivot(t_list *list, int *min);

/*
** algo_pivot
*/
void					is_pivot(t_elem *elem);
int						choose_pivot(t_list *list);

/*
** algo_distances
*/
int						dist_pivot(t_list *list, int pivot, char p_m);
int						rev_dist_pivot(t_list *list, int pivot, char p_m);
int						best_dist(int pos, int neg);

/*
** algo_insort
*/
int						b_to_a_insort(t_tab *tab);

/*
** algo_swaper
*/
int						a_swaper(t_tab *tab);

/*
**algo_rotations
*/
int						a_rev_rotation(t_tab *tab);
int						a_rotation(t_tab *tab);
int						bruteforce_for_five(t_tab *tab);
int						a_to_b_bf(t_tab *tab);

/*
** chain
*/
struct					s_op
{
	int				op;
	t_op			*next;
};

void					op_add_new(t_op **begin, int op);
void					op_list_read(t_op **begin);
void					free_op_list(t_op **begin);

/*
** ft_instant
*/
int						instant_bf(int comb, t_tab *tab);

/*
** Brutefoce
*/
int						init_a_unlocked_bf(int *cmb, int len, t_tab *piles);

/*
** render
*/
int						rerender(t_tab *tab);
int						visual_reader(t_tab *tab);

#endif
