/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:37:39 by cshingai          #+#    #+#             */
/*   Updated: 2024/06/27 17:01:23 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_list **list)
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

void	sa(t_list *stack_a)
{
	swap(&stack_a);
	ft_printf("sa\n");
}

void	sb(t_list *stack_b)
{
	swap(&stack_b);
	ft_printf("sb\n");
}

void	ss(t_list *stack_a, t_list *stack_b)
{
	swap(&stack_a);
	swap(&stack_b);
	ft_printf("ss\n");
}
