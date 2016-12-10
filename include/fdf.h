#ifndef FDF_H
# define FDF_H
# define LP t_point

#include "libft.h"

typedef struct s_point	t_point;
struct					s_point
{
	int	x;
	int	y;
	int	height;
	LP	*next;
};

/*
***** parser
*/

int						parse_map(LP **first, char *map);

#endif
