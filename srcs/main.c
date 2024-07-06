/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:05:35 by cshingai          #+#    #+#             */
/*   Updated: 2024/07/06 18:36:23 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	apagar_printlist(t_list *node, char c)
{
	while (node)
	{
		ft_printf("Minha lista %c: %d\n", c, node->value);
		node = node->next;
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	init_stack(&stack_a, argc, argv);
	if (is_ordened(stack_a) == FALSE)
		sort_three(&stack_a);
	apagar_printlist(stack_a, 'a');
	ft_printf("%d", get_price(stack_a));
	// apagar_printlist(stack_b, 'b');
	return (0);
}
