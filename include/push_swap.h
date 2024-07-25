/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:43:03 by cshingai          #+#    #+#             */
/*   Updated: 2024/07/25 13:53:27 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../lib/libft/libft.h"
# include "../lib/ft_printf/src/ft_printf.h"
# include <limits.h>

# define ERROR "Error\n"
# define NO_ARGS ""

typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0
}	t_bool;

typedef struct s_node
{
	int				value;
	int				position;
	int				price;
	t_bool			half_superior;
	struct s_node	*target;
	struct s_node	*cheapest;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	int				size_a;
	int				size_b;
	t_node			*biggest;
	t_node 			*smallest;
	t_node			*target_a;
	t_node			*target_b;
	t_node			*stack_a;
	t_node			*stack_b;
}					t_stack;

/*Here I create the list, putting each element from argv, after using Atoi, in a node*/
void	apagar_printlist_a(t_node *node);

// build_list.c
t_node	*build_list(int argc, char **argv);
void	add_node(t_node **stack, int nbr);

// price.c
void	put_price(t_stack *stack);
void	put_price_in_b(t_stack *stack, int half_b);
void	put_price_in_a(t_stack *stack, int half_a);
void	set_positian_a(t_stack *stack, t_node *list);
void	set_positian_b(t_stack *stack, t_node *list);

//swap.c
void	swap(t_node **list);
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);

// push.c
void	push(t_node **dest, t_node **src);
void	pa(t_node **dest, t_node **src);
void	pb(t_node **dest, t_node **src);

// rotate.c
void	rotate(t_node **stack);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);

// reverse_rotate.c
void	reverse_rotate(t_node **stack);
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);

// stack_utils.c
t_stack	*init_stack(t_node *list_a, t_node *list_b);
void	find_smallest_node(t_stack **stack);
void	find_biggest_node(t_stack **stack);
int		stack_size(t_node *stack);
t_node	*find_last_node(t_node *stack);

//sort.c
void	sort_three(t_node **list_a, t_stack *stack);
void	sort(t_stack *stack_a);
t_node	*get_cheapest_price(t_node *list_b);
t_bool	is_target_top(t_stack *stack, t_node *cheapest);

// sort_other.c
void	sort_others(t_stack *stack);
void    orderedStackTransfer(t_stack *stack);
void	smallest_direction(t_stack *stack);
void	push_nodes(t_stack **stack);

// target.c
void	set_target_b(t_stack *stack);
t_node	*get_target_in_a(t_stack *stack, t_node *node_b);

// target_top.c
void	target_at_top(t_stack *stack, t_node *cheapest);
void	target_a_at_top(t_stack **stack, t_node *cheapest);
void	target_b_at_top(t_stack **stack, t_node *cheapest);

// utils.c
void	ft_error(char *msg);
void	*ft_free_split(char **split);
t_bool	is_ordened(t_node *stack);

// validation.c
t_bool	check_args_num(char *str);
t_bool	check_max_min_value(char *str);
t_bool	check_doubles(long nbr, char **str, int idx);
t_bool	check_args(int argc, char **argv);

void    listen_command(void (*f)(t_stack **), t_stack **stack);

#endif
