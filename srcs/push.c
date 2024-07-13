/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:49:38 by cshingai          #+#    #+#             */
/*   Updated: 2024/07/12 20:44:48 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* 1- procedimento para adicionar elemento no inicio da lista

*/
void	push(t_node **dest, t_node **src)
{
	t_node	*new_node;

	if (*src == NULL)
		return ;
	new_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	new_node->prev = NULL;
	if (*dest == NULL)
		new_node->next = NULL;
	else
	{
		new_node->next = *dest;
		(*dest)->prev = new_node;
	}
	*dest = new_node;
}

//from b to a
void	pa(t_node **dest, t_node **src)
{
	push(dest, src);
	ft_printf("pa\n");
}

//from a to b
void	pb(t_node **dest, t_node **src)
{
	push(src, dest);
	ft_printf("pb\n");
}
