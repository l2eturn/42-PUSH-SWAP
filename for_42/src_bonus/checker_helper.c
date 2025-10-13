/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimvutt <slimvut@fpgij;dgj;ds.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 09:51:26 by slimvutt          #+#    #+#             */
/*   Updated: 2025/10/13 09:51:26 by slimvutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap_group(char *opt, t_stack *stack)
{
	if ((ft_strcmp(opt, "sa\n")) == 0)
		sa(&stack->stack_a);
	else if ((ft_strcmp(opt, "sb\n")) == 0)
		sb(&stack->stack_b);
	else if ((ft_strcmp(opt, "ss\n")) == 0)
		ss(&stack->stack_a, &stack->stack_b);
}

void	push_group(char *opt, t_stack *stack)
{
	if ((ft_strcmp(opt, "pa\n")) == 0)
		pa(&stack->stack_a, &stack->stack_b);
	else if (ft_strcmp(opt, "pb\n") == 0)
		pb(&stack->stack_a, &stack->stack_b);
}

void	rotate_group(char *opt, t_stack *stack)
{
	if ((ft_strcmp(opt, "rr\n")) == 0)
		rr(&stack->stack_a, &stack->stack_b);
	else if (ft_strcmp(opt, "ra\n") == 0)
		ra(&stack->stack_a);
	else if (ft_strcmp(opt, "rb\n") == 0)
		rb(&stack->stack_b);
}

void	reverse_rotate_group(char *opt, t_stack *stack)
{
	if (ft_strcmp(opt, "rrr\n") == 0)
		rrr(&stack->stack_a, &stack->stack_b);
	else if (ft_strcmp(opt, "rra\n") == 0)
		rra(&stack->stack_a);
	else if (ft_strcmp(opt, "rrb\n") == 0)
		rrb(&stack->stack_b);
}
