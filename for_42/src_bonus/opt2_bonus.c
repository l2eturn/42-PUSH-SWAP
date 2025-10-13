/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt2_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimvutt <slimvut@fpgij;dgj;ds.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 20:39:17 by slimvutt          #+#    #+#             */
/*   Updated: 2025/10/12 20:39:17 by slimvutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	pa(t_list **a, t_list **b)
{
	t_list *below;

	if (!(*b))
		return ;
	below = (*b)->next;
	(*b)->next = *a;
	*a = *b;
	*b = below;
}

void	pb(t_list **a, t_list **b)
{
	t_list *below;

	if (!(*a))
		return ;
	below = (*a)->next;
	(*a)->next = *b;
	*b = *a;
	*a = below;
}
