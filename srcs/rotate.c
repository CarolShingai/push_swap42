/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:42:54 by cshingai          #+#    #+#             */
/*   Updated: 2024/06/27 17:41:22 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate(t_list **stack)
{
	t_list	*old_head;
	t_list	*aux;

	if ((*stack)->next == NULL)
		return ;
	old_head = *stack;
	*stack = (*stack)->next;
	old_head->next = NULL;
	aux = *stack;
	if (aux)
		aux->prev = NULL;
	while (aux->next)
		(aux) = aux->next;
	aux->next = old_head;
	old_head->prev = aux->next;
}

void	ra(t_list **stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

void	rb(t_list **stack_b)
{
	rotate(stack_b);
	ft_printf("ra\n");
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	ft_printf("ra\n");
}
