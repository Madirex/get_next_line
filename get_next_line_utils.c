/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmateo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:31:27 by anmateo-          #+#    #+#             */
/*   Updated: 2023/10/20 14:42:39 by anmateo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	c;

	c = 0;
	while (str[c] != '\0')
		c++;
	return (c);
}

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	count;
	int		str_len;

	count = 0;
	str_len = 0;
	while (*(src + str_len))
		str_len++;
	if (size == 0)
		return (str_len);
	while (count < size - 1 && *(src + count))
	{
		*(dest + count) = *(src + count);
		count++;
	}
	*(dest + count) = '\0';
	return (str_len);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned const char	*a;
	unsigned char		*b;
	size_t				i;

	a = (unsigned char *)src;
	b = (unsigned char *)dst;
	i = 0;
	while (!n || dst == src)
		return (dst);
	while (n > i)
	{
		b[i] = a[i];
		i++;
	}
	return (dst);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned long	i;
	char			*string;

	string = (char *)s;
	i = 0;
	while (i < n)
	{
		string[i] = 0;
		i++;
	}
}

char	*ft_strjoin_reader(char *s1, char *s2, int *reader)
{
	char	*result;
	size_t	size1;
	size_t	size2;

	if (!s1 || !s2)
		return (NULL);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	result = malloc((size1 + size2 + 1) * sizeof(char));
	if (!result)
	{
		free(s1);
		return (NULL);
	}
	ft_memcpy(result, s1, size1);
	free(s1);
	ft_memcpy(result + size1, s2, size2 + 1);
	if (size1 + size2 > 0 && *(result + size1 + size2 - 1) == '\n')
		*reader = 0;
	return (result);
}
