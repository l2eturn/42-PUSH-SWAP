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

#endif