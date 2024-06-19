#include "../include/push_swap.h"

int	check_args_num(char *str)
{
	int	idx;

	idx = 0;
	if (str[idx] == '-' || str[idx] == '+')
		idx++;
	while (str[idx])
	{
		if (!ft_isdigit(str[idx]))
			return(0);
		idx++;
	}
	return(1);
}

int	check_max_value(char *str)
{
	long	number;

	number = ft_atoi(str);
	if (number > INT_MAX)
		return (0);
	return(1);
}

int	check_doubles(long nbr, char *str, int idx)
{
	idx++;
	while(str[idx])
	{
		if (nbr == ft_atoi(&str[idx]))
		{
			ft_printf("%d", nbr);
			ft_printf("%d\n", ft_atoi(&str[idx]));
			return(0);
		}
		idx++;
	}
	return(1);
}
//alterar msg de erro
void	check_args(char **argv)
{
	int		idx;
	long	tmp_nbr;

	idx = 1;
	while (argv[idx])
	{
		tmp_nbr = ft_atoi(argv[idx]);
		if (check_args_num(argv[idx]) == 0)
			ft_error(NOT_INT);
		if (check_max_value(argv[idx]) == 0)
			ft_error(BIGGER_INT_MAX);
		if (check_doubles(tmp_nbr, argv[1], idx) == 0)
			ft_error(DOBLES);
		idx++;
	}
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		ft_error(ZERO_ARGS);
	check_args(argv);
	return(0);
}
