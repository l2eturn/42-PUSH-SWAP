#include "greedy.h"

void	index_stack(t_stack *a)
{
	t_node	*i;
	t_node	*j;
	int		index;

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
//lis.c

int	*find_lis(t_stack *a, int *lis_size)
{
	int		n;
	int		*arr;
	int		*lis;
	int		*prev;
	int		max_len;
	int		max_idx;
	t_node	*tmp;
	int		i;
	int		j;

	n = a->size;
	arr = malloc(sizeof(int) * n);
	lis = malloc(sizeof(int) * n);
	prev = malloc(sizeof(int) * n);
	tmp = a->top;
	i = 0;
	while (tmp)
	{
		arr[i++] = tmp->index;
		tmp = tmp->next;
	}
	i = 0;
	max_len = 0;
	while (i < n)
	{
		lis[i] = 1;
		prev[i] = -1;
		j = 0;
		while (j < i)
		{
			if (arr[j] < arr[i] && lis[j] + 1 > lis[i])
			{
				lis[i] = lis[j] + 1;
				prev[i] = j;
			}
			j++;
		}
		if (lis[i] > max_len)
		{
			max_len = lis[i];
			max_idx = i;
		}
		i++;
	}
	*lis_size = max_len;
	int *seq = malloc(sizeof(int) * max_len);
	i = max_len - 1;
	while (i >= 0)
	{
		seq[i] = arr[max_idx];
		max_idx = prev[max_idx];
		i--;
	}
	free(lis);
	free(prev);
	free(arr);
	return (seq);
}

// push_except_lis.c

int	in_lis(int *lis, int lis_size, int index)
{
	int	i = 0;

	while (i < lis_size)
	{
		if (lis[i] == index)
			return (1);
		i++;
	}
	return (0);
}

// เช็คว่าค่า index อยู่ใน chunk ปัจจุบันหรือไม่
int	in_chunk(int index, int chunk_start, int chunk_end)
{
	return (index >= chunk_start && index <= chunk_end);
}

// push element ออกจาก a ไป b ตาม chunk
void	push_chunk_to_b(t_stack *a, t_stack *b, int chunk_start, int chunk_end)
{
	int	size = a->size;
	int	i = 0;

	while (i < size)
	{
		if (!in_chunk(a->top->index, chunk_start, chunk_end))
			ra(a); // หมุนหา element ใน chunk
		else
			pb(a, b); // push ไป b
		i++;
	}
}

// push ทั้งหมด (ยกเว้น LIS) แบบ chunked
// void	push_all_except_lis_chunked(t_stack *a, t_stack *b, int *lis, int lis_size)
void	push_all_except_lis_chunked(t_stack *a, t_stack *b)
{
	int	total = a->size;
	int	chunk_count;
	int	chunk_size;
	int	chunk_start;
	int	chunk_end;
	int	i;

	if (total <= 100)
		chunk_count = 5;
	else
		chunk_count = 11;

	chunk_size = total / chunk_count;

	chunk_start = 0;
	for (i = 0; i < chunk_count; i++)
	{
		chunk_end = chunk_start + chunk_size;
		if (i == chunk_count - 1)
			chunk_end = total;
		push_chunk_to_b(a, b, chunk_start, chunk_end);
		chunk_start = chunk_end + 1;
	}
}

//cost.c

void	calculate_cost(t_stack *a, t_stack *b)
{
	t_node	*tmp;
	int		pos_a;
	int		pos_b;

	tmp = b->top;
	while (tmp)
	{
		tmp->target = find_target_position(a, tmp->index);
		pos_a = get_position_in_stack(a, tmp->target);
		pos_b = get_position_in_stack(b, tmp);
		tmp->cost_a = (pos_a <= a->size / 2) ? pos_a : pos_a - a->size;
		tmp->cost_b = (pos_b <= b->size / 2) ? pos_b : pos_b - b->size;
		tmp->total_cost = abs(tmp->cost_a) + abs(tmp->cost_b);
		tmp = tmp->next;
	}
}

t_node	*find_cheapest(t_stack *b)
{
	t_node	*tmp;
	t_node	*best;

	tmp = b->top;
	best = tmp;
	while (tmp)
	{
		if (tmp->total_cost < best->total_cost)
			best = tmp;
		tmp = tmp->next;
	}
	return (best);
}

//rotation.c

void	do_rotation(t_stack *a, t_stack *b, t_node *cheapest)
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

// greedy.c

void	push_back_greedy(t_stack *a, t_stack *b)
{
	t_node	*cheapest;

	while (b->size > 0)
	{
		calculate_cost(a, b);
		cheapest = find_cheapest(b);

		// ทำ rotate ซ้ำกันให้มากที่สุด
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

		// หมุน stack ที่เหลือทีละ step
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

		pa(a, b);
	}
}


//finalize.c
void	final_rotation(t_stack *a)
{
	int	min_pos;

	min_pos = find_min_position(a);
	if (min_pos <= a->size / 2)
	{
		while (min_pos--)
			ra(a);
	}
	else
	{
		while (min_pos++ < a->size)
			rra(a);
	}
}
// หาตำแหน่งใน stack_a ที่ควรแทรกค่าของ node จาก b
t_node	*find_target_position(t_stack *a, int b_index)
{
	t_node	*tmp;
	t_node	*target;
	int		min_diff;

	tmp = a->top;
	target = NULL;
	min_diff = INT_MAX;

	while (tmp)
	{
		if (tmp->index > b_index && tmp->index - b_index < min_diff)
		{
			min_diff = tmp->index - b_index;
			target = tmp;
		}
		tmp = tmp->next;
	}

	// ถ้าไม่มีตัวที่ใหญ่กว่า แปลว่า target คือค่าที่เล็กสุด
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
	return (target);
}

// หา position (จากบนสุดเริ่มที่ 0)
int	get_position_in_stack(t_stack *stack, t_node *node)
{
	t_node	*tmp;
	int		pos;

	tmp = stack->top;
	pos = 0;
	while (tmp)
	{
		if (tmp == node)
			return (pos);
		tmp = tmp->next;
		pos++;
	}
	return (-1);
}

// หา position ของค่าที่เล็กที่สุดใน stack
int	find_min_position(t_stack *a)
{
	t_node	*tmp;
	int		min_index;
	int		pos;
	int		i;

	tmp = a->top;
	min_index = tmp->index;
	pos = 0;
	i = 0;
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
	return (pos);
}
