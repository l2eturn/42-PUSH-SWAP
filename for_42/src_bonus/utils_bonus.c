/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimvutt <slimvut@fpgij;dgj;ds.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 21:32:44 by slimvutt          #+#    #+#             */
/*   Updated: 2025/10/12 21:32:44 by slimvutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check(t_list *lst, int n, char *nbr)
{
	t_list	*tmp;
	int		i;

	tmp = lst;
	i = 0;
	while (nbr[i])
	{
		if (!(((nbr[i] == '-' || nbr[i] == '+') && ft_isdigit(nbr[i + 1])
					&& (i == 0 || !ft_isdigit(nbr[i - 1])))
				|| ft_isdigit(nbr[i])))
			return (0);
		i++;
	}
	while (tmp)
	{
		if (tmp->cnt == n)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static t_list	*create_node(t_list *res, char *str)
{
	long	nbr;
	t_list	*tmp;

	nbr = ft_atoi(str);
	if (nbr > INT_MAX || nbr < INT_MIN || !check(res, nbr, str))
		return (NULL);
	tmp = ft_lstnew(nbr);
	return (tmp);
}

t_list	*init_stack(char **ag, int ac)
{
	t_list	*res;
	t_list	*tmp;
	int		i;

	res = NULL;
	if (ac == 2)
		i = 0;
	else
		i = 1;
	while (ag[i])
	{
		tmp = create_node(res, ag[i]);
		if (!tmp)
		{
			free_list(res);
			ft_putstr_fd("Error\n", 2);
			return (NULL);
		}
		ft_lstadd_back(&res, tmp);
		tmp->index = -1;
		i++;
	}
	return (res);
}

void	free_list(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}

void	free_stack(t_stack *stack, char **args, int ac)
{
	int	i;

	if (stack->stack_a)
		free_list(stack->stack_a);
	if (stack->stack_b)
		free_list(stack->stack_b);
	free(stack);
	if (ac == 2 && args)
	{
		i = 0;
		while (args[i])
			free(args[i++]);
		free(args);
	}
}
