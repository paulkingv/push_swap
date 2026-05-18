/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pking <pking@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 15:57:20 by pking             #+#    #+#             */
/*   Updated: 2026/01/27 14:30:00 by pking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Mallocs, then returns an array of strings obtained by 
// splitting 's' using the character 'c' as a delimiter.
// Array must end with a NULL pointer.
static int	word_len(char const *s, char c)
{
	int	length;

	length = 0;
	while (s[length] != '\0' && s[length] != c)
		length++;
	return (length);
}

static int	count_c(char const *s, char c)
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
			count += 1;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static const char	*write_array(char const *s,
						char c, char **str_array, int *i)
{
	int	len;

	if (*s != c)
	{
		len = word_len(s, c);
		str_array[*i] = ft_substr(s, 0, len);
		if (!str_array[*i])
		{
			while (*i > 0)
			{
				(*i)--;
				free(str_array[*i]);
			}
			free(str_array);
			return (NULL);
		}
		(*i)++;
		s += len;
	}
	else
		s++;
	return (s);
}

char	**ft_split(char const *s, char c)
{
	char	**str_array;
	int		num_words;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	num_words = count_c(s, c);
	str_array = malloc(sizeof(char *) * (num_words + 1));
	if (!str_array)
		return (NULL);
	while (*s)
	{
		s = write_array(s, c, str_array, &i);
		if (!s)
			return (NULL);
	}
	if (str_array)
		str_array[i] = NULL;
	return (str_array);
}
