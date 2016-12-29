#ifndef __GET_NEXT_LINE_H
# define __GET_NEXT_LINE_H
# define BUFF_SIZE 42
# include "libft/libft.h"

typedef struct		s_gnl
{
	char			*BRB;
	char			*PIMP;
	char			*adr;
	int				fd;
	long			nbytes;
	struct s_gnl	*next;
}					t_gnl;
int			get_next_line(const int fd, char **line);
#endif