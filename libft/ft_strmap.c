/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 18:18:21 by alushenk          #+#    #+#             */
/*   Updated: 2016/11/26 18:18:24 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
				result[i] = f(s[i]);
				i++;
			}
		}
	}
	return (result);
}
