/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 17:03:11 by alushenk          #+#    #+#             */
/*   Updated: 2016/11/22 17:03:19 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *ptr;

	ptr = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (ptr)
		return (ft_strcpy(ptr, s1));
	else
		return (NULL);
}
