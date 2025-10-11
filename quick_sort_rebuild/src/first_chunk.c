/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_chunk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimvutt <slimvut@fpgij;dgj;ds.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 19:51:49 by slimvutt          #+#    #+#             */
/*   Updated: 2025/10/11 19:51:49 by slimvutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	is_rev_sort(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp -> next)
	{
		if (tmp -> content < tmp -> next -> content)
			return (0);
		tmp = tmp -> next;
	}
	return (1);
}

int	is_already_sort(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp && tmp->next)
	{
		if (tmp -> content > tmp -> next -> content)
			return (0);
		tmp = tmp -> next;
	}
	return (1);
}
//---------------------------------------------------------------
void	sort_chunk_of_five(t_stack *lst)
{

}
//end---------------------------------------------------------------

//---------------------------------------------------------------
void	sort_chunk_of_three(t_stack *lst)
{
	t_list	*last;

	if (is_already_sort(lst -> stack_a))
		return ;
	last = ft_lstlast(lst->stack_a);
	if (is_rev_sort(lst -> stack_a))
	{
		sa(&(lst->stack_a));
		rra(&(lst->stack_a));
	}
	else if (lst->stack_a->content < last->content
		&& lst->stack_a->next->content < last->content)
		sa(&(lst->stack_a));
	else if (lst->stack_a->content > last->content
		&& lst->stack_a->next->content < last->content)
		ra(&(lst->stack_a));
	else if (lst->stack_a->content < last->content
		&& lst->stack_a->next->content > last->content)
	{
		sa(&(lst->stack_a));
		ra(&(lst->stack_a));
	}
	else if (lst->stack_a->content > last->content
		&& lst->stack_a->next->content > last->content)
		rra(&(lst->stack_a));
}
//| Case | Pattern (top → bottom) | Action   | ผลลัพธ์ |
//| :--: | :--------------------- | :------- | :------ |
//|   1  | 3 2 1                  | sa + rra | 1 2 3   |
//|   2  | 2 1 3                  | sa       | 1 2 3   |
//|   3  | 3 1 2                  | ra       | 1 2 3   |
//|   4  | 1 3 2                  | sa + ra  | 1 2 3   |
//|   5  | 2 3 1                  | rra      | 1 2 3   |
//end---------------------------------------------------------------

void	do_sort(t_stack *node)
{
	int	len;

	len = ft_lstsize(node);
	if (is_already_sort((node->stack_a)))
		return ;
	if (len == 2)
	{
		if (node->stack_a->content > node->stack_a->next->content)
			sa(&(node->stack_a));
	}
	else if (len == 3)
		sort_chunk_of_three(node);
	else if (len == 5)
		sort_chunk_of_five(node);
	//else

}
