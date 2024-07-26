/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:05:35 by cshingai          #+#    #+#             */
/*   Updated: 2024/07/25 20:22:09 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

void	apagar_printlist_a(t_node *node)
{
	while (node)
	{
		ft_printf("Minha lista a: %d\n", node->value);
		node = node->next;
	}
}

void	apagar_printlist_b(t_node *node)
{
	while (node)
	{
		ft_printf("Minha lista b: %d\n", node->value);
		node = node->next;
	}
}

int	main(int argc, char **argv)
{
	t_node	*list;
	t_stack	*stacks;

	list = build_list(argc, argv);
	stacks = init_stack(list, NULL);
	if (is_ordened(stacks->stack_a) == FALSE)
		sort(stacks);
	apagar_printlist_a(stacks->stack_a);
	apagar_printlist_b(stacks->stack_b);
	free_stack(&stacks->stack_a);
	free(stacks);
	return (0);
}
