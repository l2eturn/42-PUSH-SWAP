/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimvutt <slimvut@fpgij;dgj;ds.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 20:40:51 by slimvutt          #+#    #+#             */
/*   Updated: 2025/10/12 20:40:51 by slimvutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <limits.h>

typedef struct s_stack
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		asize;
	int		bsize;
}		t_stack;
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

int				is_already_sort(t_list *stack);
int				check(t_list *lst, int n, char *nbr);
t_list			*init_stack(char **av, int ac);
void			free_list(t_list *lst);
void			free_stack(t_stack *stack, char **args, int ac);

int				is_already_sort(t_list *stack);
void			get_operate(t_stack *stack);
int				print_opt(char *opt, t_stack *stack);

void			swap_group(char *opt, t_stack *stack);
void			push_group(char *opt, t_stack *stack);
void			rotate_group(char *opt, t_stack *stack);
void			reverse_rotate_group(char *opt, t_stack *stack);
#endif
