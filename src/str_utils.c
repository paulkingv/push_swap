/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pking <pking@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:37:14 by pking             #+#    #+#             */
/*   Updated: 2026/04/02 16:41:42 by pking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "push_swap.h"
// Everything below was copy pasted, replace with my own functions later

#include "push_swap.h"

static int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	char	*dup;
	int		i;

	dup = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static int	count_words(char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*get_word(char *s, char c, int *i)
{
	int		start;
	int		len;
	char	*word;
	int		k;

	while (s[*i] == c)
		(*i)++;
	start = *i;
	while (s[*i] && s[*i] != c)
		(*i)++;
	len = *i - start;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	k = 0;
	while (k < len)
	{
		word[k] = s[start + k];
		k++;
	}
	word[k] = '\0';
	return (word);
}

char	**ft_split(char *s, char c)
{
	char	**arr;
	int		words;
	int		i;
	int		j;

	words = count_words(s, c);
	arr = malloc(sizeof(char *) * (words + 1));
	if (!arr)
		return (NULL);
	i = 0;
	j = 0;
	while (j < words)
	{
		arr[j] = get_word(s, c, &i);
		if (!arr[j])
		{
			while (j > 0)
				free(arr[--j]);
			free(arr);
			return (NULL);
		}
		j++;
	}
	arr[j] = NULL;
	return (arr);
}