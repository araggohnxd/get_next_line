/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:07:44 by maolivei          #+#    #+#             */
/*   Updated: 2022/04/22 14:31:37 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>

# define MAX_FD_VALUE 1024

// get_next_line
char	*get_next_line(int fd);

// utils
char	*ft_strchr(const char *s, int c);
void	*ft_memset(void *s, int c, size_t n);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_newlinecpy(char *dst, const char *src, size_t index);

#endif
