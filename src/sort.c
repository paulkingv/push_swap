/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pking <pking@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:29:24 by pking             #+#    #+#             */
/*   Updated: 2026/04/01 18:02:31 by pking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static  void    rotate_min_to_top(t_stack *stack)
{
    int min;
    int min_i;
    int i;

    min = stack->a[0];
    min_i = 0;
    i = 1;
    while (i < stack->a_size)
    {
        if (stack->a[i] < min)
        {
            min = stack->a[i];
            min_i = i;
        }
        i++;
    }
    while (min_i-- > 0)
        rotate(stack->a, stack->a_size, "ra");
}

// STUDY THIS; 
void    sort_three_size(t_stack *stack)
{
    int a;
    int b;
    int c;

    a = stack->a[0];
    b = stack->a[1];
    c = stack->a[2];
    if (a > b && b < c && a > c)
        rotate(stack->a, stack->a_size, "ra");
    else if (a > b && b > c)
    {
        swap(stack->a, "sa", stack->a_size);
        reverse_rotate(stack->a, stack->a_size, "rra");
    }
    else if (a < b && b > c && a < c)
    {
        swap(stack->a, "sa", stack->a_size);
        rotate(stack->a, stack->a_size, "ra");
    }
    else if (a < b && b > c && a > c)
        reverse_rotate(stack->a, stack->a_size, "rra");
    else if (a > b && b < c && a < c)
        swap(stack->a, "sa", stack->a_size);
}

// Study this; Understand it; Rewrite
void    sort_four_to_five_size(t_stack *stack)
{
    if (stack->a_size == 5)
    {
        rotate_min_to_top(stack);
        push(stack->a, &stack->a_size, stack->b, &stack->b_size, "pb");
    }
    rotate_min_to_top(stack);
    push(stack->a, &stack->a_size, stack->b, &stack->b_size, "pb");
    sort_three_size(stack);
    while(stack->b_size > 0)
        push(stack->b, &stack->b_size, stack->a, &stack->a_size, "pa");
}

void    radix_sort(t_stack *stack)
{
    int i;
    int j;
    int max_bits;
    int size;

    size = stack->a_size;
    max_bits = 0;
    while ((size - 1) >> max_bits)
        max_bits++;
    i = 0;
    while (i < max_bits)
    {
        j = 0;
        while (j < size)
        {
            if (((stack->a[0] >> i) & 1) == 0)
                push(stack->a, &stack->a_size, stack ->b, &stack->b_size, "pb");
            else
                rotate(stack->a, stack->a_size, "ra");
            j++;
        }
        while (stack->b_size > 0)
            push(stack->b, &stack->b_size, stack->a, &stack->a_size, "pa");
        i++;
    }
}
