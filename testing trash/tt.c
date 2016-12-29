#include "libft/libft.h"
#include <stdio.h>

int	main(void)
{
	char  *save;
	char  *std;

	save = ft_strdup("1234567890A0987654321");
	std = ft_strchr(save, 'A');
	printf("save: %s\n", save);	
	printf("std pts: %s\n", std);
	if (std != NULL)
	{
		*std = '\0';
		std++;
		ft_strdup(save);
		printf("save: %s\n", save);	
		printf("std++: %s\n", std);
		ft_strncpy(save, std, ft_strlen(std));
	}
	printf("ft_strlen(std) + 1: %zu\n", ft_strlen(std) + 1);
	printf("save: %s\n", save);	
	return (0);
}
