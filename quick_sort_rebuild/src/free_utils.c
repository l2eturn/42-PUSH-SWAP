/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimvutt <slimvut@fpgij;dgj;ds.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 22:47:39 by slimvutt          #+#    #+#             */
/*   Updated: 2025/10/11 22:47:39 by slimvutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	free_stack(t_list *stack)
{
    t_list *tmp;
    while (stack)
    {
        tmp = stack->next;
        free(stack);
        stack = tmp;
    }
}

void	free_all(t_stack *stack, char **args, int ac)
{
	int	j;

	j = 0;
	free_stack(stack->stack_a);
	free_stack(stack->stack_b);
	if (ac == 2)
	{
		while (args[j])
			free(args[j++]);
		free(args);
	}
	free(stack);
}