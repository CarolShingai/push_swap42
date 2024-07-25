/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_top.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:22:35 by cshingai          #+#    #+#             */
/*   Updated: 2024/07/24 22:19:23 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	target_at_top(t_stack *stack, t_node *cheapest)
{
	// if (cheapest->half_superior == TRUE && stack->target_a->half_superior == TRUE)
	// 	target_at_top_superior(&stack, cheapest);
	// else if (cheapest->half_superior == FALSE && stack->target_a->half_superior == FALSE)
	// 	target_at_top_inferior(&stack, cheapest);
	// else
	// {
		target_a_at_top(&stack, cheapest);
		target_b_at_top(&stack, cheapest);
	// }
}

void	target_at_top_superior(t_stack **stack, t_node *cheapest)
{
	t_node	*temp;
	t_node	*temp_a;

	temp = (*stack)->stack_b;
	temp_a = (*stack)->stack_a;
	if (temp == cheapest && temp_a != cheapest->target)
	{
		while(temp_a != cheapest->target)
			rra(&temp_a);
	}
	if (temp_a == cheapest->target && (temp != cheapest))
	{
		while(temp != cheapest)
			rrb(&temp);
	}
	else
		rrr(&temp_a, &temp);
	(*stack)->stack_a = temp_a;
	(*stack)->stack_b = temp;
}

void	target_at_top_inferior(t_stack **stack, t_node *cheapest)
{
	t_node	*temp;
	t_node	*temp_a;

	temp = (*stack)->stack_b;
	temp_a = (*stack)->stack_a;
	if (temp == cheapest && temp_a != (*stack)->target_a)
	{
		while(temp_a != (*stack)->target_a)
			ra(&temp_a);
	}
	if (temp_a == (*stack)->target_a && temp != cheapest)
	{
		while(temp != cheapest)
			rb(&temp);
	}
	else
		rr(&temp_a, &temp);
	(*stack)->stack_a = temp_a;
	(*stack)->stack_b = temp;
}

void	target_a_at_top(t_stack **stack, t_node *cheapest)
{
	if ((*stack)->stack_a != cheapest->target)
	{
		while ((*stack)->stack_a != cheapest->target)
		{
			if ((*stack)->target_a->half_superior == TRUE)
				rra(&(*stack)->stack_a);
			else
				ra(&(*stack)->stack_a);
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
