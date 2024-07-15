/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 19:58:10 by cshingai          #+#    #+#             */
/*   Updated: 2024/07/15 16:39:59 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*init_stack(t_node *list_a, t_node *list_b)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	stack->stack_a = list_a;
	stack->stack_b = list_b;

	stack->size_a = stack_size(stack->stack_a);
	stack->size_b = stack_size(stack->stack_b);
	return (stack);
	// info.size = stack_size(*stack);
}

void	find_biggest_node(t_node **stack)
{
	t_node	*temp;

	if (*stack == NULL && (*stack)->next == NULL)
		return ;
	(*stack)->biggest = *stack;
	temp = (*stack)->next;
	while (temp)
	{
		if ((*stack)->biggest->value < temp->value)
			(*stack)->biggest = temp;
		temp = temp->next;
	}
}

void	find_smallest_node(t_node **stack)
{
	t_node	*temp;

	if (*stack == NULL && (*stack)->next == NULL)
		return ;
	(*stack)->smallest = *stack;
	temp = (*stack)->next;
	while (temp)
	{
		if ((*stack)->smallest->value > temp->value)
			(*stack)->smallest = temp;
		temp = temp->next;
	}
}

int	stack_size(t_node *stack)
{
	int	count;

	if (stack == NULL)
		return (0);
	count = 0;
	while (stack)
	{
		count++;
		stack =  stack->next;
	}
	return (count);
}
