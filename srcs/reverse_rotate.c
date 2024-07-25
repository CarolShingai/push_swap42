/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:12:59 by cshingai          #+#    #+#             */
/*   Updated: 2024/07/24 21:15:29 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	reverse_rotate(t_node **stack)
{
	t_node	*new_head;
	t_node	*prev;

	new_head = *stack;
	prev = NULL;
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	while (new_head->next)
	{
		prev = new_head;
		new_head = new_head->next;
	}
	if (prev)
		prev->next = NULL;
	new_head->next = *stack;
	new_head->prev = NULL;
	(*stack)->prev = new_head;
	*stack = new_head;
}

void	rra(t_node **stack_a)
{
	reverse_rotate(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_node **stack_b)
{
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}
