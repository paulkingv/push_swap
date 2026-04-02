/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pking <pking@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 15:07:19 by pking             #+#    #+#             */
/*   Updated: 2026/04/01 18:02:35 by pking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// ------------------ //
int	ft_count_array(char **args)
{
	int i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

char **get_args(char **argv)
{
	char	**result;
	int		count;
	int		i;

	if (argv[0] && !argv[1])
		return (ft_split(argv[0], ' '));
	count = ft_count_array(argv);
	result = malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (argv[i])
	{
		result[i] = ft_strdup(argv[i]);
		if (!result[i])
		{
			while (i > 0)
				free(result[--i]); // Need to understand this line perfectly
			free(result);
			return (NULL);
		}
		i++;
	}
	result[i] = (NULL); // added parenthesis
	return (result);
}

void	init_stacks(t_stack *stack)
{
	stack->a = NULL;
	stack->b = NULL; //need to understand these lines
	stack->a_size = 0;
	stack->b_size = 0;
}

void	fill_stack(t_stack *stack, char **args)
{
	int count;
	int i;

	count = ft_count_array(args);
	stack->a = malloc(sizeof(int) * count);
	if (!stack->a)
		error_msg(stack);
	stack->a_size = count;
	stack->b_size = 0;
	i = 0;
	while(args[i])
	{
		stack->a[i] = (int)ft_atol(args[i]);
		i++;
	}
}

int		is_duplicate(t_stack *stack, int *arr)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->a_size)
	{
		j = i + 1;
		while (j < stack->a_size)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

