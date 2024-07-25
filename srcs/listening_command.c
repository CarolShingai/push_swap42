/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listening_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 10:40:01 by cshingai          #+#    #+#             */
/*   Updated: 2024/07/25 13:10:43 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    listen_command(void (*f)(t_stack **), t_stack **stack)
{
    int n;

    n = 0;
    if (f == (void *)ra && (*stack)->stack_b != NULL)
    {
        if (((*stack)->stack_b->value < (*stack)->stack_b->next->value)
            && ((*stack)->stack_b->target == (*stack)->stack_b->next->target))
            f = (void *)rr;
        // else
        //     f = (void *)ra;
    }
    if (f == (void *)rra && (*stack)->stack_b != NULL)
    {
        if (((*stack)->stack_b->value < (*stack)->stack_b->next->value)
            && ((*stack)->stack_b->target == (*stack)->stack_b->next->target))
            f = (void *)rrr;
        // else
        //     f = (void *)rra;
    }
    n++;
    f(stack);
    ft_printf("%d\n", n);
}
