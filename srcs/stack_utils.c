/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 19:58:10 by cshingai          #+#    #+#             */
/*   Updated: 2024/07/25 17:43:44 by cshingai         ###   ########.fr       */
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
	find_biggest_node(&stack);
	find_smallest_node(&stack);
	return (stack);
}

void	find_biggest_node(t_stack **stack)
{
	t_node	*temp;

	if ((*stack)->stack_a == NULL && (*stack)->stack_a->next == NULL)
		return ;
	(*stack)->biggest = (*stack)->stack_a;
	temp = (*stack)->stack_a;
	while (temp)
	{
		if ((*stack)->biggest->value < temp->value)
			(*stack)->biggest = temp;
		temp = temp->next;
	}
}

void	find_smallest_node(t_stack **stack)
{
	t_node	*temp;

	if ((*stack)->stack_a == NULL && (*stack)->stack_a->next == NULL)
		return ;
	(*stack)->smallest = (*stack)->stack_a;
	temp = (*stack)->stack_a;
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

t_node	*find_last_node(t_node *stack)
{
	t_node	*temp;

	if (stack == NULL)
		return (NULL);
	temp = stack;
	while(temp->next)
		temp = temp->next;
	return(temp);
}
