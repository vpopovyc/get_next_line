#include "get_next_line.h"

static void		ft_gnlnew(t_gnl **list, const int fd)
{
	if (((*list) = (t_gnl*)malloc(sizeof(t_gnl))) == NULL)
		return ;
	(*list)->BRB = NULL;
	(*list)->PIMP = ft_strnew(0);
	(*list)->next = NULL;
	(*list)->fd = fd;
	(*list)->nbytes = 0;
}

static void		ft_gnl_pushback(t_gnl **list, t_gnl *fdnode)
{
	t_gnl	*head;

	head = *list;
	while (head->next != NULL)
		head = head->next;
	head->next = fdnode;
}

static t_gnl 	*ft_get_chunk(t_gnl **list, const int fd)
{
	t_gnl	*head;

	head = *list;
	while (head)
	{
		if (head->fd == fd)
			return (head);
		head = head->next;
	}
	ft_gnlnew(&head, fd);
	ft_gnl_pushback(list, head);
	return (head);
}

static int		ft_nmove(t_gnl **ls, char **line)
{
	if (ft_strlen((*ls)->PIMP) > 0)
	{
		if ((*ls)->adr != NULL)
			*((*ls)->adr) = '\0';	
		*line = ft_strdup((*ls)->BRB);
		if ((*ls)->adr != NULL)		
			ft_strncpy((*ls)->BRB, ++(*ls)->adr, ft_strlen((*ls)->adr) + 1);		
		else
			*((*ls)->BRB) = '\0';
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	t_gnl			*chunk;
	static t_gnl	*list_of_chunks;

	if ((fd == -1 || read(fd, buf, 0) == -1 || line == NULL || BUFF_SIZE <= 0))
		return (-1);
	if (!list_of_chunks)
		ft_gnlnew(&list_of_chunks, fd);
	chunk = ft_get_chunk(&list_of_chunks, fd);
	while (!(chunk->adr = ft_strchr(chunk->PIMP, '\n')))
	{
		if ((chunk->nbytes = read(fd, buf, BUFF_SIZE)) == -1)
			return (-1);
		if (chunk->nbytes == 0)
			return (ft_nmove(&chunk, line));
		buf[chunk->nbytes] = '\0';
		chunk->BRB = ft_strjoin(chunk->PIMP, buf);
		free(chunk->PIMP);
		chunk->PIMP = chunk->BRB;
	}
	return (ft_nmove(&chunk, line));
}