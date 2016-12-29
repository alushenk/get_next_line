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
	 * в структуре можно на вяский случай сохранять индекс на котором начинаются оставшиеся символы
	 * и колличечтво считанных байт(длинну буфера)
	 *
	 * после считывания остатка из буфера его даже не нужно фришить, это делает read
	 */

	//если в буфере осталось что-то с прошлого раза
	if (*buf)
	{
		len = 0;
		//узнаем длинну слова
		while (buf[len] != '\n' && buf[len])
			len++;
		//выделяем память под строку, которую будем возвращать
		result = ft_strnew(len);
		//записываем в нее байты из буфера
		result = ft_strncpy(result, buf, len);
		//копируем оставшиеся символы во временную строку
		temp = ft_strdup(buf + len + 1);
		//зануляем старый буфер
		ft_bzero(buf, BUFF_SIZE + 1);
		//записываем в начало буфера временную строку(остаток)
		ft_strcpy(buf, temp);
		//освобождаем temp
		free(temp);
		//расширяем размер результата на случай если мы еще будем что-то считывать
		temp_size += len;
	}

	while ((bytes_read = read(fd, buf, BUFF_SIZE)))
	{
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
		if (len < bytes_read)
		{
			temp = ft_strdup(buf + len + 1);
			ft_bzero(buf, BUFF_SIZE + 1);
			ft_strcpy(buf, temp);
			*line = result;
			return(1);
		}
	}
	//если bytes_read < BUFF_SIZE
	if (result)
	{
		*line = result;
		return (1);
	}
	return (0);
}