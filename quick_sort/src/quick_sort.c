/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimvutt <slimvut@fpgij;dgj;ds.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 04:34:06 by slimvutt          #+#    #+#             */
/*   Updated: 2025/10/07 04:34:06 by slimvutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

//void	pb_and_ra(t_stack *a, t_stack *b, int len);


void	quick_sort_a(t_stack *a, t_stack *b, int len)
{
	int	pivot;
	int	push;
	int	rotate;
	int	i;

	if (len <= 1)
		return ;
	i = 0;
	push = 0;
	rotate = 0;
	pivot = find_pivot(a, len);
	while (i++ < len)
	{
		if (a -> top -> value < pivot)
		{
			pb(a, b);
			push ++;
		}
		else
		{
			ra(a);
			rotate ++;
		}
	}
	i = 0;
	while (i++ < rotate)
		rra(a);
	quick_sort_a(a, b, len - push);
	i = 0;
	while (i++ < push)
		pa(a, b);
}
