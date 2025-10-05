/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimvutt <slimvut@fpgij;dgj;ds.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 16:11:34 by slimvutt          #+#    #+#             */
/*   Updated: 2025/10/04 16:11:34 by slimvutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_check(t_stack *stack, char *nbr, int value)
{
	int		i;
	t_node	*tmp;

	i = 0;
	if (!nbr || !*nbr)
		return (0);
	while (nbr[i])
	{
		if (!(((nbr[i] == '-' || nbr[i] == '+') && ft_isdigit(nbr[i + 1])
					&& (i == 0 || !ft_isdigit(nbr[i - 1])))
				|| ft_isdigit(nbr[i])))
			return (0);
		i++;
	}
	tmp = stack->top;
	while (tmp)
	{
		if (tmp->value == value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	free_stack(t_stack *stack)
{
	t_node	*tmp;

	while (stack && stack->top)
	{
		tmp = stack->top->next;
		free(stack->top);
		stack->top = tmp;
	}
	free(stack);
}
