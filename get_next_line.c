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
	/*
	 * тут пролистывать по статической структуре, ища нужный файл дескриптор.
	 *
	 * сделать проверку если в буфере осталось что-то с прошлого раза
	 *
	 * в структуре можно на вяский случай сохранять индекс на котором начинаются оставшиеся символы
	 * и колличечтво считанных байт(длинну буфера)
	 *
	 * после считывания остатка из буфера его даже не нужно фришить, это делает read
	 */

	temp = buf;
	while(*temp != '\n' && *temp)
		temp++;
	if (*temp == '\n')
	{
		temp++;
		result = ft_strdup(temp);
		while(*temp)
		{
			temp++;
			temp_size++;
		}
	}

	while ((bytes_read = read(fd, buf, BUFF_SIZE)))
	{
		//\0 не может быть считан из файла, логика будет работать нормально
		buf[bytes_read] = '\0';
		len = 0;
		while (buf[len] != '\n' && len < bytes_read)
			len++;
		temp_size += len;
		/*
		 *  мы не должны включать \n в результат
        */
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
			//create temporary copy of result
			temp = ft_strdup(result);
			//old result is not needed
			free(result);
			//create enough space for result + buf
			result = ft_strnew(temp_size);
			//copy temp into result
			result = ft_strcpy(result, temp);
			//concatanate buf into result
			result = ft_strncat(result, buf, len);
			//temporary string doesn't needed
			free(temp);
		}
		if (len != bytes_read)
		{
			*line = result;
			return(0);
		}
	}
	return (1);
}