/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimvutt <slimvut@fpgij;dgj;ds.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 03:49:05 by slimvutt          #+#    #+#             */
/*   Updated: 2025/10/05 03:49:05 by slimvutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sa(t_stack *a)
{
	t_node	*first;
	t_node	*second;
	t_node	*tmp;

	if (a->size < 2)
		return ;
	first = a->top;
	second = a->top->next;
	tmp = second -> next;
	first -> next = tmp;
	if (second -> next)
		tmp->prev = first;
	else
		a -> bottom = first;
	second -> next = first;
	second -> prev = NULL;
	first -> prev = second;
	a -> top = second;
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack *b)
{
	t_node	*first;
	t_node	*second;
	t_node	*tmp;

	if (b->size < 2)
		return ;
	first = b->top;
	second = b->top->next;
	tmp = second -> next;
	first -> next = tmp;
	if (second -> next)
		tmp->prev = first;
	else
		b -> bottom = first;
	second -> next = first;
	second -> prev = NULL;
	first -> prev = second;
	b -> top = second;
	ft_putstr_fd("sb", 1);
}
static void	ss_sa(t_stack *a)
{
	t_node	*first;
	t_node	*second;
	t_node	*tmp;

	if (a->size < 2)
		return ;
	first = a->top;
	second = a->top->next;
	tmp = second -> next;
	first -> next = tmp;
	if (second -> next)
		tmp->prev = first;
	else
		a -> bottom = first;
	second -> next = first;
	second -> prev = NULL;
	first -> prev = second;
	a -> top = second;
}

static void	ss_sb(t_stack *b)
{
	t_node	*first;
	t_node	*second;
	t_node	*tmp;

	if (b->size < 2)
		return ;
	first = b->top;
	second = b->top->next;
	tmp = second -> next;
	first -> next = tmp;
	if (second -> next)
		tmp->prev = first;
	else
		b -> bottom = first;
	second -> next = first;
	second -> prev = NULL;
	first -> prev = second;
	b -> top = second;
}
void	ss(t_stack *a, t_stack *b)
{
	ss_sa(a);
	ss_sb(b);
	ft_putstr_fd("ss", 1);
}

//sa/sb/ss