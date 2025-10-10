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

void free_chunk(t_chunk *chunk)
{
	if (!chunk)
		return ;
	if (chunk->left)
		free_chunk(chunk->left);
	if (chunk->mid)
		free_chunk(chunk->mid);
	if (chunk->right)
		free_chunk(chunk->right);
	free(chunk->values);
	free(chunk);
}

t_chunk	*create_chunk(int *values, int size, t_location loc)
{
	t_chunk	*chunk;
	int		i;
	int		*val;
	
	chunk = malloc(sizeof(t_chunk));
	if (!chunk)
	return (NULL);
	chunk -> values = malloc(sizeof(int) * size); 
	if (!(chunk -> values))
	{
		free(chunk);
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		chunk -> values[i] = values[i];
		i ++;
	}
	chunk->size = size;
	chunk->location = loc;
	chunk->left = NULL;
	chunk->mid = NULL;
	chunk->right = NULL;
	return	(chunk);
}

int	helper_for_helper(t_chunk *lst1, t_chunk *lst2, t_chunk *lst3)
{
	if (!lst1 || !lst2 || !lst3)
	{
		if (lst1)
		{
			free(lst1->values);
			free(lst1);
		}
		if (lst2)
		{
			free(lst2->values);
			free(lst2);
		}
		if (lst3)
		{
			free(lst3->values);
			free(lst3);
		}
		return (1);
	}
	return (0);
}

void	help_for_free(int *lft_vals, int *rgt_vals, int *mid_vals)
{
	free(lft_vals);
	free(mid_vals);
	free(rgt_vals);
}

void	helper_for_fill(t_chunk *arr,int *lft_vals, int *rgt_vals, int *mid_vals)
{
	int	lft;
	int	rgt;
	int	i;

	i = 0;
	lft = 0;
	rgt = 0;
	while (i < arr -> size)
	{
		if (arr -> values[i] < mid_vals[0])
			lft ++;
		else if (arr -> values[i] > mid_vals[0])
			rgt ++;
		i ++;
	}
	arr->left = create_chunk(lft_vals, lft, TOP_A);
	arr->right = create_chunk(rgt_vals, rgt, BOTTOM_B);
	arr->mid = create_chunk(mid_vals, 1, TOP_B);
	if (helper_for_helper(arr->left, arr->mid, arr->right))
	{
		help_for_free(lft_vals, rgt_vals, mid_vals);
		return ;
	}
	help_for_free(lft_vals, rgt_vals, mid_vals);
}

int	free_vals(int *lft_vals,int *rgt_vals,int *mid_vals)
{
	if ((lft_vals == NULL) || (rgt_vals == NULL) || (mid_vals == NULL))
	{
		free(lft_vals);
		free(rgt_vals);
		free(mid_vals);
		return (1);
	}
	return (0);
}

void	split_chunk(t_chunk *arr)
{
	int		i;
	int		lft;
	int		rgt;
	int		*lft_vals;
	int		*rgt_vals;
	int		*mid_vals;

	i = 0;
	lft = 0;
	rgt = 0;
	lft_vals = malloc(sizeof(int) * arr -> size);
	rgt_vals = malloc(sizeof(int) * arr -> size);
	mid_vals = malloc(sizeof(int));
	if ((free_vals(lft_vals, rgt_vals, mid_vals)))
		return ;
	mid_vals[0] = get_pivot(arr->values, arr->size);
	while (i < arr -> size)
	{
		if (arr -> values[i] < mid_vals[0])
			lft_vals[lft++] = arr -> values[i];
		else if (arr -> values[i] > mid_vals[0])
			rgt_vals[rgt++] = arr -> values[i];
		i ++;
	}
	helper_for_fill(arr, lft_vals, rgt_vals, mid_vals);
}

void	recursive_quick_sort(t_chunk *arr)
{
	if (arr -> size <= 3)
	{
		//opt_small(arr);
		return ;
	}
	split_chunk(arr);
	recursive_quick_sort(arr -> left);
	recursive_quick_sort(arr -> mid);
	recursive_quick_sort(arr -> right);
}
