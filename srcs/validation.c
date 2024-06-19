/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:38:13 by cshingai          #+#    #+#             */
/*   Updated: 2024/06/19 18:32:18 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	check_doubles(long nbr, char **str, int idx)
{
	idx++;
	while(str[idx])
	{
		ft_printf("nbr:%d str[%d]:%d\n", nbr, idx, ft_atoi(str[idx]));
		if (nbr == ft_atoi(str[idx]))
		{
			ft_printf("nbr:%d str[%d]:%d\n", nbr, idx, ft_atoi(str[idx]));
			return(0);
		}
		idx++;
	}
	return(1);
}
// tratar casos com split
void	check_args(int argc, char **argv)
{
	int		idx;
	char	**args;
	long	tmp_nbr;

	idx = 1;
	while (argv[idx])
	{
		tmp_nbr = ft_atoi(argv[idx]);
		if (check_args_num(argv[idx]) == 0)
			ft_error(ERROR);
		if (check_max_value(argv[idx]) == 0)
			ft_error(ERROR);
		if (check_doubles(tmp_nbr, argv, idx) == 0)
			ft_error(ERROR);
		idx++;
	}
}
