/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:38:13 by cshingai          #+#    #+#             */
/*   Updated: 2024/07/05 16:55:21 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_bool	check_args_num(char *str)
{
	int	idx;

	idx = 0;
	if (str[idx] == '-' || str[idx] == '+')
		idx++;
	while (str[idx])
	{
		if (!ft_isdigit(str[idx]))
			return (FALSE);
		idx++;
	}
	return (TRUE);
}

t_bool	check_max_min_value(char *str)
{
	long	number;

	number = ft_atoi(str);
	if (number > INT_MAX || number < INT_MIN)
		return (FALSE);
	return (TRUE);
}

t_bool	check_doubles(long nbr, char **str, int idx)
{
	idx++;
	while (str[idx])
	{
		if (nbr == ft_atoi(str[idx]))
			return (FALSE);
		idx++;
	}
	return (TRUE);
}

// tratar casos com split
t_bool	check_args(int argc, char **argv)
{
	int		idx;
	long	tmp_nbr;

	idx = 1;
	if (argc < 2)
		ft_error(NO_ARGS);
	while (argv[idx])
	{
		tmp_nbr = ft_atoi(argv[idx]);
		if (check_args_num(argv[idx]) == 0)
			return (ft_error(ERROR), FALSE);
		if (check_max_min_value(argv[idx]) == 0)
			return (ft_error(ERROR), FALSE);
		if (check_doubles(tmp_nbr, argv, idx) == 0)
			return (ft_error(ERROR), FALSE);
		idx++;
	}
	return (TRUE);
}
