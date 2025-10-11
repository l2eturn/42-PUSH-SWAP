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

void	rra(t_stack *a)
{
	t_node	*last;

	if (a -> size < 2)
		return ;
	last = a->bottom;
	a->bottom = last->prev;
	a->bottom->next = NULL;
	last->prev = NULL;
	last->next = a->top;
	a->top->prev = last;
	a->top = last;
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack *b)
{
	t_node	*last;

	if (b -> size < 2)
		return ;
	last = b->bottom;
	b->bottom = last->prev;
	b->bottom->next = NULL;
	last->prev = NULL;
	last->next = b->top;
	b->top->prev = last;
	b->top = last;
	ft_putstr_fd("rrb\n", 1);
}

static void	rrr_rra(t_stack *a)
{
	t_node	*last;

	if (a -> size < 2)
		return ;
	last = a->bottom;
	a->bottom = last->prev;
	a->bottom->next = NULL;
	last->prev = NULL;
	last->next = a->top;
	a->top->prev = last;
	a->top = last;
}

static void	rrr_rrb(t_stack *b)
{
	t_node	*last;

	if (b -> size < 2)
		return ;
	last = b->bottom;
	b->bottom = last->prev;
	b->bottom->next = NULL;
	last->prev = NULL;
	last->next = b->top;
	b->top->prev = last;
	b->top = last;
}

void	rrr(t_stack *a, t_stack *b)
{
	rrr_rra(a);
	rrr_rrb(b);
	ft_putstr_fd("rrr\n", 1);
}
