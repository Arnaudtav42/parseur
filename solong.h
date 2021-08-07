#ifndef SOLONG_H
# define SOLONG_H
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif


int	get_next_line(int fd, char **line);
typedef struct s_map
{
	char **map;
	int width;
	int height;
	int fd;
}				t_map;



#endif