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
	if (!(ft_strcmp(opt, "sa\n")))
		sa(&stack->stack_a);
	else if (!(ft_strcmp(opt, "sb\n")))
		sb(&stack->stack_b);
	else if (!(ft_strcmp(opt, "sa\n")))
		ss(&stack->stack_a, &stack->stack_b);
}

void	push_group(char *opt, t_stack *stack)
{
	if (!(ft_strcmp(opt, "pa\n")))
		pa(&stack->stack_a, &stack->stack_b);
	if (!ft_strcmp(opt, "pb\n"))
		pb(&stack->stack_a, &stack->stack_b);
}

void	rotate_group(char *opt, t_stack *stack)
{
	if (!(ft_strcmp(opt, "rr\n")))
		rr(&stack->stack_a, &stack->stack_b);
	else if (!ft_strcmp(opt, "ra\n"))
		ra(&stack->stack_a);
	else if (!ft_strcmp(opt, "rb\n") == 0)
		rb(&stack->stack_b);
}

void	reverse_rotate_group(char *opt, t_stack *stack)
{
	if (!ft_strcmp(opt, "rrr\n"))
		rrr(&stack->stack_a, &stack->stack_b);
	else if (!ft_strcmp(opt, "rra\n"))
		rra(&stack->stack_a);
	else if (!ft_strcmp(opt, "rrb\n"))
		rrb(&stack->stack_b);
}
