/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:43:03 by cshingai          #+#    #+#             */
/*   Updated: 2024/07/06 18:32:48 by cshingai         ###   ########.fr       */
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

typedef struct s_list
{
	int				value;
	int				size;
	int				position;
	int				price;
	t_bool			half_superior;
	struct s_list	*biggest;
	struct s_list	*cheapest;
	struct s_list	*smallest;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

// price.c
int	get_price(t_list *stack);
int	calc_price(t_list *stack);
int	which_half(t_list *stack, int mov);
int	superior(t_list *stack, int mov);
int	inferior(t_list *stack, int mov);

// utils.c
void	ft_error(char *msg);
void	*ft_free_split(char **split);

//swap.c
void	swap(t_list **list);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);

// push.c
void	push(t_list **dest, t_list **src);
void	pa(t_list **dest, t_list **src);
void	pb(t_list **dest, t_list **src);

// rotate.c
void	rotate(t_list **stack);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);

// reverse_rotate.c
void	reverse_rotate(t_list **stack);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

// stack_utils.c
void	init_stack(t_list **stack, int argc, char **argv);
void	add_node(t_list **stack, int nbr);
void	find_smallest_node(t_list **stack);
void	find_biggest_node(t_list **stack);
int		stack_size(t_list *stack);

//sort.c
t_bool	is_ordened(t_list *stack_a);
void	sort_three(t_list **stack);
void	sort(t_list **stack, t_list **stack_b);

// validation.c
t_bool	check_args_num(char *str);
t_bool	check_max_min_value(char *str);
t_bool	check_doubles(long nbr, char **str, int idx);
t_bool	check_args(int argc, char **argv);

#endif
