/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 20:44:57 by alushenk          #+#    #+#             */
/*   Updated: 2016/11/22 20:44:59 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t destlen;

	destlen = ft_strlen(dst);
	if (size > destlen)
	{
		ft_strncat(dst, src, size - destlen - 1);
		return (ft_strlen(src) + destlen);
	}
	else
		return (ft_strlen(src) + size);
}
