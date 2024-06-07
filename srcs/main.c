/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:43:06 by cshingai          #+#    #+#             */
/*   Updated: 2024/06/07 15:01:40 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
