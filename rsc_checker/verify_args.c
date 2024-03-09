/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:41:11 by nmagdano          #+#    #+#             */
/*   Updated: 2024/03/09 17:23:27 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_splsize(char **str)
{
	int	s;

	s = 0;
	while (*str != NULL)
	{
		str++;
		s++;
	}
	return (s);
}

void	ft_cleanstr_ext(char **arr, size_t n)
{
	size_t	i;

	if (arr)
	{
		i = 0;
		while (i < n)
		{
			if (arr[i] != NULL)
				free(arr[i]);
			i++;
		}
		free(arr);
	}
	return ;
}

int	check_overflow(const char *str, int flag, int i)
{
	long long	n;

	n = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		if (str[i] >= '0' && str[i] <= '9')
			n = n * 10 + (str[i] - '0');
		if (n * flag > 2147483647 || n * flag < -2147483648)
			return (0);
		i++;
	}
	return (1);
}

int	verify_atoi(const char *str)
{
	long long	i;
	long long	flag;

	i = 0;
	flag = 1;
	if ((str[i] == '-' || str[i] == '+') && str[i + 1] != '\0')
		i++;
	while (str[i])
	{
		if (!(ft_isdigit(str[i])))
			return (0);
		i++;
	}
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			flag = -1;
		i++;
	}
	return (check_overflow(str, flag, i));
}

int	verify_argv(t_llist *args_lst, char *str)
{
	int	num;
	int	size;

	if (!(verify_atoi(str)))
		return (0);
	num = ft_atoi(str);
	if (args_lst)
	{
		size = ft_llstsize(args_lst);
		while (size)
		{
			if (args_lst->data == num)
				return (0);
			args_lst = args_lst->next;
			size--;
		}
	}
	return (1);
}
