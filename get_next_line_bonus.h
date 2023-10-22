/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmateo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 14:01:03 by anmateo-          #+#    #+#             */
/*   Updated: 2023/10/22 14:03:29 by anmateo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 512
# endif
# if BUFFER_SIZE > 125000 || BUFFER_SIZE < 1
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 512
# endif

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

char	*ft_init_line(char *left_str, int *bytes_read);
size_t	ft_get_line_length(char *line);
char	*ft_get_line(char *line, char *left_str, int *bytes_read, int fd);
char	*get_next_line(int fd);

size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, char *src, size_t size);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_bzero(void *s, size_t n);
char	*ft_strjoin_reader(char *s1, char *s2, int *reader);

#endif
