#include "header.h"

int		bf_printseed(int *seed)
{
	int i;

	i = 0;
	while(seed[i] && i < SEEDLEN)
	{
		if (seed[i] == PA)
			printf("PA  ");
		else if (seed[i] == PB)
			printf("PB  ");
		else if (seed[i] == SA)
			printf("SA  ");
		else if (seed[i] == SB)
			printf("SB  ");
		else if (seed[i] == SS)
			printf("SS  ");
		else if (seed[i] == RA)
			printf("RA  ");
		else if (seed[i] == RB)
			printf("RB  ");
		else if (seed[i] == RR)
			printf("RR  ");
		else if (seed[i] == RRA)
			printf("RRA ");
		else if (seed[i] == RRB)
			printf("RRB  ");
		else if (seed[i] == RRR)
			printf("RRR ");
		i++;
	}
	printf("\n");
}

int     bf_printtab(t_tabs *tab)
{
	int i;
	int head;

	head = 1;
	printf("TABS = ");
	while (head != tab->a_max)
	{
		i = 0;
		while (i < 5)
		{
			if (tab->a[i] == head)
				printf("%d ", i);
			i++;
		}
		head <<= 1;
	}
	printf("     ");
	head = 1;
	while (head != tab->b_max)
	{
		i = 0;
		while (i < 5)
		{
			if (tab->b[i] == head)
				printf("%d ", i);
			i++;
		}
		head <<= 1;
	}
	printf("\n");
}
