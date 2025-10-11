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

//link_list---------------------------------------------------------------
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
//---------------------------------------------------------------

//assigned_stack---------------------------------------------------------------
int				check(t_list *lst, int n, char *nbr);
void			idx_replace(t_list *lst, int min, int i);
int				ft_min(t_list *lst);
void			assign_index(t_list *lst);
t_list			*init_stack(char **av, int ac);
//---------------------------------------------------------------

//quick_sort---------------------------------------------------------------

//---------------------------------------------------------------

//first_chunk---------------------------------------------------------------
void			do_sort(t_stack *node);
void			sort_chunk_of_three(t_stack *lst);
void			sort_chunk_of_five(t_stack *lst);
int				is_already_sort(t_list *stack);
int				is_rev_sort(t_list *stack);

//---------------------------------------------------------------

//free---------------------------------------------------------------
void			free_stack(t_list *stack);
void			free_all(t_stack *stack, char **args, int ac);
//---------------------------------------------------------------

//operate---------------------------------------------------------------
void			sa(t_list **a);
void			sb(t_list **b);
void			ss(t_list **a, t_list **b);
void			pa(t_list **a, t_list **b);
void			pb(t_list **a, t_list **b);
void			ra(t_list **a);
void			rb(t_list **b);
void			rr(t_list **a, t_list **b);
void			rra(t_list **a);
void			rra(t_list **b);
void			rrr(t_list **a, t_list **b);
//---------------------------------------------------------------

#endif
