#include <unistd.h>
#include "header.h"

int		make_op(t_tabs *tab, int op)
{
	if (op & PB)
		return (push_b(tab));
	else if (op & PA)
		return (push_a(tab));
	else if (op & RA)
		return (rotate_a(tab));
	else if (op & RB)
		return (rotate_b(tab));
	else if (op & RR)
		return (rotate_ab(tab));
	else if (op & RRA)
		return (revrotate_a(tab));
	else if (op & RRB)
		return (revrotate_b(tab));
	else if (op & RRR)
		return (revrotate_ab(tab));
	else if (op & SA)
		return (swap_a(tab));
	else if (op & SB)
		return (swap_b(tab));
	else if (op & SS)
		return (swap_ab(tab));
	else
		write(1, "FTW\n", 4);
	return (0);
}

/*
 * op usefull teste si les deux operations sont compatibles
 */

int		op_usefull(int	both_op)
{
	static int	useless[] = {(RA | RB), (RRA | RRB), (SA | SB),
							(RA | RRA), (RB | RRB), (RR | RRR),
							(SA | SA), (SB | SB), (SS | SS),
							(RR | RRB), (RR | RRA), (RRR | RRA), (RRR | RB),
							(SS | SA), (SS | SB)};
	int			i;

	i = 0;
	while (i < 15)
	{
		if (useless[i] == both_op)
			return (0);
		i++;
	}
	return (1);
}

int		rec_try(t_tabs tab, int *seed, int head, int len)
{
	t_tabs	temp;
	int		op;

	// si op a zero alors on test
	op = 1;
	if (head == len)
	{
		if(is_sorted(&tab))
		{
			printf("seed = ");
			bf_printseed(seed);
			return (1);
		}
		return (0);
	}
	else
	{
		while (op < END)
		{
			seed[head] = op;
			temp = tab;
			if (head == 0 || (head > 0 && op_usefull(seed[head - 1] | op)))
			{
				if (make_op(&temp, op))
				{
					if (rec_try(temp, seed, head + 1, len))
						return (1);
				}
			}
			op <<= 1;
		}
	}
	return (0);
}

int		rec_bruteforce(t_tabs *tab)
{
	int	seed[SEEDLEN] = {0};
	int seedlen;

	seedlen = 0;
	while(seedlen < 20)
	{
		if(rec_try(*tab, seed, 0, seedlen))
			break ;
		seedlen++;
	}
	return (1);
}
