/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_other.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:56:47 by cshingai          #+#    #+#             */
/*   Updated: 2024/07/25 13:55:17 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_others(t_stack *stack)
{
	while(stack->size_a > 3)
	{
		push_nodes(&stack);
		stack->size_a = stack_size(stack->stack_a);
		stack->size_b = stack_size(stack->stack_b);
	}
	sort_three(&stack->stack_a, stack);
    orderedStackTransfer(stack);
    if(stack->stack_b == NULL)
    {
        while(stack->stack_a->value != stack->smallest->value)
			smallest_direction(stack);
    }
}

void    orderedStackTransfer(t_stack *stack)
{
	t_node	*cheapest;
    
	while(stack->stack_b != NULL)
	{
		put_price(stack);
		cheapest = get_cheapest_price(stack->stack_b);
		stack->target_b = cheapest;
		stack->target_a = cheapest->target;
		target_at_top(stack, cheapest);
		pa(&stack->stack_a, &stack->stack_b);
		stack->size_a++;
		stack->size_b--;
	}
}

void	smallest_direction(t_stack *stack)
{
	if (stack->smallest->half_superior == TRUE)
		rra(&stack->stack_a);
	else
		ra(&stack->stack_a);
}

void	push_nodes(t_stack **stack)
{
	// t_node	*last;
	
	// last = find_last_node((*stack)->stack_a);
	if((*stack)->stack_a->value != (*stack)->biggest->value)
	{
		// if ((*stack)->stack_a->value > (*stack)->stack_a->next->value)
		// {
		// 	if ((*stack)->stack_a->value >= last->value)
		// 		ra(&(*stack)->stack_a);
		// 	else
		// 		sa(&(*stack)->stack_a);
		// }
		// else
			pb(&(*stack)->stack_a, &(*stack)->stack_b);
	}
	else
		ra(&(*stack)->stack_a);
}
