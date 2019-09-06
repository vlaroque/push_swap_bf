#include "header.h"

/* push a est tout le temps autorise*/
int		push_a(t_tabs *tab)
{
	int i;

	i = 0;
	if (tab->b_max <= 1)
		return (0);
	while (i < TABLEN)
	{
		tab->a[i] <<= 1;
		if(tab->b[i] == 1)
			tab->a[i] = 1;
		tab->b[i] >>= 1;
		i++;
	}
	tab->a_max <<= 1;
	tab->b_max >>= 1;
	return(1);
}

/* pushb non autorise si ahead est amax*/
int		push_b(t_tabs *tab)
{
	int i;

	i = 0;
	if (tab->a_lock && (tab->a_head & tab->a_max))
		return (0);
	if (tab->a_max <= 1)
		return (0);
	while (i < TABLEN)
	{
		tab->b[i] <<= 1;
		if(tab->a[i] == 1)
			tab->b[i] = 1;
		tab->a[i] >>= 1;
		i++;
	}
	tab->a_max >>= 1;
	tab->b_max <<= 1;
	return(1);
}

/* ra non autorise si ahead est amax*/
int		rotate_a(t_tabs *tab)
{
	int i;

	i = 0;
	if (tab->a_lock && (tab->a_head == tab->a_max))
		return (0);
	if (tab->a_max <= 2)
		return (0);
	while (i < TABLEN)
	{
		if (tab->a[i] == 1)
			tab->a[i] = tab->a_max >> 1;
		else if (tab->a[i])
			tab->a[i] >>= 1;
		i++;
	}
	tab->a_head <<= 1;
	return (1);
}

int		rotate_b(t_tabs *tab)
{
	int i;

	i = 0;
	if (tab->b_max <= 2)
		return (0);
	while (i < TABLEN)
	{
		if (tab->b[i] == 1)
			tab->b[i] = tab->b_max >> 1;
		else if (tab->a[i])
			tab->b[i] >>= 1;
		i++;
	}
	return (1);
}

int		rotate_ab(t_tabs *tab)
{
	return(rotate_a(tab) * rotate_b(tab));
}

/* rra non autorise si ahead est 1*/
int		revrotate_a(t_tabs *tab)
{
	int i;

	i = 0;
	if (tab->a_lock && (tab->a_head == 1))
		return (0);
	if (tab->a_max <= 2)
		return (0);
	while(i < TABLEN)
	{
		tab->a[i] = tab->a[i] << 1;
		if (tab->a[i] == tab->a_max)
			tab->a[i] = 1;
		i++;
	}
	tab->a_head >>= 1;
	return (1);
}

int		revrotate_b(t_tabs *tab)
{
	int i;

	i = 0;
	if (tab->b_max <= 2)
		return (0);
	while(i < TABLEN)
	{
		tab->b[i] = tab->b_max << 1;
		if (tab->b[i] == tab->b_max)
			tab->b[i] = 1;
		i++;
	}
	return (1);
}

int		revrotate_ab(t_tabs *tab)
{
	return(revrotate_a(tab) * revrotate_b(tab));
}

/* rra non autorise si ahead est 1*/
int		swap_a(t_tabs *tab)
{
	int i;

	i = 0;
	if (tab->a_lock && (tab->a_head >= (tab->a_max >> 1)))
		return (0);
	if (tab->a_max < 3)
		return (0);
	while (i < TABLEN)
	{
		if (tab->a[i] == 1)
			tab->a[i] = 2;
		else if (tab->a[i] == 2)
			tab->a[i] = 1;
		i++;
	}
	return(1);
}

int		swap_b(t_tabs *tab)
{
	int i;

	i = 0;
	if (tab->b_max < 3)
		return (0);
	while (i < TABLEN)
	{
		if (tab->b[i] == 1)
			tab->b[i] = 2;
		else if (tab->b[i] == 2)
			tab->b[i] = 1;
		i++;
	}
	return(1);
}

int		swap_ab(t_tabs *tab)
{
	return (swap_a(tab) * swap_b(tab));
}
