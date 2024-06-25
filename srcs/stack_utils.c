/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 19:58:10 by cshingai          #+#    #+#             */
/*   Updated: 2024/06/24 23:20:17 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


void	init_stack(t_list **stack, int argc, char **argv)
{
	int	idx;

	idx = 0;
	if (check_args(argc, argv) == TRUE)
	{
		while (++idx < argc)
			add_node(stack, ft_atoi(argv[idx]));
	}
}

void	add_node(t_list **stack, int nbr)
{
	t_list	*node;
	t_list	*aux;
	
	node = malloc(sizeof (t_list));
	node->size = 0;
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
	(*stack)->size += 1;
	ft_printf("size:%d\n", (*stack)->size);
}
