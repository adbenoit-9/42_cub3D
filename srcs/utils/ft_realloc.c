/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:40:52 by adbenoit          #+#    #+#             */
/*   Updated: 2020/03/05 15:19:00 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_realloc(char *ptr, int newsize)
{
	char *newptr;

	if (ptr == 0)
		return (malloc(sizeof(char) * newsize));
	newptr = malloc(sizeof(char) * newsize);
	ft_memcpy(newptr, ptr, newsize);
	free(ptr);
	return (newptr);
}

char	**realloc_tab(char **ptr, int newsize)
{
	char	**newptr;
	int		i;

	i = 0;
	if (!(newptr = malloc(sizeof(char *) * newsize)))
		return (NULL);
	if (ptr == 0)
	{
		newptr[1] = 0;
		return (newptr);
	}
	while (i < newsize - 2)
	{
		if (!(newptr[i] = ft_realloc(ptr[i], ft_strlen(ptr[i]) + 1)))
			return (NULL);
		i++;
	}
	newptr[i + 1] = 0;
	free(ptr);
	return (newptr);
}

double	**realloc_doub(double **ptr, int newsize)
{
	double	**newptr;
	int		i;

	i = 0;
	if (!(newptr = malloc(sizeof(double *) * newsize)))
		return (NULL);
	if (ptr == 0)
	{
		if (!(newptr[0] = malloc(sizeof(double) * 2)))
			return (NULL);
		return (newptr);
	}
	while (i < newsize - 1)
	{
		if (!(newptr[i] = malloc(sizeof(double) * 2)))
			return (NULL);
		newptr[i][X] = ptr[i][X];
		newptr[i][Y] = ptr[i][Y];
		i++;
	}
	if (!(newptr[i] = malloc(sizeof(double) * 2)))
		return (NULL);
	while (i < newsize - 2)
		free(ptr[i]);
	free(ptr);
	return (newptr);
}

void	free_tab(char **tab)
{
	int i;

	if (tab)
	{
		i = 0;
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
		tab = NULL;
	}
}
