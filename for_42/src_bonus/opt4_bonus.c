/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt4_bonus .c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimvutt <slimvut@fpgij;dgj;ds.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 20:39:21 by slimvutt          #+#    #+#             */
/*   Updated: 2025/10/12 20:39:21 by slimvutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	reverse_rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*bot;

	if (!(*stack) || !((*stack)->next))
		return ;
	tmp = *stack;
	bot = ft_lstlast(*stack);
	while ((*stack)->next->next)
		*stack = (*stack)->next;
	bot->next = tmp;
	(*stack)->next = NULL;
	*stack = bot;
}

void	rra(t_list **a)
{
	reverse_rotate(a);
}

void	rrb(t_list **b)
{
	reverse_rotate(b);
}

void	rrr(t_list **a, t_list **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
