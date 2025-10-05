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

# ifndef	PUSHSWAP_H
# define	PUSHSWAP_H
# include	"../libft/libft.h"
# include 	<limits.h>
//---------------------------------------------------------------
typedef struct	s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef	struct	s_stack
{
	t_node		*top;
	t_node		*bottom;
	int			size;
}				t_stack;
//---------------------------------------------------------------
int				ft_check(t_stack *stack, char *nbr, int value);
void			free_stack(t_stack *stack);
t_node			*new_t(t_stack *stack, int nbr);
t_stack			*init_a(t_stack *st);
t_stack			*init_stack_b(void);
t_stack			*init_stack_a(char **args, int i);
void			print_stack(t_stack *stack, char name);
void			sa(t_stack *a);
void			sb(t_stack *b);
void			ss(t_stack *a, t_stack *b);
void			pa(t_stack *a, t_stack *b);
void			pb(t_stack *a, t_stack *b);
//---------------------------------------------------------------
# endif