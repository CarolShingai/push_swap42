/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_top.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:22:35 by cshingai          #+#    #+#             */
/*   Updated: 2024/07/25 13:50:59 by cshingai         ###   ########.fr       */
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
	if ((*stack)->stack_a != cheapest->target)
	{
		while ((*stack)->stack_a != cheapest->target)
		{
			if ((*stack)->target_a->half_superior == TRUE)
				rra(&(*stack)->stack_a);
				// listen_command((void *)rra, stack);
			else
				ra(&(*stack)->stack_a);
				// listen_command((void *)ra, stack);
		}
	}
}

void	target_b_at_top(t_stack **stack, t_node *cheapest)
{
	if ((*stack)->stack_b != cheapest)
	{
		while ((*stack)->stack_b != cheapest)
		{
			if ((*stack)->target_b->half_superior == TRUE)
				rrb(&(*stack)->stack_b);
			else
				rb(&(*stack)->stack_b);
		}
	}
}
