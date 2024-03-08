/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splret.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:45:01 by nmagdano          #+#    #+#             */
/*   Updated: 2024/03/08 17:57:19 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**split_ret(char **str, size_t i)
{
	if (i == 0)
		return (NULL);
	else
		str[i] = NULL;
	return (str);
}
