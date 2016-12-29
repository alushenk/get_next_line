//
// Created by Anton Lushenko on 12/27/16.
//

#include "get_next_line.h"
#include "libft.h"

int get_next_line(const int fd, char **line)
{
	static char buf[BUFF_SIZE + 1];
	char		*result;
	char 		*temp;
	int			len;
	int			temp_size;
    ssize_t      bytes_read;

	len = 0;
    bytes_read = 0;
	temp_size = BUFF_SIZE;
	result = NULL;

    /*
     * тут пролистывать по статической структуре, ища нужный файл дескриптор.
     */

    /*
     * сделать проверку если в буфере осталось что-то с прошлого раза
     *
     * в структуре можно на вяский случай сохранять индекс на котором начинаются оставшиеся символы
     * и колличечтво считанных байт(длинну буфера)
     *
     * после считывания остатка из буфера его даже не нужно фришить, это делает read
     */



	while ((bytes_read = read(fd, buf, BUFF_SIZE)))
	{
        //\0 не может быть считан из файла, логика будет работать нормально
        buf[bytes_read] = '\0';

		while (buf[len] != '\n' && len < bytes_read)
			len++;
		/*
		 * if (\n isn't in the buffer)
		 *  then
		 *      write it in the temporary result string
		 *  else
		 *      write it into the result string, return result,
		 *      and scroll result pointer into place after \n
		 *
		 *  мы не должны включать \n в результат
        */
		if (len == bytes_read)
		{
			//if it is a first step
			if (!result)
			{
				//create new string
				result = ft_strnew(bytes_read);
				//copy buffer without \n into result
				//may be strncpy doesn't suit, because it doesn't scroll the buffer pointer for the next step
				result = ft_strncpy(result, buf, bytes_read);
			}
			else
			{
				//create temporary variable to store previous result + new buffer
				temp = ft_strnew(temp_size);
				//copies data from previous result into new with larger size
                //нужна функция, пищущая result по \0. нужно нуль-терминировать result(или так как написано)
				temp = ft_strncpy(temp, result, ft_strlen(result));
				//old result is not needed
				free(result);
				//write bytes from buffer into the existing result
                //нужен strncat, или функция знающая откуда начинать(start)
				result = ft_strncpy(temp, buf, BUFF_SIZE);
				free(temp);
				//ft_memcpy(result, )
			}
		}

		temp_size += bytes_read;
	}
	*line = result;
	return (0);
}