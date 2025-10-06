/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimvutt <slimvut@fpgij;dgj;ds.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 03:18:37 by slimvutt          #+#    #+#             */
/*   Updated: 2025/10/06 03:18:37 by slimvutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GREEDY_H
# define GREEDY_H
# include "../libft/libft.h"
# include "pushswap.h"
# include <limits.h>
//---------------------------------------------------------------
void	index_stack(t_stack *a);
int	*find_lis(t_stack *a, int *lis_size);
int	in_lis(int *lis, int lis_size, int index);
int	in_chunk(int index, int chunk_start, int chunk_end);
void	push_chunk_to_b(t_stack *a, t_stack *b, int chunk_start, int chunk_end);
void	push_all_except_lis_chunked(t_stack *a, t_stack *b);
void	calculate_cost(t_stack *a, t_stack *b);
t_node	*find_cheapest(t_stack *b);
void	do_rotation(t_stack *a, t_stack *b, t_node *cheapest);
void	push_back_greedy(t_stack *a, t_stack *b);
void	final_rotation(t_stack *a);
t_node	*find_target_position(t_stack *a, int b_index);
int	get_position_in_stack(t_stack *stack, t_node *node);
int	find_min_position(t_stack *a);
//---------------------------------------------------------------
#endif
