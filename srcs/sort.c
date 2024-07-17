/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:43:45 by cshingai          #+#    #+#             */
/*   Updated: 2024/07/17 13:56:32 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three(t_node **stack)
{
	if (is_ordened(*stack) == TRUE)
		return ;
	if ((*stack)->value == (*stack)->biggest->value)
		ra(stack);
	else if ((*stack)->next->value == (*stack)->biggest->value)
		rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}

void	sort(t_stack *stack)
{
	if (stack->size_a == 3)
		sort_three(&stack->stack_a);
	else
	{
		while(stack->size_a > 3)
		{
			pb(&stack->stack_a, &stack->stack_b);
			stack->size_a = stack_size(stack->stack_a);
			stack->size_b = stack_size(stack->stack_b);
		}
		sort_three(&stack->stack_a);
		put_price(stack);
	}
}
