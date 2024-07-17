/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:56:21 by cshingai          #+#    #+#             */
/*   Updated: 2024/07/16 20:51:29 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_node	*get_target_in_a(t_stack *stack)
{
	t_node	*temp;
	t_node	*target;
	int		current_value;

	if (stack->stack_b == NULL)
		stack->target_a = NULL;
	temp = stack->stack_a;
	target = temp;
	current_value = stack->stack_a->value;
	while (temp)
	{
		if (stack->stack_b->value < temp->value)
		{
			current_value = temp->value;
			if (current_value < target->value
				|| stack->stack_b->value > target->value)
				target = temp;
		}
		temp = temp->next;
	}
	return(target);
}
