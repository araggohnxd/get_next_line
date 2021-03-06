/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:07:44 by maolivei          #+#    #+#             */
/*   Updated: 2022/05/09 00:29:50 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/**
* @brief Handles the static buffer, erasing its contents until it reaches
* a newline. The purpose of this function is to discard data that has
* already been written to the output in previous calls to get_next_line().
* @param buffer The buffer to be handled.
* @return A string containing what is in the buffer after the newline,
* or NULL if an error occurs.
*/
static char	*ft_handle_buffer(char *buffer)
{
	size_t		i;
	char		*str;

	i = 0;
	while (buffer[i] != '\n')
		i++;
	ft_strlcpy(buffer, &buffer[i + 1], BUFFER_SIZE - i);
	if (!*buffer)
		return (NULL);
	str = malloc(sizeof(char) * (BUFFER_SIZE - i + 1));
	if (!str)
		return (NULL);
	ft_newlinecpy(str, buffer, 0);
	return (str);
}

/**
* @brief Allocates memory for an array of nmemb elements of size bytes each
* and returns a pointer to the allocated memory. The memory is set to zero.
* If nmemb or size is 0, then ft_calloc() returns either NULL,
* or a unique pointer value that can later be successfully passed to
* free(). If the multiplication of nmemb and size would result in integer
* overflow, then ft_calloc() returns an error.
* @param nmemb Number of elements that need allocation.
* @param size Size of bytes required by each element.
* @return A pointer to the allocated memory,
* or NULL if an error occurs.
*/
static void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total;

	total = nmemb * size;
	if (nmemb != 0 && total / nmemb != size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, nmemb * size);
	return (ptr);
}

/**
* @brief Reallocates and expands the memory of a string.
* @param str The string to reallocate.
* @param length The current length of the string.
* @return A pointer to the reallocated string,
* or NULL if an error occurs.
*/
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

/**
* @brief Calls function read() and write it to a buffer.
* The buffer is then copied to a string. This process is repeated
* until it reaches a newline or EOF of the given file descriptor.
* @param fd The file descriptor to read from.
* @param buffer The buffer to write what was read.
* @param str The string containing the full line.
* @return A pointer to a string containing the full line,
* or NULL if an error occurs.
*/
static char	*ft_read(int fd, char *buffer, char *str)
{
	size_t	i;
	int		read_ret;

	i = ft_strlen(str);
	read_ret = BUFFER_SIZE;
	while (read_ret == BUFFER_SIZE)
	{
		read_ret = read(fd, buffer, BUFFER_SIZE);
		if (read_ret < 1)
			break ;
		buffer[read_ret] = '\0';
		str = ft_realloc(str, i);
		i = ft_newlinecpy(str, buffer, i);
		if (read_ret < BUFFER_SIZE || str[i - 1] == '\n')
			break ;
	}
	if (read_ret < 1 && !str)
	{
		free(buffer);
		return (NULL);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buffer[MAX_FD_VALUE];
	char		*str;

	if (fd < 0 || fd >= MAX_FD_VALUE || BUFFER_SIZE < 1)
		return (NULL);
	str = NULL;
	if (!buffer[fd])
		buffer[fd] = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	else if (ft_strchr(buffer[fd], '\n'))
	{
		str = ft_handle_buffer(buffer[fd]);
		if (ft_strchr(str, '\n'))
			return (str);
	}
	str = ft_read(fd, buffer[fd], str);
	if (!str)
		buffer[fd] = NULL;
	return (str);
}
