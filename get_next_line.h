//
// Created by Anton Lushenko on 12/27/16.
//

#ifndef GET_NEXT_LINE_GET_NEXT_LINE_H
#define GET_NEXT_LINE_GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int get_next_line(const int fd, char **line);

#define BUFF_SIZE 10000000

typedef struct      s_fd
{
    int             fd;
    char            buf[BUFF_SIZE + 1];
	char 			*temp;
    struct s_fd *next;
}                   t_fd;

#endif //GET_NEXT_LINE_GET_NEXT_LINE_H
