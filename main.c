//
// Created by Anton Lushenko on 12/27/16.
//

#include "get_next_line.h"
#include "libft.h"

int main(int argc, char **argv)
{
	int		fd1;
	int		fd2;
	int		g1;
	int		g2;
	char	*line1;
	char 	*line2;
	int 	i;

	i = 0;
	if (argc == 3)
	{
		fd1 = open(argv[1], O_RDONLY);
		fd2 = open(argv[2], O_RDONLY);
		while ((g1 = get_next_line(fd1, &line1)) && (g2 = get_next_line(fd2, &line2)))
        {
			if (g1 == -1 && g2 == -1)
				return (0);
			printf("%s\n", line1);
			printf("%s\n", line2);
            free(line1);
			free(line2);
			i++;
        }
	}
	return (0);
}