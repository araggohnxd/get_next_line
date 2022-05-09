/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:07:44 by maolivei          #+#    #+#             */
/*   Updated: 2022/05/09 00:29:57 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>

# define MAX_FD_VALUE 1024

// get_next_line
/**
* @brief Read and return a line from a given file descriptor.
* Consecutive calls to this function will return the next line of the file
* descriptor, until EOF.
* @param fd The file descriptor to read from.
* @return A pointer to a string containing the line read,
* or NULL if EOF is reached or an error occurs.
*/
char	*get_next_line(int fd);

// utils
/**
* @brief Returns a pointer to the first occurrence
* of the character c in the string s
* (interpreted as unsigned char).
* @param s String to be searched.
* @param c Character to search for.
* @return A pointer to the first occurrence of c in s or NULL if not found.
*/
char	*ft_strchr(const char *s, int c);

/**
* @brief Fills the first n bytes of the memory area
* pointed to by s with the constant byte c.
* @param s Memory area to fill.
* @param c Byte to fill with.
* @param n Number of bytes to fill.
* @return A pointer to the memory area s.
*/
void	*ft_memset(void *s, int c, size_t n);

/**
* @brief Calculates the length of the string pointed to by s,
* excluding the terminating null byte ('\0').
* @param s String to calculate length of.
* @return The number of bytes in the string pointed to by s.
*/
size_t	ft_strlen(const char *s);

/**
* @brief Copies up to size - 1 characters from the NUL-terminated
*  string src to dst, NUL-terminating the result.
* @param dst Destination string.
* @param src Source string.
* @param size Size in bytes of the full buffer
* (src length + 1 for the null byte).
* @return The total length of the string it tried to create
* (src length).
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

/**
* @brief Copies a string src to a dst until it reaches a newline.
* The copying starts at the index received as a parementer.
* @param dst Destination string.
* @param src Source string.
* @param index Index of destination to copy to.
* @return The index of the end of destination string (could be interpreted
* as it's length).
*/
size_t	ft_newlinecpy(char *dst, const char *src, size_t index);

#endif
