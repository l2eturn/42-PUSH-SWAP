/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimvutt <slimvut@fpgij;dgj;ds.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 09:44:09 by slimvutt          #+#    #+#             */
/*   Updated: 2025/10/12 09:44:09 by slimvutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_list	*min_in_lst(t_list *stack)
{
	t_list	*min;
	t_list	*tmp;

	min = stack;
	tmp = stack;
	while (tmp)
	{
		if (tmp->cnt < min->cnt)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

t_list	*max_in_lst(t_list *stack)
{
	t_list	*max;
	t_list	*tmp;

	max = stack;
	tmp = stack;
	while (tmp)
	{
		if (tmp->cnt > max->cnt)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

int	is_already_sort_a(t_list *stack, int size)
{
	int	curr_size;

	curr_size = ft_lstsize(stack);
	if (curr_size != size)
		return (0);
	if (is_already_sort(stack) == 0)
		return (0);
	return (1);
}

void	find_next(t_list **a, t_list **b, t_push *p)
{
	while (1)
	{
		if (ft_lstsize(*b) > 0 && (*b)->index == p->next)
			pa(a, b);
		else if ((*a)->index == p->next)
		{
			(*a)->flag = -1;
			ra(a);
			p->next++;
		}
		else if (ft_lstsize(*b) > 2 && ft_lstlast(*b)->index == p->next)
			rrb(b);
		else if ((*a)->next && (*a)->next->index == p->next)
			sa(a);
		else if (ft_lstsize(*a) > 1 && ft_lstsize(*b) > 1
			&& (*a)->next->index == p->next && (*b)->next->index == p->next + 1)
			ss(a, b);
		else
			break ;
	}
}
