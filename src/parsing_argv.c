/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_argv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pking <pking@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 17:36:27 by pking             #+#    #+#             */
/*   Updated: 2026/05/18 18:53:58 by pking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// edgecase for having \t or other whitespace chars discovered with claude
static void	normalize_spaces(char *str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\f'
			|| str[i] == '\r' || str[i] == '\v')
			str[i] = ' ';
		i++;
	}
}

int	is_only_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] > 32)
			return (0);
		i++;
	}
	return (1);
}

char	**get_args(char **argv)
{
	int		i;
	char	*str;
	char	**args;

	i = 0;
	if (!argv)
		return (NULL);
	str = ft_calloc(1, 1);
	if (!str)
		return (NULL);
	while (argv[i])
	{
		if ((ft_strlen(argv[i]) <= 1 && argv[i][0] == ' ')
			|| is_only_spaces(argv[i]) || !argv[i])
		{
			free(str);
			error_msg(NULL);
		}
		str = ft_strjoin_free(str, " ", 1, 0);
		str = ft_strjoin_free(str, argv[i++], 1, 0);
	}
	normalize_spaces(str);
	args = ft_split(str, ' ');
	free(str);
	return (args);
}

void	fill_stack(t_stack *stack, char **args)
{
	int	i;

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

int	is_duplicate(t_stack *stack, int *array)
{
	int	i;
	int	j;

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
