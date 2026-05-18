/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pking <pking@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 17:45:28 by pking             #+#    #+#             */
/*   Updated: 2026/05/18 15:47:47 by pking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//valid
// check if we have digit at all positions in str
int has_digit(char *str)
{
    int i;

    i=0;
    if (!str || !str[0])
        return(0);
    if(str[0] == '-' || str[0] == '+' )
    {
        if(str[1] == '\0' || !ft_isdigit((unsigned char)str[1]) )
            return (0);
        i = 1;
    }
    while(str[i])
    {
        if (!ft_isdigit((unsigned char)str[i]))
            return (0);
        i++;
    }
    return (1);
}

int has_overflow(char *str)
{
    long n;

    n = 0;
    n = ft_atol(str);
    if (n > 2147483647 || n < -2147483648)
        return (1);
    return (0);
}

int valid_args(char **args)
{
    int i;

    i = 0;
    while (args[i])
    {
        if(!has_digit(args[i])) // Checks if is digit
            return (0);
        if(has_overflow(args[i]))
            return (0);
        i++;
    }
    return (1); // not true
}

int is_array_sorted(int *arr, int size)
{
    int i;

    i = 0;
    while (i < size - 1)
    {
        if (arr[i] > arr[i + 1])
            return (0);
        i++;
    }
    return (1);
}
