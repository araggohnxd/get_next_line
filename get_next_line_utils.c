/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:07:43 by maolivei          #+#    #+#             */
/*   Updated: 2022/04/17 23:42:06 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*set;

	set = s;
	while (n-- > 0)
		*set++ = c;
	return (s);
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*dup;

	i = 0;
	if (!s)
		return (NULL);
	dup = malloc(ft_strlen(s) + 1);
	if (dup == NULL)
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	if (!s)
		return (size);
	while (s[size])
		size++;
	return (size);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*start_dest;
	char	*start_src;

	if (!dest || !src)
		return (dest);
	start_dest = (char *) dest;
	start_src = (char *) src;
	while (n-- > 0)
		*start_dest++ = *start_src++;
	return (dest);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	while (i < src_len && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}
