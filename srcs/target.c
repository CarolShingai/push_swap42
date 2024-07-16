/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:56:21 by cshingai          #+#    #+#             */
/*   Updated: 2024/07/16 19:49:33 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	get_target(t_stack *stack)
{
	t_node	*temp;
	int		current_value;

	if (stack->stack_b == NULL)
		stack->target_a = NULL;
	temp = stack->stack_a;
	stack->target_a = temp;
	current_value = stack->target_a->value;
	while (temp)
	{
		if (stack->stack_b->value < temp->value)
		{
			current_value = temp->value;
			if (current_value < stack->target_a->value
				|| stack->stack_b->value > stack->target_a->value)
				stack->target_a = temp;
		}
		temp = temp->next;
	}
}
