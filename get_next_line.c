/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:07:44 by maolivei          #+#    #+#             */
/*   Updated: 2022/04/18 00:10:24 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_newline(char *str, char *buffer, size_t size)
{
	while (*buffer && size--)
	{
		*str++ = *buffer;
		if (*buffer++ == '\n')
		{
			*str = '\0';
			return (1);
		}
	}
	return (0);
}

static int	ft_newline_index(char *buffer)
{
	size_t	i;

	i = 0;
	while (buffer[i] != '\n' && buffer[i])
	{
		i++;
		if (buffer[i] == '\n')
			return (i + 1);
	}
	if (buffer[i] == '\n')
		return (i + 1);
	return (0);
}

static char	*ft_expand_memory(char *str, size_t length, size_t add)
{
	char	*ptr;

	ptr = malloc(sizeof(char) * (length + add));
	ft_memcpy(ptr, str, (length + add));
	if (str)
		free(str);
	return (ptr);
}

static char	*ft_read(int fd, char *buffer, char *str, size_t *length)
{
	size_t	bytes_read;

	bytes_read = BUFFER_SIZE;
	while (bytes_read == BUFFER_SIZE)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		str = ft_expand_memory(str, *length, bytes_read);
		if (bytes_read < BUFFER_SIZE)
			str[(*length + bytes_read)] = '\0';
		else if (bytes_read)
			if (ft_newline((str + *length), buffer, BUFFER_SIZE))
				break ;
		*length += bytes_read;
	}
	return (str);
}

char	*get_next_line(int fd)
{
	size_t		length;
	size_t		i;
	char		*str;
	static char	buffer[BUFFER_SIZE + 1];

	str = NULL;
	length = 0;
	if (*buffer)
	{
		i = ft_newline_index(buffer);
		str = ft_expand_memory(&buffer[i], BUFFER_SIZE - i, 1);
		if (ft_newline_index(str))
		{
			ft_newline(str, &buffer[i], BUFFER_SIZE);
			ft_memcpy(buffer, &buffer[i], BUFFER_SIZE);
			return (str);
		}
		length = ft_strlen(str);
	}
	str = ft_read(fd, buffer, str, &length);
	return (str);
}

#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int fd = open("get_next_line.c", O_RDONLY);
	char *xar;

	for (int i = 0; i < 123; i++) {
		xar = get_next_line(fd);
		// printf("%s", xar);
		printf("LINE %3d:%s", i+1, xar);
		free(xar);
	}
	close(fd);
}
