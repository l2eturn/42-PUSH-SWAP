/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimvutt <slimvut@fpgij;dgj;ds.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 03:50:25 by slimvutt          #+#    #+#             */
/*   Updated: 2025/10/05 03:50:25 by slimvutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_list **b)
{
	reverse_rotate(b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_list **a, t_list **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_putstr_fd("rrr\n", 1);
}
