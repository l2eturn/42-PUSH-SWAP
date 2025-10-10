/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimvutt <slimvut@fpgij;dgj;ds.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 09:24:01 by slimvutt          #+#    #+#             */
/*   Updated: 2025/10/04 09:24:01 by slimvutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include "../libft/libft.h"
# include <limits.h>
//---------------------------------------------------------------
typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef struct s_stack
{
	t_node		*top;
	t_node		*bottom;
	int			size;
}				t_stack;

typedef enum e_location
{
	TOP_A,
	TOP_B,
	BOTTOM_B
}			t_location;

typedef struct s_chunk
{
	int			*values;
	int			min_val;
	int			med_val;
	int			max_val;
	int			size;
	t_location	location;
	struct s_chunk		*left;
	struct s_chunk		*mid;
	struct s_chunk		*right;
}				t_chunk;

//typedef struct s_split_chunks
//{
//	t_chunk	min;
//	t_chunk	mid;
//	t_chunk	max;
//}				t_split_chunks;

//---------------------------------------------------------------
int				ft_check(t_stack *stack, char *nbr, int value);
void			free_stack(t_stack *stack);
t_node			*new_t(t_stack *stack, int nbr);
t_stack			*init_a(void);
t_stack			*init_stack_b(void);
t_stack			*init_stack_a(char **args, int i);
void			free_init_a_if_error(t_stack *stack);
void			sa(t_stack *a);
void			sb(t_stack *b);
void			ss(t_stack *a, t_stack *b);
void			pa(t_stack *a, t_stack *b);
void			pb(t_stack *a, t_stack *b);
void			ra(t_stack *a);
void			rb(t_stack *b);
void			rr(t_stack *a, t_stack *b);
void			rra(t_stack *a);
void			rrb(t_stack *b);
void			rrr(t_stack *a, t_stack *b);
//---------------------------------------------------------------
void			print_stack(t_stack *stack, char name);
//---------------------------------------------------------------
int				stack_size(t_stack *s);
int				find_pivot(t_stack *stack, int len);
int				*fill_arr(t_stack *stack, int len);
void			bubble_sort_arr(int *arr, int len);
void			quick_sort_a(t_stack *a, t_stack *b, int len);
//---------------------------------------------------------------
void			rescursive_quick_sort(t_chunk *arr);
void			split_chunk(t_chunk *arr);
t_chunk			*create_chunk(int *values, int size, t_location loc);
void			helper_for_fill(t_chunk *arr,int *lft_vals, int *rgt_vals, int *mid_vals);
int				free_vals(int *lft_vals,int *rgt_vals,int *mid_vals);
void			help_for_free(int *lft_vals, int *rgt_vals, int *mid_vals);

//---------------------------------------------------------------
#endif
