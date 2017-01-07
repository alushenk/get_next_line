/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:53:53 by alushenk          #+#    #+#             */
/*   Updated: 2016/11/21 16:53:55 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *usrc;
	unsigned char *udst;

	usrc = (unsigned char*)src;
	udst = (unsigned char*)dst;
	if (udst == usrc)
		return (dst);
	while (n--)
		*(udst++) = *(usrc++);
	return (dst);
}
