/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimvutt <slimvut@fpgij;dgj;ds.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 03:50:25 by slimvutt          #+#    #+#             */
/*   Updated: 2025/10/05 03:50:25 by slimvutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	reverse_rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*bot;

	if (!(*stack) || !((*stack)->next))
		return ;
	tmp = *stack;//10 20 30
	bot = ft_lstlast(*stack);//30
	while ((*stack)->next->next)
		*stack = (*stack)->next;//at 20	
	bot->next = tmp;//30 10 20 30
	(*stack)->next = NULL; //30 10 20 
	*stack = bot; //stack -> 20 -> NULL == stack -> 30 10 20 NULL;
}

void	rra(t_list **a)
{
	reverse_rotate(a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_list **b)
{
	reverse_rotate(b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_list **a, t_list **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_putstr_fd("rrr\n", 1);
}
