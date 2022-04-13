/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:07:44 by maolivei          #+#    #+#             */
/*   Updated: 2022/04/13 13:21:12 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = malloc(s1_len + s2_len + 1);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, s1_len + 1);
	ft_strlcat(str, s2, s1_len + s2_len + 1);
	free(s1);
	return (str);
}

static int	ft_read(int fd, char *chr_buffer, char *str_buffer)
{
	size_t	size;
	int		read_ret;

	size = 0;
	while (size < BUFFER_SIZE)
	{
		read_ret = read(fd, chr_buffer, 1);
		if (read_ret < 1)
			break ;
		if (*chr_buffer != '\n')
			str_buffer[size] = *chr_buffer;
		if (*chr_buffer == '\n')
		{
			str_buffer[size] = '\n';
			break ;
		}
		size++;
	}
	if (size >= BUFFER_SIZE || read_ret < 1)
		str_buffer[size] = '\0';
	else if (str_buffer[size] == '\n')
		str_buffer[size + 1] = '\0';
	if (read_ret > 0 && *chr_buffer != '\n')
		return (1);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	chr_buffer;
	char		*str_buffer;
	char		*dup;

	if (fd < 0)
		return (NULL);
	str_buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str_buffer)
		return (NULL);
	dup = NULL;
	while (ft_read(fd, &chr_buffer, str_buffer) || *str_buffer)
	{
		if (!dup)
			dup = ft_strdup(str_buffer);
		else
			dup = ft_strjoin_free(dup, str_buffer);
		if (chr_buffer == '\n')
			break ;
		ft_memset(str_buffer, 0, ft_strlen(str_buffer));
	}
	free(str_buffer);
	str_buffer = NULL;
	return (dup);
}
