/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:43:45 by cshingai          #+#    #+#             */
/*   Updated: 2024/07/06 18:12:37 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three(t_list **stack)
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

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_a)->size > 3)
	{
		pb(stack_b, stack_a);
		pb(stack_b, stack_a);
		sort_three(stack_a);
		if ((*stack_b)->value == (*stack_a)->biggest->value)
		{
			pa(stack_a, stack_b);
			ra(stack_a);
		}
		else if ((*stack_b)->value == (*stack_a)->smallest->value)
			pa(stack_a, stack_b);
		else
		{
			find_smallest_node(stack_b);
		}
	}
}

void	sort(t_list **stack, t_list **stack_b)
{
	if ((*stack)->size == 3)
		sort_three(stack);
	else if ((*stack)->size == 5)
		sort_five(stack, stack_b);
}

t_bool	is_ordened(t_list *stack)
{
	t_list *temp;

	if (stack->size == 1)
		return TRUE;
	temp = stack->next;
	while (stack && temp)
	{
		if (stack->value > temp->value)
			return FALSE;
		temp = temp->next;
		stack = stack->next;
	}
	return TRUE;
}
