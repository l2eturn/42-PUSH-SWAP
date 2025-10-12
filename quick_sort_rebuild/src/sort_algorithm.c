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

void	quick_sort(t_list **stack_a, t_list **stack_b, int size)
{
	t_push	push;
	
	push.flag = 0;
	push.next = min_in_lst(*stack_a)->index;
	push.max = max_in_lst(*stack_a)->index;
	push.mid = (push.max / 2) + (push.next);
	devide_first_chunk(stack_a, stack_b, &push, size);
	while (!(is_already_sort_a(*stack_a, size)))
	{
		if (ft_lstsize(*stack_b) == 0)
			do_stack_b(stack_a, stack_b, &push);
		else
			do_stack_a(stack_a, stack_b, &push);
	}
}

void	devide_first_chunk(t_list **stack_a, t_list **stack_b,t_push *push, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if ((*stack_a)->index <= push->mid)
			pb(stack_a, stack_b);
		else
		{
			if (ft_lstsize(*stack_b) > 1 && (*stack_b)->index < (push->mid / 2))
				rr(stack_a, stack_b);
			else
				ra(stack_a);
		}
	}
	push->max = push->mid;
	push->mid = (push->max - push->next) / 2 + push->next;
	push->flag++;
}
void	do_stack_a(t_list **stack_a,t_list **stack_b, t_push *push)
{
	int	size_b;
	int	i;

	i = -1;
	size_b = ft_lstsize(*stack_b);
	while (ft_lstsize(*stack_b) && ++i < size_b)
	{
		if ((*stack_b)->index == push->next)
			find_next(stack_a, stack_b, push);
		else if ((*stack_b)->index >= push->mid)
		{
			(*stack_b)->flag = push->flag;
			pa(stack_a, stack_b);
		}
		else if ((*stack_b)->index < push->mid)
			rb(stack_b);
	}
	push->max = push->mid;
	push->mid = (push->max - push->next) / 2 + push->next;
	push->flag++;
}

void	do_stack_b(t_list **stack_a,t_list **stack_b, t_push *push)
{
	int	curr_flag;

	curr_flag = (*stack_a)->flag;
	if ((*stack_a)->flag != 0)
	{
		while ((*stack_a)->flag == curr_flag)
		{
			if ((*stack_a)->index != push->next)
				pb(stack_a, stack_b);
			find_next(stack_a, stack_b, push);
		}
	}
	else if ((*stack_a)->flag == 0)
	{
		while ((*stack_a)->flag != -1)
		{
			if ((*stack_a)->index != push->next)
				pb(stack_a, stack_b);
			find_next(stack_a, stack_b, push);
		}
	}
	if (ft_lstsize(*stack_b))
		push->max = (max_in_lst(*stack_b))->index;
	push->mid = (push->max - push->next) / 2 + push->next;
}
