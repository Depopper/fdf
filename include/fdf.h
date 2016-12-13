#ifndef FDF_H
# define FDF_H
# define LP t_point

#include "libft.h"
#include <bsd/string.h>

typedef struct s_point	t_point;
struct					s_point
{
	int	x;
	int	y;
	int	z;
	int	num;
	LP	*next;
};

/*
***** parser
*/

int						parse_map(LP **first, char *map);

/*
***** point
*/

LP						*new_point(int x, int y, int z, int num);
LP						*push_point(LP **curr, int x, int y, int z);
void					print_point(LP *first);

#endif
