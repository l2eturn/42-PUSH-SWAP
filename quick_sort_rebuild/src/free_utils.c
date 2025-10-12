/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimvutt <slimvut@fpgij;dgj;ds.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 22:47:39 by slimvutt          #+#    #+#             */
/*   Updated: 2025/10/11 22:47:39 by slimvutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void free_list(t_list *lst)
{
    t_list *tmp;
    while (lst)
    {
        tmp = lst->next;
        free(lst);
        lst = tmp;
    }
}

void free_stack(t_stack *stack, char **args, int ac)
{
    if (stack->stack_a)
        free_list(stack->stack_a);
    if (stack->stack_b)
        free_list(stack->stack_b);
    free(stack);

    if (ac == 2 && args)
    {
        int i = 0;
        while (args[i])
            free(args[i++]);
        free(args);
    }
}
