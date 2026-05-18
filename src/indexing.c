/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pking <pking@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 16:01:00 by pking             #+#    #+#             */
/*   Updated: 2026/05/18 18:47:50 by pking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_ranks(t_stack *stack, int *tmp_a)
{
	int	i;
	int	j;
	int	rank;

	i = 0;
	while (i < stack->a_size)
	{
		j = 0;
		rank = 0;
		while (j < stack->a_size)
		{
			if (stack->a[j] < stack->a[i])
				rank++;
			j++;
		}
		tmp_a[i] = rank;
		i++;
	}
}

void	index_stack(t_stack *stack)
{
	int	*tmp_a;
	int	i;

	tmp_a = malloc(stack->a_size * sizeof(int));
	if (!tmp_a)
		error_msg(stack);
	fill_ranks(stack, tmp_a);
	i = 0;
	while (i < stack->a_size)
	{
		stack->a[i] = tmp_a[i];
		i++;
	}
	free(tmp_a);
}
