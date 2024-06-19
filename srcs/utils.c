#include "../include/push_swap.h"

void	ft_error(char *msg)
{
	ft_printf("%s", msg);
	exit(0);
}

void	*ft_free_split(char **split)
{
	int	idx;

	idx = 0;
	while (split[idx])
	{
		free(&split[idx]);
		idx++;
	}
	free(split);
	return (NULL);
}
