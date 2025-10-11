/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimvutt <slimvut@fpgij;dgj;ds.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 18:54:35 by slimvutt          #+#    #+#             */
/*   Updated: 2025/10/11 07:33:36 by slimvutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	stack_size(t_stack *stack)
{
	int	size;
	t_node *p;

	size = 0;
	p = stack->top;
	while (p)
	{
		size ++;
		p = p -> next;
	}
	return (size);
}

//int	*fill_arr(t_stack *stack, int len)
//{
//	t_node	*pt;
//	int 	*arr;
//	int		i;

//	i = 0;
//	pt = stack -> top;
//	arr = malloc(sizeof(int) * len);
//	while (i < len)
//	{
//		arr[i] = pt -> value;
//		pt = pt -> next;
//		i ++;
//	}
//	return (arr);
//}

void	bubble_sort_arr(int *arr, int len)
{
	int		i;
	int		j;
	int		tmp;

	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j ++;
		}
		i ++;
	}
}

int	find_pivot(int *arr, int size)
{
	int		pivot;

	bubble_sort_arr(arr, size);
	pivot = arr[size/2];
	free(arr);
	return (pivot);
}
