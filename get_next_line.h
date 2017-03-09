/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 18:47:09 by alushenk          #+#    #+#             */
/*   Updated: 2017/01/07 18:47:19 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_GET_NEXT_LINE_H
# define GET_NEXT_LINE_GET_NEXT_LINE_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

int					get_next_line(const int fd, char **line);

# define BUFF_SIZE 600

typedef struct		s_fd
{
	int				fd;
	char			buf[BUFF_SIZE + 1];
	char			*temp;
	struct s_fd		*next;
}					t_fd;

#endif
