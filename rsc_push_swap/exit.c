/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:41:11 by nmagdano          #+#    #+#             */
/*   Updated: 2024/02/29 11:48:39 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del_stack_lst(t_llist **lst)
{
	t_llist	*tmp;
	t_llist	*tmp2;
	t_llist	*prev;
	int		size;

	size = ft_llstsize(*lst);
	while (size)
	{
		tmp = (*lst)->next;
		prev = (*lst)->prev;
		if (!(*lst))
			break ;
		tmp2 = *lst;
		if (size == 1)
		{
			free(*lst);
			return ;
		}
		if (*lst)
			free(tmp2);
		(*lst) = tmp;
		prev->next = *lst;
		(*lst)->prev = prev;
		size--;
	}
}

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

int	ft_exit_ps(t_llist **st1, t_llist **st2, char **str, int flag)
{
	if (flag == 5)
	{
		free(*st1);
		ft_cleanstr_ext(str, ft_splsize(str));
		write(2, "Error\n", 6);
		return (0);
	}
	if (st1 || flag == 3)
		del_stack_lst(st1);
	if (st2 || flag == 3)
		del_stack_lst(st2);
	if (str)
		ft_cleanstr_ext(str, ft_splsize(str));
	if (flag == 1)
		write(2, "Error\n", 6);
	return (0);
}
