#include "fdf.h"
#include "stdio.h"

LP	*new_point(int x, int y, int z, int num)
{
	LP *new;

	if(!(new = (LP *)malloc(sizeof(LP))))
		return(NULL);
	new->x = x;
	new->y = y;
	new->z = z;
	new->num = num;
	new->next = NULL;
}


LP	*push_point(LP **curr, int x, int y, int z)
{
	static int num = 0;
	LP *temp;

	num += 1;
	if(!*curr)
		return((*curr = new_point(x, y, z, num)));
	temp = *curr;
	while(temp->next)
		temp = temp->next;
	return((temp->next = new_point(x, y, z, num)));
}

void print_point(LP *first)
{
	while(first)
	{
		printf("Point numero: %d. (Z=%d, X=%d, Y=%d)\n", first->num, first->x, first->y, first->z);
		first = first->next;
	}
}
