/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:05:35 by cshingai          #+#    #+#             */
/*   Updated: 2024/07/16 21:11:10 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	apagar_printlist(t_node *node, char c)
{
	while (node != NULL)
	{
		ft_printf("Minha lista %c: %d\n", c, node->value);
		node = node->next;
	}
}

int	main(int argc, char **argv)
{
	t_node	*list;
	t_stack	*stacks;

	list = build_list(argc, argv);
	stacks = init_stack(list, NULL);
	// if (is_ordened(stacks->stack_a) == FALSE)
	// 	sort(stacks);
	// apagar_printlist(stacks->stack_a, 'a');
	apagar_printlist(stacks->stack_b, 'b');
	pb(&stacks->stack_a, &stacks->stack_b);
	pb(&stacks->stack_a, &stacks->stack_b);
	// get_target(stacks);
	put_price(stacks);
	ft_printf("price:%d\n", stacks->stack_b->price);
	// ft_printf("target:%d", stacks->target_a->value);
	return (0);
}
