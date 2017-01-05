//
// Created by Anton Lushenko on 12/27/16.
//

#include "get_next_line.h"
#include "libft.h"

t_fd    *get_fd(t_fd *list, int fd)
{
    if (list)
    {
        while (list)
        {
            if (list->fd == fd)
                return (list);
            list = list->next;
        }
    } else
    {
        list = (t_fd*)malloc(sizeof(t_fd));
        if (list)
        {
            list->fd = fd;
            list->next = NULL;
            return (list);
        }
    }
    return (NULL);
}

int get_next_line(const int fd, char **line)
{
	static t_fd *list;
    t_fd        *elem;

	char		*temp;
	ssize_t		len;
	size_t		temp_size;
	ssize_t		bytes_read;

	bytes_read = 0;
	temp_size = 0;
	*line = NULL;

	//подточить напильником логику так, чтобы возвращало -1
	//если одна из библиотечных функций не смогла выделить память.
    if (fd < 0 || line == NULL || BUFF_SIZE <= 0 || !(elem = get_fd(list, fd)))
        return (-1);

	//если в буфере осталось что-то с прошлого раза
	if (*elem->buf)
	{
		/*
		 **1)finding length of the line
		 **2)allocateing memory for line, which will be returned
		 **3)writing into *line bytes from buffer
		 **4)copying remaining cymbols into temporary line
		 **5)writing zeroes into old buffer
		 **6)writing remain symbols into buffer
		 **7)releasing temp
		 **8)expanding size of *line in case we will read from file again
		 */
		len = 0;
		while (elem->buf[len] != '\n' && elem->buf[len])
			len++;
        //if len == 0 ???
        *line = ft_strnew(len);
        *line = ft_strncpy(*line, elem->buf, len);
		temp = ft_strdup(elem->buf + len + 1);
		ft_bzero(elem->buf, BUFF_SIZE + 1);
		ft_strcpy(elem->buf, temp);
		free(temp);
		temp_size += len;
	}

	while ((bytes_read = read(fd, elem->buf, BUFF_SIZE)))
	{
        if (bytes_read == -1)
            return (-1);
		elem->buf[bytes_read] = '\0';
		len = 0;
		while (elem->buf[len] != '\n' && len < bytes_read)
			len++;
		temp_size += len;
		if (!*line)
		{
            *line = ft_strnew(len);
            *line = ft_strncpy(*line, elem->buf, len);
		}
		else
		{
			/*
			 **1)create temporary copy of *line
			 **2)free old *line
			 **3)create enough space for *line + elem->buf
			 **4)copy temp into *line
			 **5)concatanate elem->buf into *line
			 **6)free temporary string
			 */
			temp = ft_strdup(*line);
			free(*line);
            *line = ft_strnew(temp_size);
			*line = ft_strcpy(*line, temp);
			*line = ft_strncat(*line, elem->buf, len);
			free(temp);
		}
		if (len < bytes_read)
		{
			temp = ft_strdup(elem->buf + len + 1);
			ft_bzero(elem->buf, BUFF_SIZE + 1);
			ft_strcpy(elem->buf, temp);
			*line = *line;
			return(1);
		}
		if (len == bytes_read)
			ft_bzero(elem->buf, BUFF_SIZE + 1);
	}
	if (!*line)
        return (0);
	return (1);
}