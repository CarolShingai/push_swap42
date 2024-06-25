#include "../include/push_swap.h"

void apagar_printlist(t_list *node, char c)
{
	while(node != NULL)
	{
		ft_printf("Minha lista %c: %d\n", c ,node->value);
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
	pb(stack_b, stack_a);
	apagar_printlist(stack_a,'a');
	apagar_printlist(stack_b, 'b');
	return (0);
}
