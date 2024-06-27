/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:12:59 by cshingai          #+#    #+#             */
/*   Updated: 2024/06/27 17:51:11 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	reverse_rotate(t_list **stack)
{
	t_list	*new_head;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	new_head = *stack;
	while (new_head->next)
		new_head = new_head->next;
	new_head->next = *stack;
	new_head->prev->next = NULL;
	new_head->prev = NULL;
	*stack = new_head;
	(*stack)->next->prev = *stack;
}

void	rra(t_list **stack_a)
{
	reverse_rotate(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_list **stack_b)
{
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}
