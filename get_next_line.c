//
// Created by Anton Lushenko on 12/27/16.
//

#include "get_next_line.h"
#include "libft.h"

int get_next_line(const int fd, char **line)
{
	static char buf[BUFF_SIZE];
	char		*result;
	char 		*temp;
	int			len;
	int			temp_size;

	len = 0;
	temp_size = BUFF_SIZE;
	result = NULL;

	while (read(fd, buf, BUFF_SIZE) == BUFF_SIZE)
	{
		while (buf[len] != '\n' && len < BUFF_SIZE)
			len++;
		//if we didn't find \n in the
		if (len == BUFF_SIZE)
		{
			//if it is a first step
			if (!result)
			{
				//create new string
				result = ft_strnew(BUFF_SIZE);
				//copy buffer without \n into result
				//may be strncpy doesn't suit, because it doesn't scroll the buffer pointer for the next step
				result = ft_strncpy(result, buf, BUFF_SIZE);
			}
			else
			{
				//create temporary variable to store previous result + new buffer
				temp = ft_strnew(temp_size);
				//copies data from previous result into new with larger size
				temp = ft_strncpy(temp, result, temp_size);
				temp += BUFF_SIZE;
				//old result is not needed
				free(result);
				//write bytes from buffer into the existing result
				result = ft_strncpy(temp, buf, BUFF_SIZE);
				free(temp);
				//ft_memcpy(result, )
			}
		}
		temp_size += BUFF_SIZE;
	}
	*line = result;
	return (0);
}