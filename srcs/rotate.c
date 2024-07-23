/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:42:54 by cshingai          #+#    #+#             */
/*   Updated: 2024/07/22 20:52:38 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate(t_node **stack)
{
	t_node	*old_head;
	t_node	*aux;

	if ((*stack)->next == NULL)
		return ;
	old_head = *stack;
	*stack = (*stack)->next;
	aux = *stack;
	if (aux)
		aux->prev = NULL;
	while (aux->next)
		(aux) = aux->next;
	aux->next = old_head;
	old_head->prev = aux->next;
	old_head->next = NULL;
}

void	ra(t_node **stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

void	rb(t_node **stack_b)
{
	rotate(stack_b);
	ft_printf("ra\n");
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("ra\n");
}
