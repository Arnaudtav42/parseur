#include "solong.h"
#include <unistd.h>
#include <stdlib.h>

int	ft_strrlen(char *str)
{
	int	i;

	i = 0;
	if (str)
		while (str[i] != 0)
			i++;
	return (i);
}

void	ft_strncpy(char *dst, char *src, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
	while (i < BUFFER_SIZE)
	{
		dst[i] = 0;
		i++;
	}
}		

int	ft_strchr(char *str, int *c)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE && (str[i] != '\0') && (str[i] != '\n'))
		i++;
	*c = i;
	if ((c == 0 && str[0] != '\n')
		|| (*c == BUFFER_SIZE && str[BUFFER_SIZE] != '\n') || (!str[*c]))
		return (-1);
	return (i);
}

char	*ft_strnjoin(char *dst, char *src, int n)
{
	char	*str;
	int		j;
	int		i;

	str = malloc(sizeof(*dst) * (ft_strrlen(dst) + n + 1));
	if (!str)
		return (NULL);
	j = -1;
	i = -1;
	if (dst)
	{
		while (dst[++i])
			str[i] = dst[i];
	}
	else
		i = 0;
	while (++j < n)
		str[i + j] = src[j];
	str[i + j] = 0;
	free (dst);
	return (str);
}

int	get_next_line(int fd, char **line)
{
	static char		buffer[BUFFER_SIZE + 1];
	int				count;
	int				size;

	*line = NULL;
	if (0 > fd || fd >= 128 || read(fd, buffer, 0))
		return (-1);
	while (1)
	{			
		if (ft_strchr(buffer, &count) != -1)
		{				
			*line = ft_strnjoin(*line, buffer, count);
			if (!line)
				return (-1);
			ft_strncpy(buffer, buffer + count + 1, BUFFER_SIZE - count);
			return (1);
		}
		*line = ft_strnjoin(*line, buffer, count);
		if (!line)
			return (-1);
		ft_strncpy(buffer, buffer + count + 1, BUFFER_SIZE - count);
		size = read(fd, buffer, BUFFER_SIZE);
		if (size < 1)
			return (size);
	}		
}