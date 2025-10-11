/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimvutt <slimvut@fpgij;dgj;ds.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 09:21:13 by slimvutt          #+#    #+#             */
/*   Updated: 2025/10/04 09:21:13 by slimvutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
#include <stdio.h>
static void print_lst(t_list *lst)
{
	while (lst)
	{
		printf("val is %d and index is %d\n", lst->cnt, lst->index);
		lst = lst->next;
	}
	printf("\n");
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
	stack->asize = ft_lstsize(stack->stack_a);
	stack->bsize = ft_lstsize(stack->stack_b);
	assign_index(stack->stack_a);
	do_sort(stack);
	print_lst(stack->stack_a);
	//free_all(stack, args, ac);
	//---------------------------------------------------------------	
}

//int x = ft_lstsize(stack->stack_a);
//printf("%d\n", x);
