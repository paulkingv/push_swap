/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_argv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pking <pking@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 17:36:27 by pking             #+#    #+#             */
/*   Updated: 2026/05/17 16:22:54 by pking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// edgecase for having \t or other whitespace chars discovered with claude
static void normalize_spaces(char *str)
{
    int i;

    if (!str)
        return ;
    i = 0;
    while (str[i])
    {
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
            || str[i] == '\f' || str[i] == '\r' || str[i] == '\v' )
                str[i] = ' ';
        i++;
    }
}

int is_only_spaces(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] > 32)
            return (0);
        i++;
    }
    return (1);
}
// !! verified this is the same as ref (DEL)
char **get_args(char **argv)
{
    int i;
    char *str;
    char **args;

    i = 0;
    if (!argv)
        return (NULL);
    str = ft_calloc(1,1);
    if (!str)
        return(NULL);
    while (argv[i]) // does this while our argv[i] is not NULL9
    {
        if ((ft_strlen(argv[i]) <= 1 && argv[i][0] == ' ') || // arg's len <= 1 & its first char byte is ' ',
            is_only_spaces(argv[i]) || !argv[i])  // OR arg is only spaces OR arg is null
            {
                free(str);
                error_msg(NULL);
            }
            str = ft_strjoin_free(str, " ", 1, 0); // Here we joining the space to the string
            str = ft_strjoin_free(str, argv[i++], 1, 0); // Here we are joining the argv to the string.
    }
    normalize_spaces(str);
    args = ft_split(str, ' ');
    free(str);
    return (args);
}

void fill_stack(t_stack *stack, char **args)
{
    int i;

    i = 0;
    stack->a_size = count_array(args);
    stack->b_size = 0;
    stack->a = ft_calloc(stack->a_size, sizeof(int));
    if (!stack->a)
        error_msg(stack);
    stack->b = ft_calloc(stack->a_size, sizeof(int));
    if (!stack->b)
        error_msg(stack);
    while (args[i])
    {
        stack->a[i] = ft_atoi(args[i]);
        i++;
    }
}
/*  This function is_duplicate brute-force checks if 
    all numbers after the current index number [j] are 
    equal to the index i number.

    here, the array param is actually going to be stack->a
*/ 
int is_duplicate(t_stack *stack, int *array)
{
    int i;
    int j;

    i = 0;
    while (i < stack->a_size - 1)
    {
        j = i + 1;
        while (j < stack->a_size)
        {
            if (array[i] == array[j])
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

//verified 5.17