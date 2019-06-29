#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# define PIVOT 1

typedef	struct s_elem t_elem;
struct	s_elem
{
	int		nbr;
	int		index;
	int		data;
	t_elem	*next;
	t_elem	*prev;
};

typedef struct	s_list
{
	t_elem	*start;
	int		size;
}				t_list;

typedef struct	s_tab
{
	t_list *a;
	t_list *b;
}				t_tab;

/* init */
t_list	*init(int ac, char **av);
void	printlist(t_list *list);
void	free_list(t_list *list);
int		post_op(t_list *list);
void	quick_sort(t_elem **tab, int first, int last);
int		is_ordered(t_list *list);

/* list commons */
t_list		*init_empty_list(void);
void		print_tabs(t_tab *tab);

/* list operations */
int		rotate(t_list *list);
int		rev_rotate(t_list *list);
int		swap(t_list *list);
int		push(t_list *from, t_list *to);

/* operations */
int		rotate_a(t_tab *tab);
int		rotate_b(t_tab *tab);
int		revrotate_a(t_tab *tab);
int		revrotate_b(t_tab *tab);
int		rrotate(t_tab *tab);
int		rrevrotate(t_tab *tab);
int		push_a(t_tab *tab);
int		push_b(t_tab *tab);
int		swap_a(t_tab *tab);
int		swap_b(t_tab *tab);
int		sswap(t_tab *tab);

/* algo */
int		algo(t_tab *tab);

/* algo_pivot */
void	is_pivot(t_elem *elem);
int		choose_pivot(t_list *list);

/* algo_distances */
int		dist_neg_pivot(t_list *list, int pivot); /* a refaire */
int		dist_pivot(t_list *list, int pivot, char p_m);
int		best_dist(int pos, int neg);

#endif
