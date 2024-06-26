/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:42:54 by cshingai          #+#    #+#             */
/*   Updated: 2024/06/26 19:55:51 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate(t_list **stack)
{
	t_list	*temp;

	if ((*stack)->next == NULL)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;
	while((*stack)->next)
		(*stack)->next = (*stack)->next;
	(*stack)->next = temp;
	temp->next = NULL;
	temp->prev = (*stack)->next;
}
