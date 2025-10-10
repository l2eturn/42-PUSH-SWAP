/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimvutt <slimvut@fpgij;dgj;ds.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 04:34:06 by slimvutt          #+#    #+#             */
/*   Updated: 2025/10/07 04:34:06 by slimvutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

//recursive_chunk_sort(chunk)
//│
//├── base_case? (size <= 3)
//│     └── ใช้ simple_sort() แล้ว return
//│
//├── split_chunk(chunk, &splits)
//│     ├── ส่ง max → TOP_A
//│     ├── ส่ง mid → TOP_B
//│     └── ส่ง min → BOTTOM_B
//│
//├── recursive_chunk_sort(&splits.max)
//├── recursive_chunk_sort(&splits.mid)
//└── recursive_chunk_sort(&splits.min)

t_chunk	*create_chunk(int *values, int size, t_location loc)
{
	t_chunk	*chunk;
	int		i;
	int		*val;

	i = 0;
	chunk = malloc(sizeof(t_chunk));
	chunk -> values = malloc(sizeof(int) * size); 
	while (i < size)
	{
		chunk -> values[i] = values[i];
		i ++;
	}
	chunk->size = size;
	chunk->location = loc;
	chunk->left = NULL;
	chunk-> mid = NULL;
	chunk->right = NULL;
	return	(chunk);
}
//chunk = create_chunk(arr -> values, arr -> size, arr -> location);
void	split_chunk(t_chunk *arr)
{
	t_chunk	*chunk;
	int		i;
	int		lft;
	int		rgt;
	int		pivot;
	int		lft_vals[arr -> size];
	int		rgt_vals[arr -> size];
	int		x[1];

	i = 0;
	lft = 0;
	rgt = 0;
	pivot = get_pivot();
	x[0] = pivot;
	while (i++ < arr -> size)
	{
		if (chunk -> values[i] < pivot)
			lft_vals[lft++] = chunk -> values[i];
		else if (chunk -> values[i] > pivot)
			rgt_vals[rgt++] = chunk -> values[i];
	}
	arr->left = create_chunk(lft_vals, lft, TOP_A);
	arr->right = create_chunk(rgt_vals, rgt, BOTTOM_B);
	arr->mid = create_chunk(x, 1, TOP_B);
	return (chunk);
}

void	rescursive_quick_sort(t_chunk *arr)
{
	if (arr -> size <= 3)
	{
		//opt_small(arr);
		return ;
	}
	split_chunk(arr);
	rescursive_quick_sort(arr -> left);
	rescursive_quick_sort(arr -> mid);
	rescursive_quick_sort(arr -> right);
}

