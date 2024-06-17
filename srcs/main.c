#include "../include/push_swap.h"
#include <limits.h>

void	ft_error(char *msg)
{
	ft_printf("%s", msg);
	exit(0);
}


void	check_argcs_int(char *nbr)
{
	int idx = 0;
	while(nbr[idx])
	{
		if (!ft_isdigit(nbr[idx]))
			ft_error(NOT_INT);
		idx++;
	}
}

void	check_args_doubles(char *nbr, char **nbr_all, int idx)
{
	int	idx2;

		idx2 = idx + 1;
	while(nbr_all[idx2])
	{
		ft_printf("entrou\n");
		ft_printf("%s\n", &nbr);
		if (nbr == nbr_all[idx2])
			ft_error(DOBLES);
		idx2++;
	}
}

void	check_args(char **argv)
{
	int idx;
	// int j;

	idx = 1;
	while (argv[idx])
	{
		check_argcs_int(argv[idx]);
		check_args_doubles(&argv[idx], &argv, idx);
		idx++;
	}
	// j = 0;
}

// void	check_number(char **argv)
// {
// 	int idx;
// 	int number;

// 	idx = 0;
// 	while (argv[idx])
// 	{
// 		number = ft_atoi(argv[idx]);
// 		if (number == INT_MAX)
// 			ft_error(BIG_MAX);
// 	}
// }


int	main(int argc, char **argv)
{
	if (argc < 2)
		ft_error(ZERO_ARGS);
	check_args(argv);
	// check_number(argv);
	return(0);
}
