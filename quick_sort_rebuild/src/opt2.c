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

void	pa(t_list **a, t_list **b)
{
	t_list *below;

	if (!(*b))
		return ;
	below = (*b)->next;
	*a = *b;
	*b = below;
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_list **a, t_list **b)
{
	t_list *below;

	if (!(*a))
		return ;
	below = (*a)->next;
	*b = *a;
	*a = below;
	ft_putstr_fd("pb\n", 1);
}
