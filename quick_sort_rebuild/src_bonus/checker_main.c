/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimvutt <slimvut@fpgij;dgj;ds.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 20:49:38 by slimvutt          #+#    #+#             */
/*   Updated: 2025/10/12 20:49:38 by slimvutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	print_opt(char *opt, t_stack *stack)
{
	if (ft_strcmp(opt, "sa\n") == 0)
		sa(&stack->stack_a);
	else if (ft_strcmp(opt, "sb\n") == 0)
		sb(&stack->stack_b);
	else if (ft_strcmp(opt, "ss\n") == 0)
		ss(&stack->stack_a, &stack->stack_b);
	else if (ft_strcmp(opt, "pa\n") == 0)
		pa(&stack->stack_a, &stack->stack_b);
	else if (ft_strcmp(opt, "pb\n") == 0)
		pb(&stack->stack_a, &stack->stack_b);
	else if (ft_strcmp(opt, "ra\n") == 0)
		ra(&stack->stack_a);
	else if (ft_strcmp(opt, "rb\n") == 0)
		rb(&stack->stack_b);
	else if (ft_strcmp(opt, "rra\n") == 0)
		rra(&stack->stack_a);
	else if (ft_strcmp(opt, "rrb\n") == 0)
		rrb(&stack->stack_b);
	else
	{
		free(opt);
		return (0);
	}
	free(opt);
	return (1);
}

void	get_operate(t_stack *stack)
{
	char	*opt;

	opt = get_next_line(0);
	while (opt)
	{
		if (!print_opt(opt, stack))
		{
			ft_putstr_fd("Error\n", 1);
			exit(-1);
		}
		opt = get_next_line(0);
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack;
	char	**args;
	
	args = av;
	if (ac == 1)
		return (0);
	stack = malloc(sizeof(t_stack));
	if (ac == 2)
		args = ft_split(av[1], ' ');
	else
		args = av;
	stack->stack_a = init_stack(args, ac);
	if (stack->stack_a == NULL)
		return (-1);
	stack->stack_b = NULL;

	if (is_already_sort(stack->stack_a) && !stack->stack_b)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_stack(stack, args, ac);
}
