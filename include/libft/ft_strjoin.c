/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pking <pking@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 18:46:30 by pking             #+#    #+#             */
/*   Updated: 2026/01/27 15:00:10 by pking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// mallocs, then returns new string by concatinating s1 + s2
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_len;
	int		s2_len;
	int		i;
	int		j;
	char	*concat_string;

	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	i = 0;
	j = 0;
	concat_string = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
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
	concat_string[i + j] = '\0';
	return (concat_string);
}
