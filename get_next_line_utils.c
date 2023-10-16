/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmateo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 10:02:49 by anmateo-          #+#    #+#             */
/*   Updated: 2023/10/08 10:07:39 by anmateo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	c;

	c = 0;
	while (str[c] != '\0')
	{
		c++;
	}
	return (c);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c || c == '\0')
		return ((char *)s);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*result;
	size_t			str_size;
	unsigned int	i;

	str_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	result = malloc(str_size * sizeof(char));
	if (result)
	{
		i = 0;
		while (*s1)
		{
			result[i] = *s1;
			i++;
			s1++;
		}
		while (*s2)
		{
			result[i] = *s2;
			i++;
			s2++;
		}
		result[i] = '\0';
	}
	return (result);
}
