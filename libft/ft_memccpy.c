/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:48:58 by alushenk          #+#    #+#             */
/*   Updated: 2016/11/22 16:49:00 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *udst;
	unsigned char *usrc;
	unsigned char sym;

	sym = (unsigned char)c;
	udst = (unsigned char*)dst;
	usrc = (unsigned char*)src;
	while (n--)
	{
		if (*usrc == sym)
		{
			*udst = sym;
			return (++udst);
		}
		*(udst++) = *(usrc++);
	}
	return (NULL);
}
