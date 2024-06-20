#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_list **stack_a;

	stack_a = NULL;
	check_args(argc, argv);
	add_node(stack_a, ft_atoi(argv[1]));
	// list = (t_list)swap(argv);
	// ft_printf("%s", argv[2]);
	return(0);
}
