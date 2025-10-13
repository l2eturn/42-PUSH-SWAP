/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimvutt <slimvut@fpgij;dgj;ds.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 16:11:34 by slimvutt          #+#    #+#             */
/*   Updated: 2025/10/04 16:11:34 by slimvutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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

void	idx_replace(t_list *lst, int min, int i)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (tmp -> index == -1 && tmp ->cnt == min)
			break ;
		tmp = tmp -> next;
	}
	tmp -> index = i;
}

int	ft_min(t_list *lst)
{
	t_list		*tmp;
	long int	min;	

	min = LONG_MAX;
	tmp = lst;
	while (tmp)
	{
		if (tmp -> index == -1 && tmp -> cnt < min)
			min = tmp->cnt;
		tmp = tmp -> next;
	}
	return (min);
}

void	assign_index(t_list *lst)
{
	int	len;
	int	min;
	int	i;

	i = 0;
	len = ft_lstsize(lst);
	while (i < len)
	{
		min = ft_min(lst);
		idx_replace(lst, min, i);
		i ++;
	}
}
