/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:43:03 by cshingai          #+#    #+#             */
/*   Updated: 2024/06/24 22:40:46 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../lib/libft/libft.h"
# include "../lib/ft_printf/src/ft_printf.h"
# include <limits.h>

# define ERROR "Error\n"
# define NO_ARGS ""

// typedef struct s_elements
// {
//     int     size;
// }   t_elements;

typedef struct s_list
{
	int				value;
    int             size;
	struct s_list	*next;
    struct s_list   *prev;
}					t_list;

typedef enum e_bool
{
    TRUE = 1,
    FALSE = 0
}   t_bool;

// utils.c
void	ft_error(char *msg);
void	*ft_free_split(char **split);

// validation.c
int		check_args_num(char *str);
int		check_max_value(char *str);
int		check_doubles(long nbr, char **str, int idx);
t_bool	check_args(int argc, char **argv);

//swap.c
void	swap(t_list **list);

// stack_utils.c
void	init_stack(t_list **stack, int argc, char **argv);
void	add_node(t_list **stack, int nbr);

#endif
