#include "../include/push_swap.h"

void apagar_printlist(t_list *node)
{
	while(node)
	{
		ft_printf("Minha lista: %d\n", node->value);
		node = node->next;
	}
}


int	main(int argc, char **argv)
{
	t_list *stack_a;
	t_list *stack_b;

	stack_a = NULL;
	stack_b = NULL;
	init_stack(&stack_a, argc, argv);
	swap(&stack_a);
	// list = (t_list)swap(argv);
	apagar_printlist(stack_a);
	return (0);
}
