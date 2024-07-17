/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   price.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:16:36 by cshingai          #+#    #+#             */
/*   Updated: 2024/07/16 21:02:34 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	put_price(t_stack *stack)
{
	int	half_a;
	int	half_b;

	half_a = stack->size_a / 2;
	half_b = stack_size(stack->stack_b) / 2;
	stack->target_a = get_target_in_a(stack);
	set_positian(&stack->stack_a);
	set_positian(&stack->stack_b);
	put_price_in_a(stack, half_a);
	put_price_in_b(stack, half_b);
}

void	put_price_in_b(t_stack *stack, int half_b)
{
	t_node	*temp;

	temp = stack->stack_b;
	temp->price = temp->position;
	while(temp)
	{
		if ((temp)->position <= half_b)
		{
			(temp)->half_superior = TRUE;
			(temp)->price = (temp)->position;
		}
		else if ((temp)->position > half_b)
		{
			(temp)->half_superior = FALSE;
			(temp)->price = stack->size_b - (temp)->position;
		}
		temp->price += stack->target_a->price;
		temp = temp->next;
	}
}

void	put_price_in_a(t_stack *stack, int half_a)
{
	t_node	*temp;

	temp = stack->stack_a;
	temp->price = temp->position;
	while(temp)
	{
		if ((temp)->position <= half_a)
		{
			temp->half_superior = TRUE;
			temp->price = (temp)->position;
		}
		else if (temp->position > half_a)
		{
			temp->half_superior = FALSE;
			temp->price = stack->size_a - (temp)->position;
		}
		temp = temp->next;
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
