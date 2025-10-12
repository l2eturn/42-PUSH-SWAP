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

	curr_size = ft_lstsize(stack);
	if (curr_size != size)
		return (0);
	if (!(is_already_sort(stack)))
		return (0);
	return (1);
}



