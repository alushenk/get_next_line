/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 15:57:54 by alushenk          #+#    #+#             */
/*   Updated: 2016/11/21 15:58:00 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *destination, size_t n)
{
	unsigned char	*s;

	if (n != 0)
	{
		s = (unsigned char*)destination;
		while (n--)
		{
			*s = 0;
			s++;
		}
	}
}
