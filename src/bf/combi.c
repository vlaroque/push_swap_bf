/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 13:14:02 by vlaroque          #+#    #+#             */
/*   Updated: 2019/09/24 13:37:59 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		combination_five(int comb)
{
	static int	comb_tab[120] = {
		12345, 12354, 12435, 12453, 12534, 12543, 13245, 13254,
		13425, 13452, 13524, 13542, 14235, 14253, 14325, 14352, 14523, 14532,
		15234, 15243, 15324, 15342, 15423, 15432, 21345, 21354, 21435, 21453,
		21534, 21543, 23145, 23154, 23415, 23451, 23514, 23541, 24135, 24153,
		24315, 24351, 24513, 24531, 25134, 25143, 25314, 25341, 25413, 25431,
		31245, 31254, 31425, 31452, 31524, 31542, 32145, 32154, 32415, 32451,
		32514, 32541, 34125, 34152, 34215, 34251, 34512, 34521, 35124, 35142,
		35214, 35241, 35412, 35421, 41235, 41253, 41325, 41352, 41523, 41532,
		42135, 42153, 42315, 42351, 42513, 42531, 43125, 43152, 43215, 43251,
		43512, 43521, 45123, 45132, 45213, 45231, 45312, 45321, 51234, 51243,
		51324, 51342, 51423, 51432, 52134, 52143, 52314, 52341, 52413, 52431,
		53124, 53142, 53214, 53241, 53412, 53421, 54123, 54132, 54213, 54231,
		54312, 54321};
	int			i;

	i = 0;
	while (i < 120 && comb_tab[i] != comb)
		i++;
	return (i);
}

char	*solution_five(int index)
{
	static char sol[120][15] = {"aaaa", "aaasa", "aasaa", "aaqsapa", "aaqaap",
		"aaqsaap", "asaaa", "asaasa", "aqsapaa", "aqqsappaa", "aqsapasa",
		"aqquapaap", "aqaapa", "aqasapa", "aqsaapa", "aqqsapapa", "aqqaappa",
		"aqqsaappa", "aqaaap", "aqasaap", "aqsaaap", "aqqsapaap", "aqqaapap",
		"aqqsaapap", "saaaa", "saaasa", "saasaa", "saaqsapa", "saaqaap",
		"saaqsaap", "qsapaaa", "qsapaasa", "qqsappaaa", "qqqsapppaaa",
		"qqsappaasa", "qqqsapppaasa", "qsapasaa", "qqaupaapa", "qquapaapa",
		"qqquapppaaa", "qqsaupaapa", "qqqsapupaapa", "sqsaaaap", "qqaupaaap",
		"qquapaaap", "qqqspuapaaap", "qqsaupaaap", "qqqsapupaaap", "qaapaa",
		"qaapasa", "qasapaa", "qaqsappaa", "qasapasa", "qaquapaap", "qsaapaa",
		"qsaapasa", "qqsapapaa", "qqqsappapaa", "qqsapapasa", "qqqsappapasa",
		"qqaappaa", "qqasappaa", "qqsaappaa", "qqqsapappaa", "qqqaapppaa",
		"qqqsaapppaa", "qqaappasa", "qqauapaap", "qquaapaap", "qqqspuaapaap",
		"qqsauapaap", "qqquaapppaa", "qaaapa", "qaasapa", "qasaapa",
		"qaqsapapa", "qaqaappa", "qaqsaappa", "qsaaapa", "qsaasapa",
		"qqsapaapa", "qqqsappaapa", "qqsapasapa", "qqquapaappa", "qqaapapa",
		"qqasapapa", "qqsaapapa", "qqqsapapapa", "qqqaappapa", "qqqsaappapa",
		"qqaaappa", "qqasaappa", "qqsaaappa", "qqqsapaappa", "qqqaapappa",
		"qqqsaapappa", "qaaaap", "qaasaap", "qasaaap", "qaqsapaap", "qaqaapap",
		"qaqsaapap", "qsaaaap", "qsaasaap", "qqsapaaap", "qqqsappaaap",
		"qqsapasaap", "qqquapaapap", "qqaapaap", "qqasapaap", "qqsaapaap",
		"qqqsapapaap", "qqqaappaap", "qqqsaappaap", "qqaaapap", "qqasaapap",
		"qqsaaapap", "qqqsapaapap", "qqqaapapap", "qqqsaapapap"};

	return (sol[index]);
}

int		main(void)
{
	int		index;
	char	*str;

	index = combination_five(54321);
	str = solution_five(index);
	printf("%s\n", str);
	return (0);
}
