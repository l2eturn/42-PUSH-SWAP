#include "pushswap.h"
#include <stdio.h>

void	print_stack(t_stack *stack, char name)
{
	t_node	*tmp;

	if (!stack)
	{
		printf("Stack %c is NULL\n", name);
		return ;
	}
	printf("Stack %c (size = %d):\n", name, stack->size);
	tmp = stack->top;
	while (tmp)
	{
		printf("%d", tmp->value);
		if (tmp->next)
			printf(" -> ");
		tmp = tmp->next;
	}
	printf("\n");
}
