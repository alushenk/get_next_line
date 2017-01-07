/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:07:51 by alushenk          #+#    #+#             */
/*   Updated: 2016/11/22 14:07:57 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*udst;
	unsigned char	*usrc;

	udst = (unsigned char*)dst;
	usrc = (unsigned char*)src;
	if (udst > usrc)
	{
		udst += len;
		usrc += len;
		while (len--)
			*(--udst) = *(--usrc);
	}
	else
		while (len--)
			*(udst++) = *(usrc++);
	return (dst);
}
