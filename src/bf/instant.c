#include "push_swap.h"
#include "instant.h"

static char	*little_solution(int comb)
{
	int			i;
	static		t_solution solutions[33] = {
		{1, ""}, {12, "a"}, {21, "sa"}, {123, "aa"}, {132, "asa"}, {213, "saa"},
		{231, "qsapa"}, {312, "qaap"}, {321, "qsaap"}, {1234, "aaa"},
		{1243, "aasa"}, {1324, "asaa"}, {1342, "aqsapa"}, {1423, "aqaap"},
		{1432, "aqsaap"}, {2134, "saaa"}, {2143, "saasa"}, {2314, "qsapaa"},
		{2341, "qqsappaa"}, {2413, "qsapasa"}, {2431, "qquapaap"},
		{3124, "qaapa"}, {3142, "qasapa"}, {3214, "qsaapa"}, {3241, "qqsapapa"},
		{3412, "qqaappa"}, {3421, "qqsaappa"}, {4123, "qaaap"},
		{4132, "qasaap"}, {4213, "qsaaap"}, {4231, "qqsapaap"},
		{4312, "qqaapap"}, {4321, "qqsaapap"}
	};

	i = 0;
	while (i < 33)
	{
		if (solutions[i].cmb == comb)
			return (solutions[i].ops);
		i++;
	}
	return (NULL);
}

static int		combination_five(int comb)
{
//	printf("combi_five comb = %d\n", comb);
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

static char	*solution_five(int index)
{
	static char sol[120][15] = {
		"aaaa", "aaasa", "aasaa", "aaqsapa", "aaqaap", "aaqsaap",
		"asaaa", "asaasa", "aqsapaa", "aqqsappaa", "aqsapasa", "aqquapaap",
		"aqaapa", "aqasapa", "aqsaapa", "aqqsapapa", "aqqaappa", "aqqsaappa",
		"aqaaap", "aqasaap", "aqsaaap", "aqqsapaap", "aqqaapap", "aqqsaapap",
		"saaaa", "saaasa", "saasaa", "saaqsapa", "saaqaap", "saaqsaap",
		"qsapaaa", "qsapaasa", "qqsappaaa", "qqqsapppaaa", "qqsappaasa",
		"qqqsapppaasa", "qsapasaa", "qqaupaapa", "qquapaapa", "qqquapppaaa",
		"qqsaupaapa", "qqqsapupaapa", "sqsaaaap", "qqaupaaap", "qquapaaap",
		"qqqspuapaaap", "qqsaupaaap", "qqqsapupaaap", "qaapaa", "qaapasa",
		"qasapaa", "qaqsappaa", "qasapasa", "qaquapaap", "qsaapaa", "qsaapasa",
		"qqsapapaa", "qqqsappapaa", "qqsapapasa", "qqqsappapasa", "qqaappaa",
		"qqasappaa", "qqsaappaa", "qqqsapappaa", "qqqaapppaa", "qqqsaapppaa",
		"qqaappasa", "qqauapaap", "qquaapaap", "qqqspuaapaap", "qqsauapaap",
		"qqquaapppaa", "qaaapa", "qaasapa", "qasaapa", "qaqsapapa", "qaqaappa",
		"qaqsaappa", "qsaaapa", "qsaasapa", "qqsapaapa", "qqqsappaapa",
		"qqsapasapa", "qqquapaappa", "qqaapapa", "qqasapapa", "qqsaapapa",
		"qqqsapapapa", "qqqaappapa", "qqqsaappapa", "qqaaappa", "qqasaappa",
		"qqsaaappa", "qqqsapaappa", "qqqaapappa", "qqqsaapappa", "qaaaap",
		"qaasaap", "qasaaap", "qaqsapaap", "qaqaapap", "qaqsaapap", "qsaaaap",
		"qsaasaap", "qqsapaaap", "qqqsappaaap", "qqsapasaap", "qqquapaapap",
		"qqaapaap", "qqasapaap", "qqsaapaap", "qqqsapapaap", "qqqaappaap",
		"qqqsaappaap", "qqaaapap", "qqasaapap", "qqsaaapap", "qqqsapaapap",
		"qqqaapapap", "qqqsaapapap"};
	return (sol[index]);
}

static void	read_solution(char *solution, t_tab *tab, int i)
{
	while (solution[++i] != 0)
	{
		if (solution[i] == 'p')
			push_a(tab);
		else if (solution[i] == 'q')
			push_b(tab);
		else if (solution[i] == 'a')
			rotate_a(tab);
		else if (solution[i] == 'b')
			rotate_b(tab);
		else if (solution[i] == 'c')
			rrotate(tab);
		else if (solution[i] == 'd')
			revrotate_a(tab);
		else if (solution[i] == 'e')
			revrotate_b(tab);
		else if (solution[i] == 'f')
			rrevrotate(tab);
		else if (solution[i] == 's')
			swap_a(tab);
		else if (solution[i] == 't')
			swap_b(tab);
		else if (solution[i] == 'u')
			sswap(tab);
	}
}

int		instant_bf(int comb, t_tab *tab)
{
	int		index;
	char	*str;

	if (comb > 5000)
	{
//		printf("\nmore than 5\n");
		index = combination_five(comb);
//		printf("index = %d\n", index);
		str = solution_five(index);
	}
	else
		str = little_solution(comb);
	read_solution(str, tab, -1);
//	printf("%s\n", str);
	return (0);
}
