/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:43:45 by cshingai          #+#    #+#             */
/*   Updated: 2024/07/23 18:12:44 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three(t_node **list_a, t_stack *stack)
{
	if (is_ordened(*list_a) == TRUE)
		return ;
	if ((*list_a)->value == stack->biggest->value)
		ra(list_a);
	else if ((*list_a)->next->value == stack->biggest->value)
		rra(list_a);
	if ((*list_a)->value > (*list_a)->next->value)
		sa(list_a);
}

void	sort(t_stack *stack)
{
	if (stack->size_a == 3)
		sort_three(&stack->stack_a, stack);
	else
		while(!is_ordened(stack->stack_a) && stack->stack_b != NULL);
			sort_others(stack);
}

void	sort_others(t_stack *stack)
{
	t_node	*cheapest;

	while(stack->size_a > 3)
	{
		pb(&stack->stack_a, &stack->stack_b);
		stack->size_a = stack_size(stack->stack_a);
		stack->size_b = stack_size(stack->stack_b);
	}
	while(!is_ordened(stack->stack_a) && stack->stack_b != NULL)
	{
		put_price(stack);
		cheapest = get_cheapest_price(stack->stack_b);
		stack->target_b = cheapest;
		stack->target_a = cheapest->target;
		target_at_top(stack, cheapest);
		pa(&stack->stack_a, &stack->stack_b);
	}
}

t_node	*get_cheapest_price(t_node *list_b)
{
	t_node	*cheapest;
	t_node	*temp;

	cheapest = list_b;
	temp = list_b;
	while (temp)
	{
		if (cheapest->price > temp->price)
			cheapest = temp;
		temp = temp->next;
	}
	return (cheapest);
}

t_bool	is_target_top(t_stack *stack, t_node *cheapest)
{
	if (stack->stack_a == cheapest->target && stack->stack_b == cheapest)
		return (TRUE);
	else
		return (FALSE);
}
