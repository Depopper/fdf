#include "fdf.h"

#include <bsd/string.h>
int main(int ac, char **av)
{
	LP *first;
	char *dest;
	char *src;

	first = NULL;
	if(ac != 2)
		return(ft_puterr("Usage: ./fdf [map_name]"));
	if (parse_map(&first, av[1]) == -1)
		return(-1);
	print_point(first);
	strlcpy(dest, src, 5);
	return (0);
}
