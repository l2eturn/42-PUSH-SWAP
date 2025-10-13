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

typedef struct s_push
{
	int	next;
	int	max;
	int	mid;
	int	flag;
}	t_push;

typedef struct s_stack
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		asize;
	int		bsize;
}		t_stack;

int				check(t_list *lst, int n, char *nbr);
void			idx_replace(t_list *lst, int min, int i);
int				ft_min(t_list *lst);
void			assign_index(t_list *lst);
t_list			*init_stack(char **av, int ac);

void			quick_sort(t_list **stack_a, t_list **stack_b, int size);
void			devide_first_chunk(t_list **stack_a, t_list **stack_b,
					t_push *push, int size);
void			do_stack_a(t_list **stack_a, t_list **stack_b, t_push *push);
void			do_stack_b(t_list **stack_a, t_list **stack_b, t_push *push);

t_list			*max_in_lst(t_list *stack);
t_list			*min_in_lst(t_list *stack);
int				is_already_sort_a(t_list *stack, int size);
void			find_next(t_list **a, t_list **b, t_push *p);

void			do_sort(t_stack *node);
void			sort_chunk_of_three(t_stack *lst);
void			sort_chunk_of_five(t_stack *lst);
int				is_already_sort(t_list *stack);
int				is_rev_sort(t_list *stack);

void			free_stack(t_stack *stack, char **args, int ac);
void			free_list(t_list *lst);

void			sa(t_list **a);
void			sb(t_list **b);
void			ss(t_list **a, t_list **b);
void			pa(t_list **a, t_list **b);
void			pb(t_list **a, t_list **b);
void			ra(t_list **a);
void			rb(t_list **b);
void			rr(t_list **a, t_list **b);
void			rra(t_list **a);
void			rrb(t_list **b);
void			rrr(t_list **a, t_list **b);

#endif
