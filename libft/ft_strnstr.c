/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 13:20:45 by alushenk          #+#    #+#             */
/*   Updated: 2016/11/26 13:20:46 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*cbig;
	size_t	llen;

	cbig = (char*)big;
	llen = ft_strlen(little);
	if (!llen)
		return (cbig);
	while (*cbig && len >= llen)
	{
		if (!ft_strncmp(cbig, little, llen))
			return (cbig);
		cbig++;
		len--;
	}
	return (NULL);
}
