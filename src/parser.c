#include "fdf.h"
#include <stdio.h>
#include <fcntl.h>

static int	get_point(char **line, int *z)
{
	static char buff[10];
	int i;
	int j;

	j = 0;
	i = 0;
	ft_bzero(buff, 10);
	while((*line)[i] && ft_isalnum((*line)[i]) && j < 10)
	{
		if(ft_isdigit((*line)[i]))
		{
				buff[j] = (*line)[i];
				j++;
				i++;
		}
		else
			i++;
	}
	if(j > 9 || ((*line)[i] && i == 0))
		return (-1);
	*line += (*line)[i] ? i + 1 : i;
	*z = ft_atoi(buff);
	return(*line[0] ? 1 : 0);
}

static int	parse_line(LP **first, char *line)
{
	static int size_line = 0;
	static int y = 0;
	int tab[3] = {0,0,1}; // tab[0] = x , tab[1] = z , tab[2] = ret
	LP *curr;

	curr = NULL;
	while(tab[2] > 0)
	{
		tab[2] = get_point(&line, &(tab[1]));
		tab[0] += 1;
		curr = push_point(first, tab[0], y, tab[1]);
	}
	if(tab[2] == -1 || (size_line > 1 && size_line != tab[0]))
		return(-1);
	size_line = tab[0];
	y += 1;
	return(0);
}

static int	parse(LP **first, int fd)
{
	char *line;

	while(get_next_line(fd, &line))
	{
		if(parse_line(first, line) == -1)
		{
			ft_memdel((void **)&line);
			return(-1);
		}
		ft_memdel((void **)&line);
	}
	ft_memdel((void **)&line);
	return(0);
}

int			parse_map(LP **first, char *map)
{
	int fd;
	int ret;

	if ((fd = open(map, O_RDONLY)) < 0)
		return(ft_puterr("Map not found !"));
	ret = parse(first, fd);
	close(fd);
	if (ret != 0)
		return(ft_puterr("Map error !"));
	return(0);
}
