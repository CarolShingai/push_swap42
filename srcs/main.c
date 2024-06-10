#include "push_swap.h"

int	main(int argc, char **argv)
{
	check_args(argv);
}

int	check_args(char **argv)
{
	int i;

	i = 0;
	if (!ft_isdigit(&argv[i]))
		ft_error();
}

void	ft_error(void)
{
	exit(0);
}
