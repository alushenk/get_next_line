/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 17:20:29 by alushenk          #+#    #+#             */
/*   Updated: 2016/11/27 17:20:31 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	words_count(const char *s, char c)
{
	size_t	result;
	char	is_word;

	result = 0;
	is_word = 1;
	while (*s)
	{
		if (*s == c && !is_word)
			is_word = 1;
		if (*s != c && is_word)
		{
			is_word = 0;
			result++;
		}
		s++;
	}
	return (result);
}

static	void	replace(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			*s = '\0';
		s++;
	}
}

static	void	assign(char *str, char **result, size_t count)
{
	if (count--)
	{
		while (!*str)
			str++;
		*result = ft_strdup(str);
		result++;
		while (*str)
			str++;
		assign(str, result, count);
	}
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	count;
	char	**result;
	char	*str;

	if (s && (str = ft_strdup(s)))
	{
		replace(str, c);
		count = words_count(s, c);
		if ((result = (char**)malloc(sizeof(char*) * count + 1)))
		{
			result[count] = NULL;
			assign(str, result, count);
			return (result);
		}
	}
	return (NULL);
}
