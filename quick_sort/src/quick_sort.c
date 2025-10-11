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
	mid_vals[0] = find_pivot(arr->values, arr->size);
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

void	sa_rra(t_stack *a)
{
	sa(a);
	rra(a);
}

void	sa_ra(t_stack *a)
{
	sa(a);
	ra(a);
}

void	sort_small_a(t_chunk *arr, t_stack *a)
{
	int	*val;

	val = arr -> values;
	if (arr -> size == 2)
	{
		if (val[0] > val[1])
			sa(a);
	}
	else if (arr -> size == 3)
	{
		if (val[0] > val[1] && val[1] < val[2] && val[0] < val[2])
			sa(a);
		else if (val[0] > val[1] && val[1] > val[2])
			sa_rra(a);
		else if (val[0] > val[1] && val[1] < val[2] && val[0] > val[2])
			ra(a);
		else if (val[0] < val[1] && val[1] > val[2] && val[0] < val[2])
			sa_ra(a);
		else if (val[0] < val[1] && val[1] > val[2] && val[0] > val[2])
			rra(a);
	}
}

void	sort_small_b(t_chunk *arr, t_stack *b)
{

}
void	sort_small_botb(t_chunk *arr, t_stack *b)
{

}

void	sort_small(t_chunk *arr, t_stack *a, t_stack *b)
{
	if (arr -> location == TOP_A)
		sort_small_a(arr, a);
	else if (arr -> location == TOP_B)
		sort_small_b(arr, b);
	else if (arr -> location == BOTTOM_B)
		sort_small_botb(arr, b);
}

void	recursive_quick_sort(t_chunk *arr, t_stack *a, t_stack *b)
{
	if (arr -> size <= 3)
	{
		sort_small(arr -> values, a ,b);
		return ;
	}
	split_chunk(arr);
	recursive_quick_sort(arr -> left, a, b);
	recursive_quick_sort(arr -> mid, a, b);
	recursive_quick_sort(arr -> right, a, b);
}
