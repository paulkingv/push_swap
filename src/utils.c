/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pking <pking@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:29:41 by pking             #+#    #+#             */
/*   Updated: 2026/03/31 13:32:09 by pking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_putendl_fd(char *s, int fd)
{
    while (*s)
        write(fd, s++, 1);
    write(fd, "\n", 1);
}

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
static void fill_ranks(t_stack *stack, int *ranks)
{
    int i;
    int j;
    int rank;

    i = 0;
    while (i < stack->a_size)
    {
        rank = 0;
        j = 0;
        while (j < stack->a_size)
        {
            if (stack->a[j] < stack->a[i])
                rank++;
            j++;
        }
        ranks[i] = rank;
        i++;
    }
}
void    index_stack(t_stack *stack)
{
    int *ranks;
    int i;

    ranks = malloc(sizeof(int) * stack->a_size);
    if (!ranks)
        error_msg(stack);
    fill_ranks(stack, ranks);
    i = 0;
    while (i < stack->a_size)
    {
        stack->a[i] = ranks[i];
        i++;
    }
    free(ranks);
}