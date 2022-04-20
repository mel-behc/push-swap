#include "push_swap.h"

static char	*m_buf(char *buf)
{
	char	*temp;
	int		i;	

	temp = NULL;
	i = 0;
	while (buf[i] != '\n' && buf[i])
		i++;
	temp = ft_strdup(&buf[i + 1]);
	buf[i + 1] = '\0';
	return (temp);
}

static char	*m_reste(char *rs, char **str)
{
	char	*temp;
	int		i;

	temp = NULL;
	i = 0;
	while (rs[i] != '\n' && rs[i])
		i++;
	temp = ft_strdup(&rs[i + 1]);
	rs[i + 1] = '\0';
	*str = ft_strjoin(*str, rs);
	return (temp);
}

static int	ft_read(int fd, char **buf)
{
	int	i;

	*buf = (char *)malloc(sizeof(char) * 10 + 1);
	if (!*buf)
		return (-1);
	i = read(fd, *buf, 10);
	if (i == -1 || i == 0)
	{
		free(*buf);
		buf = NULL;
	}
	else
		(*buf)[i] = '\0';
	return (i);
}

static char	*ft_line(int fd, char **temp, char **reste)
{
	char	*buf;
	char	*line;
	int		rd;

	buf = ft_strdup("");
	line = ft_strdup("");
	rd = 1;
	while (rd > 0 && !ft_strchr(buf, '\n'))
	{	
		line = ft_strjoin(line, buf);
		rd = ft_read(fd, &buf);
	}
	if (buf && ft_strchr(buf, '\n'))
	{
		*temp = m_buf(buf);
		line = ft_strjoin(line, buf);
	}
	if (!*line && (!*reste || !**reste) && rd <= 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*str;
	char		*temp;
	char		*str_free;
	static char	*reste;

	str = ft_strdup("");
	str_free = str;
	temp = NULL;
	if (!reste)
	{
		str = ft_line(fd, &temp, &reste);
		free(str_free);
	}
	else if (!ft_strchr(reste, '\n'))
	{
		str = ft_line(fd, &temp, &reste);
		free(str_free);
		str = ft_strjoin(reste, str);
	}
	else if (ft_strchr(reste, '\n'))
		temp = m_reste(reste, &str);
	reste = temp;
	return (str);
}