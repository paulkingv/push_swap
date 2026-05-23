/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pking <pking@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:29:06 by pking             #+#    #+#             */
/*   Updated: 2026/05/23 17:31:52 by pking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap(int *arr, char *name, int size)
{
    int tmp;

    if (size < 2)
        return;
    tmp = arr[0];
    arr[0] = arr[1];
    arr[1] = tmp;
    ft_putendl_fd (name, 1);
}

void    rotate(int *arr, int size, char *name)
{
    int     tmp;
    int     i;

    if (size < 2)
        return ;
    tmp = arr[0];
    i = 0;
    while (i < size - 1)
    {
        arr[i] = arr[i + 1];
        i++;
    }
    arr[size - 1] = tmp;
    ft_putendl_fd(name, 1);
}

void    reverse_rotate(int *arr, int size, char *name)
{
    int     tmp;
    int     i;

    if (size < 2)
        return ;
    tmp = arr[size - 1];
    i = size - 1;
    while (i > 0)
    {
        arr[i] = arr[i - 1];
        i--;
    }
    arr[0] = tmp;
    ft_putendl_fd(name, 1);
}

void    pa(t_stack *stack, char *name)
{
    int i;

    if (stack->b_size == 0)
        return ;
    i = stack->a_size;
    while (i > 0)
    {
        stack->a[i] = stack->a[i - 1];
        i--;
    }
    stack->a[0] = stack->b[0];
    i = 0;
    while (i < stack->b_size - 1)
    {
        stack->b[i] = stack->b[i + 1];
        i++;
    }
    stack->a_size++;
    stack->b_size--;
    ft_putendl_fd(name, 1);
}

void    pb(t_stack *stack, char *name)
{
    int i;
    if (stack->a_size == 0)
        return ;
    i = stack->b_size;
    while (i > 0)
    {
        stack->b[i] = stack->b[i - 1];
        i--;
    }
    stack->b[0] = stack->a[0];
    i = 0;
    while (i < stack->a_size - 1)
    {
        stack->a[i] = stack->a[i + 1];
        i++;
    }
    stack->b_size++;
    stack->a_size--;
    ft_putendl_fd(name, 1);
}

// Verified