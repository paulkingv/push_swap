/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pking <pking@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 16:20:17 by pking             #+#    #+#             */
/*   Updated: 2026/01/24 20:56:41 by pking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr_m;

	if (nmemb > 0 && size > 0 && nmemb > (size_t)-1 / size)
		return (NULL);
	ptr_m = malloc(nmemb * size);
	if (!ptr_m)
		return (NULL);
	ft_bzero (ptr_m, nmemb * size);
	return (ptr_m);
}
