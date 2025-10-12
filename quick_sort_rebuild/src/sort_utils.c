/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimvutt <slimvut@fpgij;dgj;ds.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 09:44:09 by slimvutt          #+#    #+#             */
/*   Updated: 2025/10/12 09:44:09 by slimvutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_list	*min_in_lst(t_list *stack)
{
	t_list *min;
	t_list *tmp;

	min = stack;
	tmp = stack;
	while (tmp)
	{
		if (tmp->cnt < min->cnt)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

t_list	*max_in_lst(t_list *stack)
{
	t_list *max;
	t_list *tmp;

	max = stack;
	tmp = stack;
	while (tmp)
	{
		if (tmp->cnt > max->cnt)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

int is_already_sort_a(t_list *stack,int size)
{
	int	curr_size;

	curr_size = ft_lstsize(stack);//so if its not the same which mean threre is no way itll be sort
	if (curr_size != size)
		return (0);
	if (is_already_sort(stack) == 0)
		return (0);
	return (1);
}

void find_next(t_list **a, t_list **b, t_push *p)
{
    while (1)
    {
        if (ft_lstsize(*b) > 0 && (*b)->index == p->next)
            pa(a, b);
        else if ((*a)->index == p->next)
        {
            (*a)->flag = -1;
            ra(a);
            p->next++;
        }
        else if (ft_lstsize(*b) > 2 && ft_lstlast(*b)->index == p->next)
            rrb(b);
        else if ((*a)->next && (*a)->next->index == p->next)
            sa(a);
        else if (ft_lstsize(*a) > 1 && ft_lstsize(*b) > 1
            && (*a)->next->index == p->next && (*b)->next->index == p->next + 1)
            ss(a, b);
        else
            break;
    }
}

//void	find_next(t_list **stack_a, t_list **stack_b, t_push *push)
//{
//	if (ft_lstsize(*stack_b) > 0 && ((*stack_b)->index == push->next))
//		pa(stack_a, stack_b);
//	else if ((*stack_a)->index == push->next)
//	{
//		(*stack_a)->flag = -1;
//		ra(stack_a);
//		push->next++;
//	}
//	else if ((ft_lstsize(*stack_b)) > 2
//		&& ft_lstlast(*stack_b)->index == push->next)
//		rrb(stack_b);
//	else if ((*stack_a)->next->index == push->next)
//		sa(stack_a);
//	else if ((ft_lstsize(*stack_a)) > 1 && ((*stack_a)->next->index == push->next)
//		&& ((*stack_b)->next->index == push->next + 1))
//		ss(stack_a, stack_b);
//	else
//		return ;
//	find_next(stack_a, stack_b, push);
//	return ;
//}
//#include <stdio.h>

//void	find_next(t_list **a, t_list **b, t_push *p)
//{
//	int	moved;

//	while (1)
//	{
//		moved = 0;
//		printf("\n=== DEBUG LOOP START ===\n");
//		printf("next = %d\n", p->next);
//		if (*a)
//			printf("A top = %d\n", (*a)->index);
//		if (*a && (*a)->next)
//			printf("A next = %d\n", (*a)->next->index);
//		if (*b)
//			printf("B top = %d\n", (*b)->index);
//		if (*b && (*b)->next)
//			printf("B next = %d\n", (*b)->next->index);
//		if (*b)
//			printf("B last = %d\n", ft_lstlast(*b)->index);
//		printf("========================\n");

//		if (ft_lstsize(*b) > 0 && (*b)->index == p->next)
//		{
//			printf("Action: pa (b->a)\n");
//			pa(a, b);
//			moved = 1;
//		}
//		else if ((*a)->index == p->next)
//		{
//			printf("Action: ra + mark flag\n");
//			(*a)->flag = -1;
//			ra(a);
//			p->next++;
//			moved = 1;
//		}
//		else if (ft_lstsize(*b) > 2 && ft_lstlast(*b)->index == p->next)
//		{
//			printf("Action: rrb\n");
//			rrb(b);
//			moved = 1;
//		}
//		else if ((*a)->next && (*a)->next->index == p->next)
//		{
//			printf("Action: sa\n");
//			sa(a);
//			moved = 1;
//		}
//		else if (ft_lstsize(*a) > 1 && ft_lstsize(*b) > 1
//			&& (*a)->next->index == p->next && (*b)->next->index == p->next + 1)
//		{
//			printf("Action: ss\n");
//			ss(a, b);
//			moved = 1;
//		}

//		if (!moved)
//		{
//			printf("No move this round → break loop\n");
//			break;
//		}
//	}
//}