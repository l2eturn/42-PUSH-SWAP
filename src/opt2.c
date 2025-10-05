/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimvutt <slimvut@fpgij;dgj;ds.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 03:49:46 by slimvutt          #+#    #+#             */
/*   Updated: 2025/10/05 03:49:46 by slimvutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

//pa/pb
void	pa(t_stack *a, t_stack *b)
{
	t_node	*first_node_b;

	if (b -> size == 0)
		return ;
	first_node_b = b->top;
	b->top = first_node_b->next;
	if (b->top)
		b->top->prev = NULL;
	else
		b->bottom = NULL;
	b->size--;

	first_node_b -> next = a->top;
	if (a->top)
		a->top->prev = first_node_b;
	else
		a->bottom = first_node_b;
	a->top = first_node_b;
	a->size++;
	ft_putstr_fd("pa\n", 1);	
}

void	pb(t_stack *a, t_stack *b)
{
	t_node	*first_node_a;

	if (a -> size == 0)
		return ;
	first_node_a = a->top;
	a->top = first_node_a->next;
	if (a->top)
		a->top->prev = NULL;
	else
		a->bottom = NULL;
	a->size--;

	first_node_a -> next = b->top;
	if (b->top)
		b->top->prev = first_node_a;
	else
		b->bottom = first_node_a;
	b->top = first_node_a;
	b->size++;
	ft_putstr_fd("pb\n", 1);	
}
