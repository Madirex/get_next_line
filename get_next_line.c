/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmateo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:49:23 by anmateo-          #+#    #+#             */
/*   Updated: 2023/10/20 13:48:31 by anmateo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_init_line(char *left_str, int *bytes_read)
{
	size_t	i;
	char	*line;

	i = 0;
	if (!left_str)
		return (NULL);
	while (left_str[i] && left_str[i] != '\n')
		i++;
	i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	ft_memcpy(line, left_str, i);
	line[i] = '\0';
	if (i > 0 && line[i - 1] == '\n')
		*bytes_read = i - 1;
	return (line);
}

size_t	ft_get_line_length(char *line)
{
	size_t	i;

	i = 0;
	if (!line)
		return (0);
	while (i < BUFFER_SIZE)
	{
		if (line[i] == '\n' || line[i] == '\0')
			return (i + 1);
		i++;
	}
	return (i);
}

char	*ft_get_line(char *line, char *left_str, int *bytes_read, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	read_res;
	size_t	len;

	while (*bytes_read == -1)
	{
		ft_bzero(buffer, (BUFFER_SIZE + 1));
		read_res = read(fd, buffer, BUFFER_SIZE);
		if (read_res == -1)
		{
			free(line);
			ft_bzero(left_str, (BUFFER_SIZE + 1));
			return (NULL);
		}
		len = ft_get_line_length(buffer);
		ft_strlcpy(left_str, &buffer[len], (BUFFER_SIZE + 1));
		buffer[len] = '\0';
		line = ft_strjoin_reader(line, buffer, bytes_read);
		if (read_res == 0)
		{
			ft_bzero(left_str, BUFFER_SIZE + 1);
			break ;
		}
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	left_str[BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = -1;
	line = ft_init_line(left_str, &bytes_read);
	if (!line)
		return (NULL);
	ft_strlcpy(left_str, &left_str[bytes_read + 1], BUFFER_SIZE + 1);
	line = ft_get_line(line, left_str, &bytes_read, fd);
	if (!line || line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}
