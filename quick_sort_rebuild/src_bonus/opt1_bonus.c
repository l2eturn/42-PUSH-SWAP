/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt1_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimvutt <slimvut@fpgij;dgj;ds.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 20:39:14 by slimvutt          #+#    #+#             */
/*   Updated: 2025/10/12 20:39:14 by slimvutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void swap(t_list **stack)
{
	t_list	*tmp;

	if (!(*stack) || !((*stack)->next))
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

void	sa(t_list **a)
{
	swap(a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_list **b)
{
	swap(b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_list **a, t_list **b)
{
	swap(a);
	swap(b);
	ft_putstr_fd("ss\n", 1);
}