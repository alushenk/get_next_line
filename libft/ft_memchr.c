/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:10:04 by alushenk          #+#    #+#             */
/*   Updated: 2016/11/22 15:10:11 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *ns;
	unsigned char sym;

	ns = (unsigned char*)s;
	sym = (unsigned char)c;
	while (n--)
	{
		if (*ns == sym)
			return (ns);
		ns++;
	}
	return (NULL);
}
