/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 19:58:10 by cshingai          #+#    #+#             */
/*   Updated: 2024/07/12 16:31:34 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	init_stack(t_list **stack, int argc, char **argv)
{
	int	idx;

	idx = 0;
	if (check_args(argc, argv) == TRUE)
	{
		while (++idx < argc)
			add_node(stack, ft_atoi(argv[idx]));
	}
	find_smallest_node(stack);
	find_biggest_node(stack);
	(*stack)->size = stack_size(*stack);
}

void	add_node(t_list **stack, int nbr)
{
	t_list	*node;
	t_list	*aux;

	node = malloc(sizeof (t_list));
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

void	find_biggest_node(t_list **stack)
{
	t_list	*temp;

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

void	find_smallest_node(t_list **stack)
{
	t_list	*temp;

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

int	stack_size(t_list *stack)
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
	return(count);
}
