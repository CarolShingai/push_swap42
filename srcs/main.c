#include "../include/push_swap.h"
#include <limits.h>

void	ft_error(char *msg)
{
	ft_printf("%s", msg);
	exit(0);
}

void	check_args(char **argv)
{
	int idx;
	int j;

	idx = 1;
	j = 0;
	if (!ft_isdigit(*argv[idx]))
		ft_error(NOT_INT);
	// ft_printf("1:%s 2:%s", argv[idx], argv[j]);
	while (argv[idx])
	{
		j = idx + 1;
		if(argv[idx] == argv[j])
			ft_error(DUPLICATE);
		idx++;
	}
}

void	check_number(char **argv)
{
	int idx;
	int number;

	idx = 0;
	while (argv[idx])
	{
		number = ft_atoi(argv[idx]);
		if (number == INT_MAX)
			ft_error(BIG_MAX);
	}
}


int	main(int argc, char **argv)
{
	if (argc < 2)
		ft_error(ZERO_ARGS);
	check_args(argv);
	check_number(argv);
	return(0);
}
