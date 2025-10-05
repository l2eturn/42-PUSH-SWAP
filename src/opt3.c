/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimvutt <slimvut@fpgij;dgj;ds.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 03:50:08 by slimvutt          #+#    #+#             */
/*   Updated: 2025/10/05 03:50:08 by slimvutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ra(t_stack *a)
{
	t_node *first;

	if (a->size < 2)
		return ;
	first = a -> top;
	a->top = first->next;
	a->top->prev = NULL;
	a->bottom->next = first;
	first->prev = a->bottom;
	first->next = NULL;
	a->bottom = first;
	ft_putstr_fd("ra\n", 1);
}
void	rb(t_stack *b)
{
	t_node *first;

	if (b->size < 2)
		return ;
	first = b -> top;
	b->top = first->next;
	b->top->prev = NULL;
	b->bottom->next = first;
	first->prev = b->bottom;
	first->next = NULL;
	b->bottom = first;
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
	ft_putstr_fd("rr\n", 1);
}
