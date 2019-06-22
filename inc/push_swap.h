#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>

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

/* list commons */
t_list		*init_empty_list(void);
void		print_tabs(t_tab *tab);

/* list operations */
int		rotate(t_list *list);
int		rev_rotate(t_list *list);
int		swap(t_list *list);
int		push(t_list *from, t_list *to);



#endif
