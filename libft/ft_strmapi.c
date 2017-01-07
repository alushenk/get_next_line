/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 18:47:09 by alushenk          #+#    #+#             */
/*   Updated: 2016/11/26 18:47:11 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	size_t	i;

	result = NULL;
	i = 0;
	if (s && f)
	{
		result = ft_strnew(ft_strlen(s));
		if (result)
		{
			while (s[i])
			{
				result[i] = f(i, s[i]);
				i++;
			}
		}
	}
	return (result);
}
