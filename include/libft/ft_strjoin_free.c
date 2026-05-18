/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pking <pking@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 14:40:30 by pking             #+#    #+#             */
/*   Updated: 2026/05/18 19:18:52 by pking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// mallocs, then returns new string by concatinating s1 + s2
static void	free_s1_s2(char const *s1, char const *s2, int free_s1, int free_s2)
{
	if (free_s1)
		free((void *)s1);
	if (free_s2)
		free((void *)s2);
}

char	*ft_strjoin_free(char const *s1, char const *s2, int free_s1,
		int free_s2)
{
	int		i;
	int		j;
	char	*concat_string;

	i = 0;
	j = 0;
	concat_string = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1),
			sizeof(char));
	if (!concat_string)
		return (NULL);
	while (s1[i] != '\0')
	{
		concat_string[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		concat_string[i + j] = s2[j];
		j++;
	}
	free_s1_s2(s1, s2, free_s1, free_s2);
	return (concat_string);
}
