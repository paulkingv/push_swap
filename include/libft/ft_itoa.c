/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pking <pking@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 14:29:12 by pking             #+#    #+#             */
/*   Updated: 2026/01/26 19:46:21 by pking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_size(int n)
{
	int	n_len;

	n_len = 0;
	if (n < 0)
		n_len++;
	while (n != 0)
	{
		n_len++;
		n = n / 10;
	}
	return (n_len);
}

static void	fill_itoa(int n, int len, char *nb)
{
	while (n != 0)
	{
		nb[len] = ((n % 10) + '0');
		n /= 10;
		len--;
	}
}

static char	*special_cases(int n, char **ascii_num)
{
	if (n == -2147483648)
	{
		*ascii_num = ft_strdup("-2147483648");
		if (!(*ascii_num))
			return (NULL);
		return (*ascii_num);
	}
	if (n == 0)
	{
		*ascii_num = ft_strdup("0");
		if (!(*ascii_num))
			return (NULL);
		return (*ascii_num);
	}
	return (NULL);
}

char	*ft_itoa(int n)
{
	char	*ascii_num;
	int		n_len;

	ascii_num = NULL;
	if (special_cases(n, &ascii_num))
	{
		return (ascii_num);
	}
	if ((n == -2147483648 || n == 0) && !ascii_num)
		return (NULL);
	n_len = num_size(n);
	ascii_num = malloc(sizeof(char) * (n_len + 1));
	if (!ascii_num)
		return (NULL);
	ascii_num[n_len] = '\0';
	if (n < 0)
	{
		n *= -1;
		fill_itoa(n, n_len - 1, ascii_num);
		ascii_num[0] = '-';
	}
	else
		fill_itoa(n, n_len - 1, ascii_num);
	return (ascii_num);
}
