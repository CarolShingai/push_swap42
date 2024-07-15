/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   price.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:16:36 by cshingai          #+#    #+#             */
/*   Updated: 2024/07/15 17:50:23 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	get_price(t_stack *stack)
{
	int	stack_len;
	int	stack_half_b;

	stack_len = 0;
	stack_half_b = stack_size(stack->stack_b) / 2;
	set_positian(&stack->stack_a);
	set_positian(&stack->stack_b);
	stack->stack_b->price = stack->stack_b->position;
	while(stack->stack_b)
	{
		if ((stack->stack_b)->position <= stack_half_b)
		{
			(stack->stack_b)->half_superior = TRUE;
			(stack->stack_b)->price = (stack->stack_b)->position;
		}
		else if ((stack->stack_b)->position > stack_half_b)
		{
			(stack->stack_b)->half_superior = FALSE;
			(stack->stack_b)->price = stack_len - (stack->stack_b)->position;
		}
		stack->stack_b = stack->stack_b->next;
	}
}

void	set_positian(t_node **stack)
{
	t_node	*temp;

	(*stack)->position = -1;
	temp = *stack;
	while (temp)
	{
		temp->position++;
		temp = temp->next;
	}
}
