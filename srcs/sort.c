/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:43:45 by cshingai          #+#    #+#             */
/*   Updated: 2024/07/02 21:14:00 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three(t_list **stack)
{
	if ((*stack)->size == 1)
		return ;
	while (*stack)
	{
		if (*stack == (*stack)->biggest)
		{
			if((*stack)->next == (*stack)->smallest)
				swap(stack);
		}
	}
}
