#include "bf_header.h"

int     init_bf(int *cmb, int len)
{
	int		i;
	t_tabs	tab;
	int		seed[SEEDLEN] = {0};

	bzero(&tab, sizeof(t_tabs));
	i = 0;
	while(i < len)
	{
		tab.a[cmb[i] - 1] = 1 << i;
		i++;
	}
	tab.a_max = 1 << len;
	tab.b_max = 1;
	tab.a_lock = 1;
	tab.a_head = 1;
	rec_bruteforce(&tab, seed);
}

int     usefull_cmb(int *cmb, int head)
{
	int check;

	check = cmb[head];
	head--;
	while (head >= 0)
	{
		if (cmb[head] == check)
			return (0);
		head--;
	}
	return (1);
}

int     next_cmb(int *cmb, int head, int len)
{
	int i;
	i = 1;

	if (head == len)
	{
		printf("combi %d %d %d %d %d\n", cmb[0], cmb[1], cmb[2], cmb[3], cmb[4]);
		init_bf(cmb, len);
	}
	else
	{
		while (i < len + 1)
		{
			cmb[head] = i;
			if (usefull_cmb(cmb, head))
				next_cmb(cmb, head + 1, len);
			cmb[head] = 0;
			i++;
		}
	}
	return (0);
}

int     main(void)
{
	int cmb[CMBLENMAX];
	//int cm[CMBLENMAX] = {1, 3, 2, 4, 5};
	int len = 5;

	bzero(cmb, sizeof(int) * CMBLENMAX);
	next_cmb(cmb, 0, len);
	//init_bf(cm, 5);
	return (0);
}
