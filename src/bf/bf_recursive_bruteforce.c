#include <unistd.h>
#include "bf_header.h"

int		make_op(t_tabs *tab, int op)
{
	if (op & PB)
		return (bf_push_b(tab));
	else if (op & PA)
		return (bf_push_a(tab));
	else if (op & RA)
		return (bf_rotate_a(tab));
	else if (op & RB)
		return (bf_rotate_b(tab));
	else if (op & RR)
		return (bf_rotate_ab(tab));
	else if (op & RRA)
		return (bf_revrotate_a(tab));
	else if (op & RRB)
		return (bf_revrotate_b(tab));
	else if (op & RRR)
		return (bf_revrotate_ab(tab));
	else if (op & SA)
		return (bf_swap_a(tab));
	else if (op & SB)
		return (bf_swap_b(tab));
	else if (op & SS)
		return (bf_swap_ab(tab));
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

	op = 1;
	if (head == len)
	{
		if(bf_is_sorted(&tab))
		{
//			printf("seed = ");
//			bf_printseed(seed);
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

int		rec_bruteforce(t_tabs *tab, int *seed)
{
	int seedlen;

	seedlen = 0;
//	bf_printtab(tab);
	while(seedlen < 20)
	{
		if(rec_try(*tab, seed, 0, seedlen))
			break ;
		seedlen++;
	}
	return (1);
}
