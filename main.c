//
// Created by Anton Lushenko on 12/27/16.
//

#include "get_next_line.h"
#include "libft.h"

int main(int argc, char **argv)
{
	int fd;
	char *line;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while (!get_next_line(fd, &line))
        {
            printf("%s\n", line);
            free(line);
        }
	}
	return (0);
}