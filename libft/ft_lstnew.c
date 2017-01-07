/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 19:42:19 by alushenk          #+#    #+#             */
/*   Updated: 2016/11/28 19:42:21 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*result;

	result = (t_list*)malloc(sizeof(t_list));
	if (result)
	{
		if (!content)
		{
			result->content = NULL;
			result->content_size = 0;
		}
		else
		{
			if ((result->content = malloc(content_size)))
			{
				ft_memcpy(result->content, (char*)content, content_size);
			}
			result->content_size = content_size;
		}
		result->next = NULL;
		return (result);
	}
	return (NULL);
}
