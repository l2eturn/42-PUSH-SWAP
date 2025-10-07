/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimvutt <slimvutt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 18:54:35 by slimvutt          #+#    #+#             */
/*   Updated: 2025/10/07 19:32:49 by slimvutt         ###   ########.fr       */
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
