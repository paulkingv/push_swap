/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pking <pking@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 13:31:14 by pking             #+#    #+#             */
/*   Updated: 2026/01/27 15:00:03 by pking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Applies f() to each char of 's', passing its index as arg1, 
// and itself as arg2. A new string is created (malloc) to store
// the results from successive applications of f.
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			len;
	char			*string;

	if (!s || !f)
		return (NULL);
	i = 0;
	len = ft_strlen((char *)s);
	string = (char *)malloc((len + 1) * sizeof(char));
	if (!string)
		return (NULL);
	while (s[i] != '\0')
	{
		string[i] = f(i, s[i]);
		i++;
	}
	string[i] = '\0';
	return (string);
}
