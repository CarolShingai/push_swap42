/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:56:21 by cshingai          #+#    #+#             */
/*   Updated: 2024/07/22 16:03:56 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	set_target_b(t_stack *stack)
{
	t_node	*temp;

	temp = stack->stack_b;
	while (temp)
	{
		temp->target = get_target_in_a(stack, temp);
		temp = temp->next;
	}
}

t_node	*get_target_in_a(t_stack *stack, t_node *node_b)
{
	t_node	*temp;
	t_node	*target;
	int		current_value;

	if (node_b == NULL)
		stack->target_a = NULL;
	temp = stack->stack_a;
	target = temp;
	current_value = stack->stack_a->value;
	while (temp)
	{
		if (node_b->value < temp->value)
		{
			current_value = temp->value;
			if (current_value < target->value
				|| node_b->value > target->value)
				target = temp;
		}
		temp = temp->next;
	}
	node_b->target = target;
	return(target);
}
