#include "push_swap.h"

static void swap_p(t_elem **a, t_elem **b)
{
	t_elem *tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int partition(t_elem **tab, int first, int last, int pivot)
{
	int i;
	int j;

	j = first;
	i = first;
	swap_p(&tab[pivot], &tab[last]);
	while (i < last)
	{
		if (tab[i]->nbr <= tab[last]->nbr)
		{
			swap_p(&tab[i], &tab[j]);
			j++;
		}
		i++;
	}
	swap_p(&tab[last], &tab[j]);
	return (j);
}

void	quick_sort(t_elem **tab, int first, int last)
{
	int pivot;

	if (first >= last)
		return ;
	pivot = (first + last) / 2;
	pivot = partition(tab, first, last, pivot);
	quick_sort(tab, first, pivot - 1);
	quick_sort(tab, pivot + 1, last);
}

