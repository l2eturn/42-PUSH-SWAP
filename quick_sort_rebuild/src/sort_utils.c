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
	t_list *min;
	t_list *tmp;

	min = stack;
	tmp = stack;
	while (tmp)
	{
		if (tmp->content < min->content)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

t_list	*max_in_lst(t_list *stack)
{
	t_list *max;
	t_list *tmp;

	max = stack;
	tmp = stack;
	while (tmp)
	{
		if (tmp->content > max->content)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

int is_already_sort_a(t_list *stack,int size)
{
	int	curr_size;

	curr_size = ft_lstsize(stack);//so if its not the same which mean threre is no way itll be sort
	if (curr_size != size)
		return (0);
	if (!(is_already_sort(stack)))
		return (0);
	return (1);
}

void	find_next(t_list **stack_a, t_list **stack_b, t_push *push)
{
	if (ft_lstsize(*stack_b) > 0 && ((*stack_b)->index == push->next))
		pa(stack_a, stack_b);
	else if ((*stack_a)->index == push->next)
	{
		(*stack_a)->flag = -1;
		ra(stack_a);
		push->next++;
	}
	else if ((ft_lstsize(*stack_b)) > 2
		&& ft_lstlast(*stack_b)->index == push->next)
		rrb(stack_b);
	else if ((*stack_a)->next->index == push->next)
		sa(stack_a);
	else if ((ft_lstsize(*stack_a)) > 1 && ((*stack_a)->next->index == push->next)
		&& ((*stack_b)->next->index == push->next + 1))
		ss(stack_a, stack_b);
	else
		return ;
	find_next(stack_a, stack_b, push);
}
