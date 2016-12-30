
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main(int ac, char **av)
{
	int		fd;
	char	*line;

	if (ac == 1)
		fd = 0;
	else if ((fd = open(av[1], O_RDONLY)) == -1)
		return (0);
	else
	{
		while (get_next_line(fd, &line) == 1)
		{
			printf("Line output: %s\n", line);
			free(line);
		}
	}
	if (close(fd) == -1)
		return (0);
}