/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 19:58:10 by cshingai          #+#    #+#             */
/*   Updated: 2024/07/12 20:59:06 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	init_stack(t_node **stack, int argc, char **argv)
{
	int	idx;
	t_info	info;

	idx = 0;
	if (check_args(argc, argv) == TRUE)
	{
		while (++idx < argc)
			add_node(stack, ft_atoi(argv[idx]));
	}
	find_smallest_node(stack);
	find_biggest_node(stack);
	info.size = stack_size(*stack);
}

void	add_node(t_node **stack, int nbr)
{
	t_node	*node;
	t_node	*aux;

	node = malloc(sizeof (t_node));
	if (!node)
		return ;
	node->value = nbr;
	node->next = NULL;
	if (*stack == NULL)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		aux = *stack;
		while (aux->next)
			aux = aux->next;
		aux->next = node;
		node->prev = aux;
	}
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
