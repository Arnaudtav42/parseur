#include "solong.h"

int ft_parsing(char *s, t_map *map)
{
	int i;
	

	i = -1;
	while (s[++i])
	if (s[i--] == 'r')
	{
		if(s[i--] == 'e')
		{
			if (s[i--] == 'b')
			{
				if (s[i--] == '.')
				{
					map->fd = open(s, O_RDONLY);
					return 1;
				}
			}
		}
	}
	return 0;
}

int ft_parse_map(t_map *map)
{
	char *line;
	int i;
	int j;

	j = 0;
	while (get_next_line(map->fd, &line) == 1)
	{
		i = ft_strlen(line);
		map->map[j] = malloc(i + 1);
		i = 0;
		while (line[i])
		{
			map->map[j][i] = line[i];
			i++;
		}
		map->map[j][i] = '\0';
		map->width = i;
		free(line);
		j++;
	}
	map->height = j;
	ft_check_error(&map);
}

int main (int argc, char **argv)
{
	t_map map;
	if (argc == 2)
	{
		if (ft_parsing_arg(argv[1], &map))
		{
			if (ft_parse_map(&map))
			{
				printf("parsing ok");
			}
		}
		else
			write (1, "bad extensions\n", 16);

	}
	else
		write(1, "error\n", 6);


}