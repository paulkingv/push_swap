/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pking <pking@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:37:17 by pking             #+#    #+#             */
/*   Updated: 2026/04/01 18:02:17 by pking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long    ft_atol(char *s)
{
    long    n;
    int     sign;
    int     i;

    n = 0;
    sign = 1;
    i = 0;
    if (s[i] == '+' || s[i] == '-')
    {
        if(s[i] == '-')
            sign = -1;
        i++;
    }
    while (s[i] >= '0' && s[i] <= '9')
    {
        n = n * 10 + (s[i] - '0');
        i++;
    }
    return (n * sign);
}

static  int is_valid_str(char *s)
{
    int     i;
    long    n;

    i = 0;
    if (!s || !s[0])
        return(0);
    if (s[i] == '+' || s[i] == '-')
        i++;
    if (!s[i])
        return (0);
    while (s[i])
    {
        if (s[i] < '0' || s[i] > '9')
            return (0);
        i++;
    }
    n = ft_atol(s);
    if (n > 2147483647 || n < -2147483648)
        return (0);
    return (1);
}

int is_valid(char **args)
{
    int i;

    i = 0;
    while (args[i])
    {
        if (!is_valid_str(args[i]))
            return (0);
        i++;
    }
    return (1);
}

int is_array_sorted(int *arr, int size)
{
    int i;

    i = 0;
    while (i < size - 1)
    {
        if (arr[i] > arr[i+1])
            return (0);
        i++;
    }
    return (1);
}