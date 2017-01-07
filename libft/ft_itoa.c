/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:35:01 by alushenk          #+#    #+#             */
/*   Updated: 2016/11/28 13:35:04 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	count_len(int n)
{
	size_t			i;
	unsigned int	un;

	i = 1;
	un = n;
	if (n < 0)
	{
		un = -n;
		i++;
	}
	while ((un /= 10) >= 1)
		i++;
	return (i);
}

char			*ft_itoa(int n)
{
	size_t			len;
	size_t			start;
	char			*ptr;
	unsigned int	un;

	len = count_len(n);
	un = n;
	start = 0;
	if ((ptr = ft_strnew(len)))
	{
		if (n < 0)
		{
			ptr[0] = '-';
			un = -n;
			start = 1;
		}
		while (len-- > start)
		{
			ptr[len] = (un % 10) + 48;
			un /= 10;
		}
		return (ptr);
	}
	return (NULL);
}
