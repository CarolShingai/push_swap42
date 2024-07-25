/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_top.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:22:35 by cshingai          #+#    #+#             */
/*   Updated: 2024/07/25 19:20:12 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	target_at_top(t_stack *stack, t_node *cheapest)
{
		target_a_at_top(&stack, cheapest);
		target_b_at_top(&stack, cheapest);
}

void	target_a_at_top(t_stack **stack, t_node *cheapest)
{
	while ((*stack)->stack_a != cheapest->target)
	{
		if ((*stack)->target_a->half_superior == TRUE)
			ra(&(*stack)->stack_a);
			// listen_command((void *)rra, stack);
		else
			rra(&(*stack)->stack_a);
			// listen_command((void *)ra, stack);
	}
}

void	target_b_at_top(t_stack **stack, t_node *cheapest)
{
	if ((*stack)->stack_b != cheapest)
	{
		while ((*stack)->stack_b != cheapest)
		{
			if ((*stack)->target_b->half_superior == TRUE)
				rb(&(*stack)->stack_b);
			else
				rrb(&(*stack)->stack_b);
		}
	}
}
