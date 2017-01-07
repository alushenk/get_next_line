/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 20:21:19 by alushenk          #+#    #+#             */
/*   Updated: 2016/11/26 20:21:21 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	split_back(const char *str)
{
	size_t len;

	len = ft_strlen(str) - 1;
	while (str[len] == ' ' || str[len] == '\n' || str[len] == '\t')
	{
		len--;
	}
	return (len + 1);
}

char		*ft_strtrim(char const *s)
{
	char	*result;
	size_t	lenafter;
	size_t	lenbefore;

	result = NULL;
	lenbefore = 0;
	if (s)
	{
		while ((s[lenbefore] == ' ' || s[lenbefore] == '\n'
		|| s[lenbefore] == '\t') && s[lenbefore])
			lenbefore++;
		lenafter = split_back(s);
		if (lenbefore == ft_strlen(s))
			return (ft_strdup(""));
		result = (char*)malloc(lenafter - lenbefore + 1);
		if (result)
		{
			*(result + lenafter - lenbefore) = '\0';
			ft_strncpy(result, s + lenbefore, lenafter - lenbefore);
		}
	}
	return (result);
}
