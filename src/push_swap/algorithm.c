#include "push_swap.h"

/*
 * WARNING all pivot variables are in reality for the index !
 */

/*
 * commence sur une case non pivot, jusqu'au prochain
 */

int		a_rev_rotation(t_tab *tab)
{
	t_elem *elem;

	//printf("      >>> A REV_ROTATION <<<\n");
	while(tab->a->start->prev->data != PIVOT)
		revrotate_a(tab);
	return (0);
}

int		a_to_b(t_tab *tab)
{
	static int	first = 0;
	int			pivot;
	int			dist;

	//printf("     >>> A TO B <<<\n");
	pivot = choose_pivot(tab->a);
	dist = dist_pivot(tab->a, pivot, '-');
	while (dist >= 0)
	{
		if (tab->a->start->index <= pivot)
		{
			//printf("     PUSH a >>> b | index = %d\n", tab->a->start->index);
			push_b(tab);
			if(tab->b->start->index == pivot)
				rotate_b(tab);
		}
		else
			rotate_a(tab);
		dist--;
	}
	if (first)
		a_rev_rotation(tab);
	first = 1;
	return (1);
}

int		b_to_a(t_tab *tab)
{
	int		pivot;
	int		dist;
	
	//printf("     >>> B TO A <<<\n");
	pivot = choose_pivot(tab->b);
	dist = best_dist(dist_pivot(tab->b, pivot, '+'), 999999);
	while (dist >= 0)
	{
		if(tab->b->start->index >= pivot)
		{
			//printf("     PUSH b >>> a | index = %d\n", tab->b->start->index);
			push_a(tab);
			if(tab->a->start->index == pivot)
				rotate_a(tab);
		}
		else if (dist > 0)
			rotate_b(tab);
		else if (dist < 0)
			revrotate_b(tab);
		//if (dist > 0)
			dist--;
		//else
		//	dist++;
	}
	return (1);
}

int		a_rotation(t_tab *tab)
{
	t_elem *elem;

	//printf("A_ROTATION ");
	while(tab->a->start->data == PIVOT)
	{
		//printf(" ONE");
		rotate_a(tab);
		if(tab->a->start->index == 0 && is_ordered(tab->a))
		{
			//printf("index == 0!\n");
			return (1);
		}
	}
	//printf("\n");
	return (0);
}

int		algo(t_tab *tab)
{
	//printf("in algo \n");
	while (1)
	{
		a_to_b(tab);
		print_tabs(tab);
		//printf("in alogo while 01\n");
		while (tab->b->size > 0)
		{
			//	printf("in alogo while by while %d\n", tab->b->size);
			b_to_a(tab);
			revrotate_a(tab);
			is_pivot(tab->a->start);
			print_tabs(tab);
		}
		printf("in alogo while 02\n");
		if (is_ordered(tab->a))
			return (1);
		//printf("isnotordered\n");
		if (a_rotation(tab))
			return (1);
		//printf("in alogo while\n");
	}
	print_tabs(tab);

}
