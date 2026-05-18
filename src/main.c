/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pking <pking@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 14:09:09 by pking             #+#    #+#             */
/*   Updated: 2026/05/17 20:23:02 by pking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int error_msg(t_stack *stack)
{
    if (stack)
        free_all(stack);
    ft_putendl_fd("Error", 2);
    exit (1);
}

// This function is called to parse, check for discrepancies, 
void    init(t_stack *stack, char **argv)
{
    stack->args = get_args(argv + 1); // [1] puts arguments into the struct's args container
    if (!stack->args)
        error_msg(NULL);
    init_stacks(stack);
    if (!valid_args(stack->args))
        error_msg(stack);
    if (count_array(stack->args) < 1) // if we have less than 1 arg
        error_msg(stack);
    fill_stack(stack, stack->args);
    if (is_duplicate(stack, stack->a)) //goes through struct stackA to find dupes
        error_msg(stack);
    if (is_array_sorted(stack->a, stack->a_size)) 
    {
        free_all(stack);
        exit(0);
    }
} 

int main (int argc, char **argv)
{
    t_stack stack;

    if (argc < 2 || (argc == 2 && !argv[1][0]))
    {
        error_msg(NULL);
        return(1);
    }    
    init(&stack, argv);
    index_stack(&stack);
    if (stack.a_size == 2 && stack.a[0] > stack.a[1])
        swap(stack.a, "sa", stack.a_size);
    else if (stack.a_size == 3)
        sort_three(&stack);
    else if (stack.a_size >= 4 && stack.a_size <= 5)
        sort_fourfive(&stack);
    else
        radix(&stack);
    free_all(&stack);
    return (0);
}

//verified