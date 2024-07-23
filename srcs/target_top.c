/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_top.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:22:35 by cshingai          #+#    #+#             */
/*   Updated: 2024/07/23 18:58:13 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	target_at_top(t_stack *stack, t_node *cheapest)
{
	while(is_target_top(stack, cheapest) == FALSE)
	{
		if (cheapest->half_superior == TRUE && stack->target_a->half_superior == TRUE)
			target_at_top_superior(&stack, cheapest);
		else if (cheapest->half_superior == FALSE && stack->target_a->half_superior == FALSE)
			target_at_top_inferior(&stack, cheapest);
		else
		{
			target_a_at_top(&stack, cheapest);
			target_b_at_top(&stack, cheapest);
		}
	}
}

void	target_at_top_superior(t_stack **stack, t_node *cheapest)
{
	// t_node	*temp;
	// t_node	*temp_a;

	// temp = (*stack)->stack_b;
	// temp_a = (*stack)->stack_a;

	while((*stack)->stack_b != cheapest && (*stack)->stack_a != cheapest->target)
	{
		if ((*stack)->stack_b == cheapest && (*stack)->stack_a != cheapest->target)
		{
			while((*stack)->stack_a != cheapest->target)
				rra(&(*stack)->stack_a);
		}
		if ((*stack)->stack_a == cheapest->target && (*stack)->stack_b != cheapest)
		{
			while((*stack)->stack_b != cheapest)
				rrb(&(*stack)->stack_b);
		}
		else
			rrr(&(*stack)->stack_a, &(*stack)->stack_b);
	}
}

void	target_at_top_inferior(t_stack **stack, t_node *cheapest)
{
	// t_node	*temp;
	// t_node	*temp_a;

	// temp = stack->stack_b;
	// temp_a = stack->stack_a;

	while((*stack)->stack_b != cheapest && (*stack)->stack_a != (*stack)->target_a)
	{
		if ((*stack)->stack_b == cheapest && (*stack)->stack_a != (*stack)->target_a)
		{
			while((*stack)->stack_a != (*stack)->target_a)
				ra(&(*stack)->stack_a);
		}
		if ((*stack)->stack_a == (*stack)->target_a && (*stack)->stack_b != cheapest)
		{
			while((*stack)->stack_b != cheapest)
				rb(&(*stack)->stack_b);
		}
		else
			rr(&(*stack)->stack_a, &(*stack)->stack_b);
	}
}

void	target_a_at_top(t_stack **stack, t_node *cheapest)
{
	while ((*stack)->stack_a != cheapest->target)
	{
		if ((*stack)->target_a->half_superior == TRUE)
			rra(&(*stack)->stack_a);
		else
			ra(&(*stack)->stack_a);
	}
}

void	target_b_at_top(t_stack **stack, t_node *cheapest)
{
	while ((*stack)->stack_b != cheapest)
	{
		if ((*stack)->target_b->half_superior == TRUE)
			rrb(&(*stack)->stack_b);
		else
			rb(&(*stack)->stack_b);
	}
}
