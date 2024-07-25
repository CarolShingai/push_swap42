/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 00:06:44 by cshingai          #+#    #+#             */
/*   Updated: 2024/07/25 16:40:00 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_node	*build_list(int argc, char **argv)
{
	int	idx;
	t_node *list;

	idx = 0;
	list = NULL;
	if (check_args(argc, argv) == TRUE)
	{
		while (++idx < argc)
			add_node(&list, ft_atoi(argv[idx]));
	}
	else
		free_stack(&list);
	return(list);
}

void	add_node(t_node **stack, int nbr)
{
	t_node	*node;
	t_node	*aux;

	node = malloc(sizeof (t_node));
	if (!node)
		return ;
	node->value = nbr;
	node->next = NULL;
	if (*stack == NULL)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		aux = *stack;
		while (aux->next)
			aux = aux->next;
		aux->next = node;
		node->prev = aux;
	}
}
