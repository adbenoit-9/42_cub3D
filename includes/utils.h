/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 19:04:45 by adbenoit          #+#    #+#             */
/*   Updated: 2020/07/05 22:24:03 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "get_next_line.h"
# define BUFFER_SIZE 4096

double			**realloc_doub(double **ptr, int newsize);
void			free_tab_char(char **ptr);
void			free_tab_nb(void **ptr, int size);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			ft_putnbr_fd(int n, int fd);
void			*ft_realloc(void *ptr, int newsize);
char			*ft_strtrim(char *s1, char const *set, int size);
char			**realloc_tab(char **ptr, int newsize);
int				ft_atoi(const char *str);
int				ft_rgb(int r, int g, int b);
int				ft_strlen(char *str);
int				ft_strncmp(char *s1, char *s2, int n);

#endif