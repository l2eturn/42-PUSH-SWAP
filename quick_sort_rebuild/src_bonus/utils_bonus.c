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

int	is_already_sort(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp && tmp->next)
	{
		if (tmp -> cnt > tmp -> next -> cnt)
			return (0);
		tmp = tmp -> next;
	}
	return (1);
}
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

t_list	*init_stack(char **av, int ac)
{
	t_list	*tmp;
	t_list	*res;
	int		i;
	long	nbr;

	if (ac == 2)
		i = 0;
	else
		i = 1;
	res = NULL;
	while (av[i])
	{
		nbr = ft_atoi(av[i]);
		if ((nbr > INT_MAX) || (nbr < INT_MIN) || (check(res, nbr, av[i]) == 0))
		{
			ft_putstr_fd("Error\n", 2);
			return (NULL);
		}
		tmp = ft_lstnew(nbr);
		ft_lstadd_back(&res, tmp);
		tmp -> index = -1;
		i ++;
	}
	return (res);
}

void free_list(t_list *lst)
{
    t_list *tmp;
    while (lst)
    {
        tmp = lst->next;
        free(lst);
        lst = tmp;
    }
}

void free_stack(t_stack *stack, char **args, int ac)
{
    if (stack->stack_a)
        free_list(stack->stack_a);
    if (stack->stack_b)
        free_list(stack->stack_b);
    free(stack);

    if (ac == 2 && args)
    {
        int i = 0;
        while (args[i])
            free(args[i++]);
        free(args);
    }
}
