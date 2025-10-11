/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimvutt <slimvut@fpgij;dgj;ds.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 15:43:48 by slimvutt          #+#    #+#             */
/*   Updated: 2025/10/11 15:43:48 by slimvutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	is_already_sort(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp && tmp->next)
	{
		if (tmp -> content > tmp -> next -> content)
			return (0);
		tmp = tmp -> next;
	}
	return (1);
}

void	is_sort(t_stack *node)
{
	int	len;

	len = ft_lstsize(node);
	if (is_already_sort(&(node->stack_a)))
		return ;
	if (len == 2)
	{
		if (node->stack_a->content > node->stack_a->next->content)
			sa(&(node->stack_a));
	}
	//else if (len == 3)

	//else if (len == 5)

	//else

}
