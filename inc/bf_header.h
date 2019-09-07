#ifndef HEADER_H
# define HEADER_H

#include <stdio.h>
#include <strings.h>
#include "push_swap.h"
# define CMBLENMAX 6
# define SEEDLEN 20
# define TABLEN 5

typedef struct  s_tabs
{
	int a[TABLEN];
	int a_max;
	int b[TABLEN];
	int b_max;
	int a_lock;
	int a_head;
}               t_tabs;


int		bf_push_a(t_tabs *tab);
int		bf_push_b(t_tabs *tab);
int		bf_rotate_a(t_tabs *tab);
int		bf_rotate_b(t_tabs *tab);
int		bf_rotate_ab(t_tabs *tab);
int		bf_revrotate_a(t_tabs *tab);
int		bf_revrotate_b(t_tabs *tab);
int		bf_revrotate_ab(t_tabs *tab);
int		bf_swap_a(t_tabs *tab);
int		bf_swap_b(t_tabs *tab);
int		bf_swap_ab(t_tabs *tab);

int		init_bf(int *cmb, int len);
int		bruteforce(t_tabs *tab);
int		rec_bruteforce(t_tabs *tab, int *seed);

int		init_a_unlocked_bf(int *cmb, int len, t_tab *tab);
int		init_a_locked_bf(int *cmb, int len, t_tab *tab);
int		init_b_locked_bf(int *cmb, int len, t_tab *tab);

int		bf_printtab(t_tabs *tab);
int		bf_printseed(int *seed);
int		bf_is_sorted(t_tabs *tab);

# define PB 1
# define PA 2
# define RA 4
# define RB 8
# define RR 16
# define RRA 32
# define RRB 64
# define RRR 128
# define SA 256
# define SB 512
# define SS 1024
# define END 2048

#endif
