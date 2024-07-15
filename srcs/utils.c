/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:01:10 by cshingai          #+#    #+#             */
/*   Updated: 2024/07/15 16:45:50 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_error(char *msg)
{
	ft_printf("%s", msg);
	exit(0);
}

void	*ft_free_split(char **split)
{
	int	idx;

	idx = 0;
	while (split[idx])
	{
		free(&split[idx]);
		idx++;
	}
	free(split);
	return (NULL);
}

t_bool	is_ordened(t_node *stack_a)
{
	t_node *temp;

	temp = stack_a->next;
	while (stack_a && temp)
	{
		if (stack_a->value > temp->value)
			return FALSE;
		temp = temp->next;
		stack_a = stack_a->next;
	}
	return TRUE;
}
