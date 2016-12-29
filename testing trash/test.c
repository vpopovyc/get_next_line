#include "get_next_line.h"

static t_list	*ft_get_chunk(int fd, t_list **list)
{
	t_list	*head;

	head = *list;
	while (head)
	{
		if ((int)head->content_size == fd)
			return (head);
		head = head->next;
	}
	head = ft_lstnew("\0", fd);
	ft_lstadd(list, head);
	head = *list;
	return (head);
}

static size_t	ft_copy_to_nline(char *src, char **dst)
{
	size_t		len;

	len = -1;
	while (src[++len] != '\0')
		if (src[len] == '\n')
			break;
	*dst = ft_strnew(len);                 //mallo
	*dst = ft_strncpy(*dst, src, len);
	return (len);
}

static int 		ft_nmove(t_list **list, char **line, int nbt)
{
	size_t		btn;
	size_t		bic;

	bic = ft_strlen((*list)->content);
	if (nbt < BUFF_SIZE && !bic)
		return (0);
	btn = ft_copy_to_nline((*list)->content, line);
	if (btn < bic)
		(*list)->content += (btn + 1);
	else
		ft_strclr((*list)->content);
	return (1);
}	

int				get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	int 			nbytes;
	t_list			*chunk;
	static t_list	*list_of_chunks;

	if ((fd == -1 || read(fd, buf, 0) == -1 || line == NULL))
		return (-1);
	chunk = ft_get_chunk(fd, &list_of_chunks);
	while ((nbytes = read(fd, buf, BUFF_SIZE)))
	{
		buf[nbytes] = '\0';
		if ((chunk->content = ft_strjoin(chunk->content, buf)) == 0) //LEAK
			return (-1);
		if (ft_strchr(buf, '\n'))
			break;
	}
	return (ft_nmove(&chunk, line, nbytes));
}
