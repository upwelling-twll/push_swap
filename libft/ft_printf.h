/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 22:03:40 by nmagdano          #+#    #+#             */
/*   Updated: 2024/01/23 17:29:20 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

int		ft_numlen(long long num);
size_t	ft_putstrlen(char *s);
int		ft_print_d(int str);
int		ft_print_p(unsigned long long num);
int		ft_printf(const char *format, ...);
void	ft_putnbr_int(int n);
int		ft_putcharlen(char c);
int		ft_printf(const char *format, ...);
int		ft_print_u(unsigned int num);
int		thex(unsigned int num, int key);

#endif
