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
#include "greedy.h"

t_node	*new_t(t_stack *stack, int nbr)
{
	t_node	*new; 
	new = malloc(sizeof(t_node));
	new -> value = (int)(nbr);
	new -> next = NULL;
	new -> prev = stack->bottom;
	return (new);
}

t_stack	*init_a(void)
{
	t_stack	*st;
	st = malloc(sizeof(t_stack));
	if (!st)
		return (NULL);
	st -> top = NULL;
	st -> bottom = NULL;
	st -> size = 0;
	return (st);
}

t_stack	*init_stack_b(void)
{
	t_stack	*stack;

	stack = init_a();
	if (!stack)
		return (NULL);
	return (stack);
}

t_stack	*init_stack_a(char **args, int i)
{
	t_stack	*stack;
	t_node	*new;
	long	nbr;

	stack = init_a();
	if (!stack)
		return (NULL);
	while (args[i])
	{
		nbr = ft_atoi(args[i]);
		if (nbr > INT_MAX || nbr < INT_MIN || ft_check(stack, args[i], (int)nbr) == 0)
		{
			free_init_a_if_error(stack);
			return (NULL);
		}
		new = new_t(stack, (int)nbr);
		if (stack -> bottom)
			stack->bottom->next = new;
		else
			stack->top = new;
		stack -> bottom = new;
		stack -> size++;
		i ++;
	}
	return (stack);
}

//int	main(int ac, char **av)
//{
//	t_stack	*stack_a;
//	t_stack	*stack_b;
//	char	**args;
//	int		i;

//	i = 0;
//	args = av;
//	if (ac == 1)
//		return (0);
//	if (ac == 2)
//		args = ft_split(av[1], ' ');
//	else
//		i = 1;
//	stack_a = init_stack_a(args, i);
//	stack_b = init_stack_b();
////---------------------------------------------------------------	
//	print_stack(stack_a, 'A');
//	print_stack(stack_b, 'B');
//	free_stack(stack_a);
//	free_stack(stack_b);
////---------------------------------------------------------------	
//}

	//sa(stack_a);
	//pb(stack_a,stack_b);
	//pb(stack_a,stack_b);
	//print_stack(stack_a, 'A');
	//print_stack(stack_b, 'B');
int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**args;
	int		i;
	int		*lis;
	int		lis_size;

	i = 0;
	args = av;
	if (ac == 1)
		return (0);
	if (ac == 2)
		args = ft_split(av[1], ' ');
	else
		i = 1;
	stack_a = init_stack_a(args, i);
	stack_b = init_stack_b();
	index_stack(stack_a);
	lis = find_lis(stack_a, &lis_size);
	push_all_except_lis_chunked(stack_a, stack_b);
	push_back_greedy(stack_a, stack_b);
	final_rotation(stack_a);
	free(lis);
//---------------------------------------------------------------	
	//print_stack(stack_a, 'A');
	//print_stack(stack_b, 'B');
	free_stack(stack_a);
	free_stack(stack_b);
//---------------------------------------------------------------	
}