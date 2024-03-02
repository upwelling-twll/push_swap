/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 21:49:49 by nmagdano          #+#    #+#             */
/*   Updated: 2024/02/08 14:51:44 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct new_line_bit
{
	char				*line_bit;
	size_t				len;
	struct new_line_bit	*next;
}		t_bits;

char	*get_next_line(int fd);

size_t	ft_lsbsize(t_bits *lst);
char	*ft_strcat(char *s1, const char *s2);
t_bits	*lst_magic(void *content, t_bits *lst);
char	*ft_strldup(const char *s1, ssize_t *fe);
char	*fill_line(t_bits *bits);

#endif