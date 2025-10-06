/* ************************************************************************** */
/* greedy_push_swap.c - all-in-one optimized version                         */
/* ************************************************************************** */

#include "greedy.h"
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// ======================= index_stack =======================
void index_stack(t_stack *a)
{
	t_node *i, *j;
	int index;

	i = a->top;
	while (i)
	{
		index = 0;
		j = a->top;
		while (j)
		{
			if (j->value < i->value)
				index++;
			j = j->next;
		}
		i->index = index;
		i = i->next;
	}
}

// ======================= LIS =======================
int *find_lis(t_stack *a, int *lis_size)
{
	int n = a->size;
	int *arr = malloc(sizeof(int) * n);
	int *lis = malloc(sizeof(int) * n);
	int *prev = malloc(sizeof(int) * n);
	t_node *tmp = a->top;
	int i = 0, j, max_len = 0, max_idx = 0;

	while (tmp)
	{
		arr[i++] = tmp->index;
		tmp = tmp->next;
	}

	for (i = 0; i < n; i++)
	{
		lis[i] = 1;
		prev[i] = -1;
		for (j = 0; j < i; j++)
		{
			if (arr[j] < arr[i] && lis[j] + 1 > lis[i])
			{
				lis[i] = lis[j] + 1;
				prev[i] = j;
			}
		}
		if (lis[i] > max_len)
		{
			max_len = lis[i];
			max_idx = i;
		}
	}

	*lis_size = max_len;
	int *seq = malloc(sizeof(int) * max_len);
	for (i = max_len - 1; i >= 0; i--)
	{
		seq[i] = arr[max_idx];
		max_idx = prev[max_idx];
	}
	free(lis);
	free(prev);
	free(arr);
	return seq;
}

int in_lis(int *lis, int lis_size, int index)
{
	for (int i = 0; i < lis_size; i++)
		if (lis[i] == index)
			return 1;
	return 0;
}

// ======================= chunk push =======================
int find_in_chunk_position(t_stack *a, int chunk_start, int chunk_end)
{
	t_node *tmp = a->top;
	int pos = 0;

	while (tmp)
	{
		if (tmp->index >= chunk_start && tmp->index <= chunk_end)
			return pos;
		tmp = tmp->next;
		pos++;
	}
	return -1;
}

void push_chunk_to_b(t_stack *a, t_stack *b, int chunk_start, int chunk_end)
{
	int pos;

	while ((pos = find_in_chunk_position(a, chunk_start, chunk_end)) != -1)
	{
		if (pos <= a->size / 2)
		{
			while (pos-- > 0)
				ra(a);
		}
		else
		{
			pos = a->size - pos;
			while (pos-- > 0)
				rra(a);
		}
		pb(a, b);
	}
}

void	push_all_except_lis_chunked(t_stack *a, t_stack *b, int *lis, int lis_size)
{
	int	total = a->size;
	int	i;
	t_node *top;

	i = 0;
	while (i < total)
	{
		top = a->top;
		if (!in_lis(lis, lis_size, top->index))
			pb(a, b);
		else
			ra(a);
		i++;
	}
}


// ======================= cost calculation =======================
void calculate_cost(t_stack *a, t_stack *b);

t_node *find_target_position(t_stack *a, int b_index)
{
	t_node *tmp = a->top;
	t_node *target = NULL;
	int min_diff = INT_MAX;

	while (tmp)
	{
		if (tmp->index > b_index && tmp->index - b_index < min_diff)
		{
			min_diff = tmp->index - b_index;
			target = tmp;
		}
		tmp = tmp->next;
	}

	if (!target)
	{
		tmp = a->top;
		target = tmp;
		while (tmp)
		{
			if (tmp->index < target->index)
				target = tmp;
			tmp = tmp->next;
		}
	}
	return target;
}

int get_position_in_stack(t_stack *stack, t_node *node)
{
	t_node *tmp = stack->top;
	int pos = 0;

	while (tmp)
	{
		if (tmp == node)
			return pos;
		tmp = tmp->next;
		pos++;
	}
	return -1;
}

void calculate_cost(t_stack *a, t_stack *b)
{
	t_node *tmp = b->top;
	while (tmp)
	{
		tmp->target = find_target_position(a, tmp->index);
		int pos_a = get_position_in_stack(a, tmp->target);
		int pos_b = get_position_in_stack(b, tmp);
		tmp->cost_a = (pos_a <= a->size / 2) ? pos_a : pos_a - a->size;
		tmp->cost_b = (pos_b <= b->size / 2) ? pos_b : pos_b - b->size;
		tmp->total_cost = abs(tmp->cost_a) + abs(tmp->cost_b);
		tmp = tmp->next;
	}
}

t_node *find_cheapest(t_stack *b)
{
	t_node *tmp = b->top;
	t_node *best = tmp;
	while (tmp)
	{
		if (tmp->total_cost < best->total_cost)
			best = tmp;
		tmp = tmp->next;
	}
	return best;
}

// ======================= rotations =======================
void do_rotation(t_stack *a, t_stack *b, t_node *cheapest)
{
	while (cheapest->cost_a > 0 && cheapest->cost_b > 0)
	{
		rr(a, b);
		cheapest->cost_a--;
		cheapest->cost_b--;
	}
	while (cheapest->cost_a < 0 && cheapest->cost_b < 0)
	{
		rrr(a, b);
		cheapest->cost_a++;
		cheapest->cost_b++;
	}
	while (cheapest->cost_a > 0)
	{
		ra(a);
		cheapest->cost_a--;
	}
	while (cheapest->cost_a < 0)
	{
		rra(a);
		cheapest->cost_a++;
	}
	while (cheapest->cost_b > 0)
	{
		rb(b);
		cheapest->cost_b--;
	}
	while (cheapest->cost_b < 0)
	{
		rrb(b);
		cheapest->cost_b++;
	}
}

void	push_back_greedy(t_stack *a, t_stack *b)
{
	t_node	*cheapest;

	while (b->size > 0)
	{
		calculate_cost(a, b);
		cheapest = find_cheapest(b);
		do_rotation(a, b, cheapest);
		pa(a, b);
	}
}


// ======================= finalize =======================
int find_min_position(t_stack *a)
{
	t_node *tmp = a->top;
	int min_index = tmp->index, pos = 0, i = 0;
	while (tmp)
	{
		if (tmp->index < min_index)
		{
			min_index = tmp->index;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return pos;
}

void final_rotation(t_stack *a)
{
	int min_pos = find_min_position(a);
	if (min_pos <= a->size / 2)
		while (min_pos-- > 0)
			ra(a);
	else
		while (min_pos++ < a->size)
			rra(a);
}
