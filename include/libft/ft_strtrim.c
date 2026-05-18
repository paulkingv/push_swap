/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pking <pking@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 12:07:05 by pking             #+#    #+#             */
/*   Updated: 2026/01/27 14:27:57 by pking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Mallocs, then returns a copy of 's1' after 
// removing chars in 'set' from the beginning and the end.
static int	is_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed_s1;
	int		i;
	int		j;
	int		len;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] != '\0' && is_in_set(s1[i], set))
		i++;
	j = 0;
	while (s1[j] != '\0')
		j++;
	j--;
	while (j >= i && is_in_set(s1[j], set))
		j--;
	len = j - i + 1;
	if (len < 0)
		len = 0;
	trimmed_s1 = ft_substr(s1, i, len);
	return (trimmed_s1);
}
