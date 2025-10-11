/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_safe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimvutt <slimvut@fpgij;dgj;ds.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 10:00:00 by slimvutt          #+#    #+#             */
/*   Updated: 2025/10/11 10:00:00 by slimvutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/* ========================= MEMORY HELPERS ========================= */
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
	if (chunk->values)
		free(chunk->values);
	free(chunk);
}

static void free_tmp_arrays(int *lft, int *mid, int *rgt)
{
	if (lft) free(lft);
	if (mid) free(mid);
	if (rgt) free(rgt);
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

static int create_subchunks(t_chunk *arr, int *lft_vals, int lft_size,
							int *rgt_vals, int rgt_size, int *mid_vals)
{
	arr->left  = create_chunk(lft_vals, lft_size, TOP_A);
	arr->mid   = create_chunk(mid_vals, 1, TOP_B);
	arr->right = create_chunk(rgt_vals, rgt_size, BOTTOM_B);

	if (!arr->left || !arr->mid || !arr->right)
	{
		if (arr->left) free_chunk(arr->left);
		if (arr->mid) free_chunk(arr->mid);
		if (arr->right) free_chunk(arr->right);
		return 1; // fail
	}
	return 0; // success
}

void split_chunk(t_chunk *arr)
{
	int i, lft, rgt, size;
	int *lft_vals, *rgt_vals, *mid_vals;

	if (!arr || arr->size <= 1)
		return;

	size = arr->size;
	lft_vals = malloc(sizeof(int) * size);
	rgt_vals = malloc(sizeof(int) * size);
	mid_vals = malloc(sizeof(int));
	if (!lft_vals || !rgt_vals || !mid_vals)
	{
		free_tmp_arrays(lft_vals, mid_vals, rgt_vals);
		return;
	}

	mid_vals[0] = find_pivot(arr->values, size);

	lft = 0; rgt = 0;
	for (i = 0; i < size; i++)
	{
		if (arr->values[i] < mid_vals[0])
			lft_vals[lft++] = arr->values[i];
		else if (arr->values[i] > mid_vals[0])
			rgt_vals[rgt++] = arr->values[i];
		// equal to pivot is in mid_vals[0]
	}

	if (create_subchunks(arr, lft_vals, lft, rgt_vals, rgt, mid_vals))
	{
		free_tmp_arrays(lft_vals, mid_vals, rgt_vals);
		return;
	}

	free_tmp_arrays(lft_vals, mid_vals, rgt_vals);
}

/* ========================= SORT SMALL ========================= */
static void sa_rra(t_stack *a) { sa(a); rra(a); }
static void sa_ra(t_stack *a)  { sa(a); ra(a); }

void sort_small_a(t_chunk *arr, t_stack *a)
{
	int *val = arr->values;
	if (arr->size == 2)
	{
		if (val[0] > val[1]) sa(a);
	}
	else if (arr->size == 3)
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

static void sb_rrb(t_stack *b) { sb(b); rrb(b); }
static void sb_rb(t_stack *b)  { sb(b); rb(b); }

void sort_small_b(t_chunk *arr, t_stack *a, t_stack *b)
{
	int *val = arr->values;
	if (arr->size == 1) pa(a, b);
	else if (arr->size == 2)
	{
		if (val[0] < val[1]) sb(b);
		pa(a, b); pa(a, b);
	}
	else if (arr->size == 3)
	{
		if (val[0] < val[1] && val[1] > val[2] && val[0] > val[2])
			rb(b);
		else if (val[0] < val[1] && val[1] > val[2] && val[0] < val[2])
			sb_rb(b);
		else if (val[0] > val[1] && val[1] < val[2] && val[0] < val[2])
			rrb(b);
		else if (val[0] > val[1] && val[1] < val[2] && val[0] > val[2])
			sb(b);
		else if (val[0] > val[1] && val[1] > val[2])
			sb_rrb(b);
		while (b->size > 0) pa(a, b);
	}
}

void sort_small_botb(t_chunk *arr, t_stack *a, t_stack *b)
{
	int *val = arr->values;
	if (arr->size == 1) { pa(a,b); ra(a); }
	else if (arr->size == 2)
	{
		if (val[0] < val[1]) sb(b);
		pa(a,b); ra(a); pa(a,b); ra(a);
	}
	else if (arr->size == 3)
	{
		if (val[0] < val[1] && val[1] > val[2] && val[0] > val[2]) rb(b);
		else if (val[0] < val[1] && val[1] > val[2] && val[0] < val[2]) sb_rb(b);
		else if (val[0] > val[1] && val[1] < val[2] && val[0] < val[2]) rrb(b);
		else if (val[0] > val[1] && val[1] < val[2] && val[0] > val[2]) sb(b);
		else if (val[0] > val[1] && val[1] > val[2]) sb_rrb(b);
		while (arr->size--)
		{
			pa(a,b);
			ra(a);
		}
	}
}

void sort_small(t_chunk *arr, t_stack *a, t_stack *b)
{
	if (arr->location == TOP_A) sort_small_a(arr, a);
	else if (arr->location == TOP_B) sort_small_b(arr, a, b);
	else if (arr->location == BOTTOM_B) sort_small_botb(arr, a, b);
}

/* ========================= RECURSIVE QUICK SORT ========================= */
void recursive_quick_sort(t_chunk *arr, t_stack *a, t_stack *b)
{
	if (!arr || arr->size == 0) return;

	if (arr->size <= 3)
	{
		sort_small(arr, a, b);
		return;
	}

	split_chunk(arr);

	if (arr->left)  recursive_quick_sort(arr->left, a, b);
	if (arr->mid)   recursive_quick_sort(arr->mid, a, b);
	if (arr->right) recursive_quick_sort(arr->right, a, b);
}
