//
// Created by Anton Lushenko on 12/27/16.
//

#include "get_next_line.h"
#include "libft.h"

int get_next_line(const int fd, char **line)
{
	static char buf[BUFF_SIZE + 1];
	char		*result;
	char		*temp;
	ssize_t		len;
	size_t		temp_size;
	ssize_t		bytes_read;

	bytes_read = 0;
	temp_size = 0;
	result = NULL;

	//подточить напильником логику так, чтобы возвращало -1
	//если одна из библиотечных функций не смогла выделить память.
	if (fd < 0)
		return (-1);
	/*
	 ** тут пролистывать по статической структуре, ища нужный файл дескриптор.
	 **
	 ** в структуре можно на вяский случай сохранять индекс на котором начинаются оставшиеся символы
	 ** и колличечтво считанных байт(длинну буфера)
	 **
	 ** после считывания остатка из буфера его даже не нужно фришить, это делает read
	 */

	//если в буфере осталось что-то с прошлого раза
	if (*buf)
	{
		/*
		 **1)finding length of the line
		 **2)allocateing memory for line, which will be returned
		 **3)writing into result bytes from buffer
		 **4)copying remaining cymbols into temporary line
		 **5)writing zeroes into old buffer
		 **6)writing remain symbols into buffer
		 **7)releasing temp
		 **8)expanding size of result in case we will read from file again
		 */
		len = 0;
		while (buf[len] != '\n' && buf[len])
			len++;
		result = ft_strnew(len);
		result = ft_strncpy(result, buf, len);
		temp = ft_strdup(buf + len + 1);
		ft_bzero(buf, BUFF_SIZE + 1);
		ft_strcpy(buf, temp);
		free(temp);
		temp_size += len;
	}

	while ((bytes_read = read(fd, buf, BUFF_SIZE)))
	{
		buf[bytes_read] = '\0';
		len = 0;
		while (buf[len] != '\n' && len < bytes_read)
			len++;
		temp_size += len;
		//if it is a first step
		if (!result)
		{
			//create new null-terminated string
			result = ft_strnew(len);
			//copy buffer without \n into result
			//may be strncpy doesn't suit, because it doesn't scroll the buffer pointer for the next step
			result = ft_strncpy(result, buf, len);
		}
		else
		{
			/*
			 **1)create temporary copy of result
			 **2)free old result
			 **3)create enough space for result + buf
			 **4)copy temp into result
			 **5)concatanate buf into result
			 **6)free temporary string
			 */
			temp = ft_strdup(result);
			free(result);
			result = ft_strnew(temp_size);
			result = ft_strcpy(result, temp);
			result = ft_strncat(result, buf, len);
			free(temp);
		}
		if (len < bytes_read)
		{
			temp = ft_strdup(buf + len + 1);
			ft_bzero(buf, BUFF_SIZE + 1);
			ft_strcpy(buf, temp);
			*line = result;
			return(1);
		}
		if (len == bytes_read)
			ft_bzero(buf, BUFF_SIZE + 1);
	}
	if (result)
	{
		*line = result;
		return (1);
	}
	return (0);
}