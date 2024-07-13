/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   price.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:16:36 by cshingai          #+#    #+#             */
/*   Updated: 2024/07/12 20:44:32 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	get_price(t_node **stack_a, t_node **stack_b)
{
	int	stack_len;
	int	stack_half;

	stack_half = stack_size(*stack_b) / 2;
	stack_len = (*stack_b)->size;
	set_positian(stack_a);
	set_positian(stack_b);
	(*stack_b)->price = (*stack_b)->position;
	while(*stack_b)
	{
		if ((*stack_b)->position <= stack_half)
		{
			(*stack_b)->half_superior = TRUE;
			(*stack_b)->price = (*stack_b)->position;
		}
		else if ((*stack_b)->position > stack_half)
		{
			(*stack_b)->half_superior = FALSE;
			(*stack_b)->price = stack_len - (*stack_b)->position;
		}
		*stack_b = (*stack_b)->next;
	}
}

void	set_positian(t_node **stack)
{
	(*stack)->position = -1;
	while (*stack)
	{
		(*stack)->position++;
		(*stack) = (*stack)->next;
	}
}
