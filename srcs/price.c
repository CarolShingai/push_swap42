/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   price.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:16:36 by cshingai          #+#    #+#             */
/*   Updated: 2024/07/12 17:10:05 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// int	get_price(t_list **stack)






// int	get_price(t_list **stack)
// {
// 	int	idx;
// 	int	price;
// 	int	stack_half;

// 	stack_half = stack_size(*stack) / 2;
// 	idx = 0;
// 	while (*stack)
// 	{
// 		(*stack)->position = idx;
// 		if ((*stack)->position <= stack_half)
// 			(*stack)->half_superior = TRUE;
// 		else
// 			(*stack)->half_superior = FALSE;
// 		price = calc_price(*stack);
// 		(*stack)->price = price;
// 		*stack = (*stack)->next;
// 		idx++;
// 	}
// 	return (price);
// }

// int	calc_price(t_list *stack)
// {
// 	int	mov;
// 	int	price;

// 	if (stack->half_superior == TRUE)
// 		mov = 0;
// 	else
// 		mov = stack->size;
// 	price = which_half(stack, mov);
// 	return (price);
// }

// int	which_half(t_list *stack, int mov)
// {
// 	int	price;

// 	if (stack->half_superior == TRUE)
// 		price = superior(stack, mov);
// 	else
// 		price = inferior(stack, mov);
// 	return (price);
// }

// int	superior(t_list *stack, int mov)
// {
// 	int	midle;

// 	midle = (stack_size(stack) / 2) - 1;
// 	if (stack->position == 0)
// 		mov = 0;
// 	while (stack && mov <= stack->position && stack->position > 0 && midle >= 0)
// 	{
// 		mov++;
// 		midle--;
// 		stack = stack->next;
// 	}
// 	return (mov);
// }

// int	inferior(t_list *stack, int mov)
// {
// 	int	midle;

// 	midle = (stack_size(stack) / 2) - 1;
// 	while (stack && stack->position > 0 && midle >= 0)
// 	{
// 		midle--;
// 		mov--;
// 		stack = stack->next;
// 	}
// 	return (mov);
// }
