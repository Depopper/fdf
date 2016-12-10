#include "fdf.h"

int main(int ac, char **av)
{
	LP *first;

	if(ac != 2)
		return(ft_puterr("Usage: ./fdf [map_name]"));
	if (parse_map(&first, av[1]) == -1)
		return(-1);
	return (0);
}
