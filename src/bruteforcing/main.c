#include "header.h"

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
		init_bf(cmb, 5);
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
