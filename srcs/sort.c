/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:43:45 by cshingai          #+#    #+#             */
/*   Updated: 2024/07/03 19:35:39 by cshingai         ###   ########.fr       */
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
		sa(*stack);
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
