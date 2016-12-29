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
	*dst = ft_strnew(len);
	*dst = ft_strncpy(*dst, src, len);
	return (len);
}

static int 		ft_nmove(t_list **list, char **line, size_t nbt)
{
	size_t		btn;
	size_t		bic;

	bic = ft_strlen((*list)->content);
	if (nbt < BUFF_SIZE && !bic)
		return (0);
	btn = ft_copy_to_nline((*list)->content, line);
	printf("btn: %zu\n", btn + 1);
	if (btn < bic)
		(*list)->content += (btn + 1);
	else
		ft_strclr((*list)->content);
	return (1);
}	

static void		ft_re_alloc(t_list **list, size_t len, char *add)
{
	size_t	ln;
	char	*tmp;

	printf("IN List rght now: %s\n", (*list)->content);
	tmp = ft_strdup((*list)->content);
	printf("tmp: %s\n", tmp);
	ln = ft_strlen((*list)->content) + len + 1;
	printf("LENGHT :%zu\n", ft_strlen((*list)->content));
	printf("LENGHT OF BUFF :%zu\n", ft_strlen(add));
	printf("LN: %zu\n", ln);
	if (ft_strlen((*list)->content) == 18)
		free((*list)->content -= 14);
	if (ft_strlen((*list)->content) == 33)
		free((*list)->content -= 17);
	(*list)->content = (char*)malloc((sizeof(char)) * ln);
	ft_bzero((*list)->content, ln);
	(*list)->content = ft_strcpy((*list)->content, tmp);
	free(tmp);
	ft_strlcat((*list)->content, add, ln);
	printf("LENGHT after strlcat:%zu\n", ft_strlen((*list)->content));
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
		ft_re_alloc(&chunk, nbytes, buf);
		if (ft_strchr(buf, '\n'))
			break;
	}
	return (ft_nmove(&chunk, line, nbytes));
}