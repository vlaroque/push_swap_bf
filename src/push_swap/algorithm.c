int		choose_pivot(t_list *list)
{
	t_elem	*head;
	t_elem	*save;
	int		min;
	int		max;

	head = list->start;
	save = list->start;
	min = head->nbr;
	max = head->nbr;
	while (head->data != PIVOT)
	{
		if (head->nbr < min)
			min = head->nbr;
		if (head->nbr > max)
			max = head->nbr;
		head = head->next;
		if (head == save)
			break ;
	}
	return ((min + max) / 2)
}

int		algo(t_tab *tab)
{
	
}
