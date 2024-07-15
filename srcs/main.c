/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:05:35 by cshingai          #+#    #+#             */
/*   Updated: 2024/07/15 03:11:25 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	apagar_printlist(t_node *node, char c)
{
	while (node)
	{
		ft_printf("Minha lista %c: %d\n", c, node->value);
		node = node->next;
	}
}

int	main(int argc, char **argv)
{
	t_node	*list;
	t_stack	*stacks;

	if (check_args(argc, argv) == TRUE)
		list = build_list(argc, argv);
	stacks = init_stack(list, NULL);
	if (is_ordened(list) == FALSE)
		sort(stacks->stack_a, stacks->stack_b);
	apagar_printlist(stack_a, 'a');
	ft_printf("%d",stack_b->price );
	// apagar_printlist(stack_b, 'b');
	return (0);
}
