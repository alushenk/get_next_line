/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:43:49 by alushenk          #+#    #+#             */
/*   Updated: 2016/11/28 18:43:51 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	char	*cbig;
	char	*clittle;
	size_t	llen;

	cbig = (char*)big;
	clittle = (char*)little;
	llen = ft_strlen(little);
	if (!llen)
		return (cbig);
	while (*cbig)
	{
		if (!ft_strncmp(cbig, clittle, llen))
			return (cbig);
		cbig++;
	}
	return (NULL);
}
