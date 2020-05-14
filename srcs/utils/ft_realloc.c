/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Adeline <Adeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:40:52 by adbenoit          #+#    #+#             */
/*   Updated: 2020/05/10 17:32:56 by Adeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*ft_realloc(void *ptr, int newsize)
{
	void	*newptr;

	if (ptr == 0)
		return (malloc(newsize));
	newptr = malloc(newsize);
	ft_memcpy(newptr, ptr, newsize);
	free(ptr);
	ptr = NULL;
	return (newptr);
}

char	**realloc_tab(char **ptr, int newsize)
{
	char	**newptr;
	int		i;

	i = 0;
	if (!(newptr = malloc(sizeof(char *) * newsize)))
		return (NULL);
	while (i < newsize - 2)
	{
		if (!(newptr[i] = (char *)ft_realloc(ptr[i], ft_strlen(ptr[i]) + 1)))
			return (NULL);
		i++;
	}
	newptr[i + 1] = 0;
	if (ptr != 0)
	free(ptr);
	ptr = NULL;
	return (newptr);
}

double	**realloc_doub(double **ptr, int newsize)
{
	double	**newptr;
	int		i;

	i = 0;
	if (!(newptr = malloc(sizeof(double *) * newsize)))
		return (NULL);
	while (i < newsize - 1)
	{
		if (!(newptr[i] = (double *)ft_realloc(ptr[i], sizeof(double) * 2)))
			return (NULL);
		i++;
	}
	if (!(newptr[i] = (double *)malloc(sizeof(double) * 2)))
		return (NULL);
	if (ptr != 0)
		free(ptr);
	ptr = NULL;
	return (newptr);
}
