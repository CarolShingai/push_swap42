/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:37:39 by cshingai          #+#    #+#             */
/*   Updated: 2024/07/12 20:44:53 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_node **list)
{
	if (*list == NULL || (*list)->size == 1)
		return ;
	(*list) = (*list)->next;
	(*list)->prev->next = (*list)->next;
	if ((*list)->next)
		(*list)->next->prev = (*list)->prev;
	(*list)->next = (*list)->prev;
	(*list)->prev = NULL;
}

void	sa(t_node **stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}

void	sb(t_node **stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}
