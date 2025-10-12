/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt3_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimvutt <slimvut@fpgij;dgj;ds.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 20:39:19 by slimvutt          #+#    #+#             */
/*   Updated: 2025/10/12 20:39:19 by slimvutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	rotate(t_list **stack)
{
	t_list	*top;

	top = *stack;
	if (!(*stack) || !((*stack)->next))
		return ;
	*stack = top->next;
	top -> next = NULL;
	ft_lstlast(*stack)->next = top;
}

void	ra(t_list **a)
{
	rotate(a);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_list **b)
{
	rotate(b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
	ft_putstr_fd("rr\n", 1);
}