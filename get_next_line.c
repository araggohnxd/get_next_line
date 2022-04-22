/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:07:44 by maolivei          #+#    #+#             */
/*   Updated: 2022/04/22 13:52:11 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_handle_buffer(char *buffer)
{
	size_t		i;
	size_t		j;
	char		*str;

	i = 0;
	j = 0;
	while (buffer[i] != '\n')
		i++;
	ft_strlcpy(buffer, &buffer[i + 1], BUFFER_SIZE - i);
	if (!*buffer)
		return (NULL);
	str = malloc(sizeof(char) * (BUFFER_SIZE - i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		str[j++] = buffer[i++];
	if (buffer[i] == '\n')
		str[j++] = '\n';
	str[j] = '\0';
	return (str);
}

static char	*ft_realloc(char *str, size_t length)
{
	char	*tmp;

	if (!str)
		str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	else
	{
		tmp = malloc(sizeof(char) * (length + BUFFER_SIZE + 1));
		ft_strlcpy(tmp, str, length + 1);
		free(str);
		str = tmp;
	}
	if (!str)
		return (NULL);
	return (str);
}

static char	*ft_read(int fd, char *buffer, char *str)
{
	size_t	i;
	size_t	j;
	int		read_ret;

	j = ft_strlen(str);
	read_ret = BUFFER_SIZE;
	while (read_ret == BUFFER_SIZE)
	{
		i = 0;
		read_ret = read(fd, buffer, BUFFER_SIZE);
		if (read_ret < 1)
			break ;
		buffer[read_ret] = '\0';
		str = ft_realloc(str, j);
		while (buffer[i] != '\n' && buffer[i])
			str[j++] = buffer[i++];
		if (buffer[i] == '\n')
			str[j++] = '\n';
		str[j] = '\0';
		if (read_ret < BUFFER_SIZE || buffer[i] == '\n')
			break ;
	}
	if (read_ret < 1 && !str)
		return (NULL);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*str;

	if (fd < 0 || fd > MAX_FD_VALUE || BUFFER_SIZE < 1)
		return (NULL);
	str = NULL;
	if (ft_strchr(buffer, '\n'))
	{
		str = ft_handle_buffer(buffer);
		if (ft_strchr(str, '\n'))
			return (str);
	}
	return (ft_read(fd, buffer, str));
}
