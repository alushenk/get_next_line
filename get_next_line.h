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

#endif //GET_NEXT_LINE_GET_NEXT_LINE_H
