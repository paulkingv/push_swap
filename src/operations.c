/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pking <pking@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:29:06 by pking             #+#    #+#             */
/*   Updated: 2026/04/01 18:02:17 by pking            ###   ########.fr       */
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

void    push(int *src, int *src_size, int *dst, int *dst_size, char *name)
{
    int i;

    if (*src_size == 0)
        return ;
    i = *dst_size;
    while (i > 0)
    {
        dst[i] = dst[i - 1];
        i--;
    }
    dst[0] = src[0];
    i = 0;
    while (i < *src_size - 1)
    {
        src[i] = src[i + 1];
        i++;
    }
    (*dst_size)++;
    (*src_size)--;
    ft_putendl_fd(name, 1);
}

