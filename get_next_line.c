/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmateo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:49:23 by anmateo-          #+#    #+#             */
/*   Updated: 2023/10/16 10:50:04 by anmateo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*get_next_line(int fd)
{
	static char	*left_str;
	char		*line;
	char		*buffer;
	int			bytes_readed;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buffer)
			return (NULL);
	bytes_readed = 1;
	while (!ft_strchr(left_str, '\n') && bytes_readed != 0)
	{
		bytes_readed = read(fd, buffer, BUFFER_SIZE);
		if (bytes_readed == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_readed] = '\0';
		if (!left_str)
			left_str = ft_strjoin(left_str, buffer);
		else
		{
			char *temp = ft_strjoin(left_str, buffer);
			free(left_str);
			left_str = temp;
		}
	}
	free(buffer);
	if (!left_str)
		return (NULL);
	line = ft_get_line(left_str);
	left_str = ft_next_left_str(left_str);
	return (line);
}

char	*ft_get_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

size_t	get_next_str_length(char *str)
{
	size_t	i;
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

char	*ft_next_left_str(char *str)
{
	size_t	next_str_size;
	int		d;
	char	*left_str = NULL;

	next_str_size = get_next_str_length(str);
	if (!str[next_str_size])
	{
		free(str);
		return (NULL);
	}
	left_str = malloc(sizeof(char) * (ft_strlen(str) - next_str_size + 1));
	if (!left_str)
		return (NULL);
	next_str_size++;
	d = 0;
	while (str[next_str_size])
	{
		left_str[d] = str[next_str_size];
		d++;
		next_str_size++;
	}
	left_str[d] = '\0';
	free(str);
	return (left_str);
}
