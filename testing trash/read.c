#include "libft/libft.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int ac, char **av)
{
	int	ret;
	int	fd;
	char	buf[10];	

	ret = 0;	
	if ((fd = open(av[1], O_RDONLY)) == -1 )
		return (printf("Errour: open()\n"));
	while ((ret = read(fd, buf, 9)))
	{
		buf[ret] = '\0';
		printf ("buff: %s\n", buf); 
	}
	if (!close(fd))
		return (printf("Errour: close()\n"));
	return (0);
}

