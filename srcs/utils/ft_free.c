#include "cub3d.h"

void	free_tab_char(char **ptr, int alloc)
{
	int i;

	if (ptr != 0)
	{
		i = 0;
		while (ptr[i])
		{
			free(ptr[i]);
			i++;
		}
		if (alloc == 1)
			free(ptr);
		ptr = NULL;
	}
}

void	free_tab_nb(void **ptr, int size, int alloc)
{
	int i;

	if (ptr != 0)
	{
		i = 0;
		while (i < size)
		{
			free(ptr[i]);
			i++;
		}
		if (alloc == 1)
			free(ptr);
		ptr = NULL;
	}
}
