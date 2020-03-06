/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 11:28:19 by adbenoit          #+#    #+#             */
/*   Updated: 2020/03/06 15:10:49 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*int		ft_len1(char *s1, char set)
{
	int	len;
	int	i;
	int count;

	i = 0;
	len = 0;
	if (s1[0] == set)
		return (-1);
	while (s1[i])
	{
		count = 0;
		while (s1[i] == set)
		{
			count++;
			i++;
		}
		if ((count % 2 == 0 && (s1[i] == set || (i != 0 && s1[i - 1] != set)))|| (count > 0 && (i == count - 1 || i == ft_strlen(s1))))
			return (-1);
		if (count != 1)
			len += count / 2;
		if (s1[i] != set)
			len++;
		i++;
	}
	return (len);
}*/

char	*ft_trim(char *s1, char set)
{
	int		i;
	int		j;
	int		len;
	char	*str;

//	if (s1 == NULL)
//		return (NULL);
	len = ft_strlen(s1);
	i = 0;
	j = 0;
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (0);
	while (s1[i])
	{
		if (s1[i] != set)
		{
			str[j] = s1[i];
			j++;
		}
		else if (s1[i] == set)
		{
			str[j] = HOLE;
			j++;
		}
		i++;
	}
	str[j] = 0;
	free(s1);
	return (str);
}
