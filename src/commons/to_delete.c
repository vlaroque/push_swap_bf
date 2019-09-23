void		print_tabs(t_tab *tab)
{
	int		i;
	t_elem	*elem;

	i = -1;
	elem = tab->a->start;
	printf("A = ");
	while (++i < tab->a->size)
	{
		if (elem->prev->next->nbr != elem->nbr
				|| elem->next->prev->nbr != elem->nbr)
			printf("!pb!\n");
		if (elem->data == PIVOT)
			printf("!");
		printf(" (%d) %-5d ", elem->index, elem->nbr);
		elem = elem->next;
	}
	printf("\n");
	i = -1;
	elem = tab->b->start;
	printf("B = ");
	while (++i < tab->b->size)
	{
		if (elem->data == PIVOT)
			printf("!");
		printf(" (%d) %-5d ", elem->index, elem->nbr);
		elem = elem->next;
	}
	printf("\n");
}

void		printlist(t_list *list)
{
	t_elem	*elem;
	int		i = 0;

	elem = list->start;
	while (i < list->size)
	{
		printf("%10d <<< %10d >>> %10d ind = %d\n", elem->prev->nbr, elem->nbr,
				elem->next->nbr, elem->index);
		elem = elem->next;
		i++;
	}
}
