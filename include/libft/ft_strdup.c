/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pking <pking@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 15:07:16 by pking             #+#    #+#             */
/*   Updated: 2026/01/27 15:00:22 by pking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*string;
	size_t	size;

	size = 0;
	while (s[size] != '\0')
		size++;
	size++;
	string = (char *)malloc(size * sizeof(char));
	if (!string)
		return (NULL);
	size = 0;
	while (s[size] != '\0')
	{
		string[size] = s[size];
		size++;
	}
	string[size] = '\0';
	return (string);
}
