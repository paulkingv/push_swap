/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pking <pking@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 17:57:28 by pking             #+#    #+#             */
/*   Updated: 2026/04/24 16:52:41 by pking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    free_all(t_stack *stack)
{
    int i;

    i = 0;
    if (stack->args)
    {
        while (stack->args[i])
            free(stack->args[i++]);
        free(stack->args);
    }
    if (stack->a)
        free(stack->a);
    if (stack->b)
        free(stack->b);
}

void init_stacks(t_stack *stack)
{
    stack->a = NULL;
    stack->b = NULL;
    stack->a_size = 0;
    stack->b_size = 0;
}

int count_array(char **argv)
{
    int i;

    i = 0;
    while (argv[i])
        i++;
    return (i);
}



