/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:05:35 by cshingai          #+#    #+#             */
/*   Updated: 2024/07/12 20:48:52 by cshingai         ###   ########.fr       */
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
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	init_stack(&stack_a, argc, argv);
	if (is_ordened(stack_a) == FALSE)
		sort(&stack_a, &stack_b);
	apagar_printlist(stack_a, 'a');
	ft_printf("%d",stack_b->price );
	// apagar_printlist(stack_b, 'b');
	return (0);
}
