/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimvutt <slimvut@fpgij;dgj;ds.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 09:09:49 by slimvutt          #+#    #+#             */
/*   Updated: 2025/10/12 09:09:49 by slimvutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	devide_first_chunk(t_list **stack_a, t_list **stack_b,t_push *push, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if ((*stack_a)->index <= push->mid)
			pb(stack_a, stack_b);
		else
		{
			if ((ft_lstsize(*stack_b) > 1) && ((*stack_b)->index < (push->mid/2)))
				rr(stack_a, stack_b);
			else
				ra(stack_a);
		}
		i ++;
	}
	push->max = push->mid;
	push->mid = ((push->max - push->next) / 2) + (push->next);
	push->flag++;
}










void	quick_sort(t_list **stack_a, t_list **stack_b, int size)
{
	t_push	push;
	
	push.flag = 0;
	push.next = min_in_lst(*stack_a)->index;
	push.max = max_in_lst(*stack_b)->index;
	push.max = (push.max / 2) + (push.next);
	devide_first_chunk(stack_a, stack_b, &push, size);

}