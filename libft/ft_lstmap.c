/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 14:50:05 by alushenk          #+#    #+#             */
/*   Updated: 2016/11/30 14:50:08 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *result;

	if (lst)
	{
		result = (t_list*)malloc(sizeof(t_list));
		if (result)
		{
			result = f(lst);
			result->next = ft_lstmap(lst->next, f);
			return (result);
		}
	}
	return (NULL);
}
