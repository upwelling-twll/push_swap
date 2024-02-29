/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_or_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:41:11 by nmagdano          #+#    #+#             */
/*   Updated: 2024/02/29 11:07:55 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del_stack_lst(tt_list **lst)
{
	tt_list	*tmp;
	tt_list	*tmp2;
	tt_list	*prev;
	int		size;

	size = ft_llstsize(*lst);
	//printf("size=%i\n", size);
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
	//printf("del done\n");
}

int	check_overflow(const char *str, int flag, int i)
{
	long long	n;
	long long	cn;

	n = 0;
	cn = 0;
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
	if (str[i] == '-' && str[i + 1] != '\0')
		i++;
	while (str[i])
	{
		if (!(ft_isdigit(str[i])))
			return (0);
		i++;
	}
	i = 0;
	if (str[i] == '-')
	{
		flag = -1;
		i++;
	}
	return (check_overflow(str, flag, i));
}

int	verify_argv(tt_list *args_lst, char *str)
{
	int	num;
	int	size;

	if (!(verify_atoi(str)))
	{
		//printf("atoi return 0");
		return (0);
	}
	num = ft_atoi(str);
	//printf("str=%s\n", str);
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
	//printf("first ok\n");
	return (1);
}

int	ft_splsize(char **str)
{
	//printf("what is str size\n");
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
	//printf("clean str\n");
	//printf("size str = %li\n", n);
	size_t	i;

	if (arr)
	{
		i = 0;
		while (i < n)
		{
			//printf("will del: %s\n", arr[i]);
			//printf("next del: %s\n", arr[i+1]);
			if (arr[i] != NULL)
				free(arr[i]);
			i++;
		}
		free(arr);
	}
	//printf("str cleaned\n");
	return ;
}

int	ft_exit_ps(tt_list **st1, tt_list **st2, char **str, int flag)
{
	//printf("cleaning\n");
	//print_list(*st1);
	// printf("str=%s\n", *str);
	// printf("str2=%s\n", *(str+1));
	//printf("flag=%i\n", flag);
	if (flag == 5)  //5 means stack1 is empty
	{
		free(*st1);
		//printf("will clean str\n");
		ft_cleanstr_ext(str, ft_splsize(str));
		write(2, "Error\n", 6);
		return (0);
	}
	if (st1 || flag == 3)
		del_stack_lst(st1);
	//printf("st1 cleaned\n");
	if (st2 || flag == 3)
		del_stack_lst(st2);
	//printf("str=%s\n", *str);
	if (str)
		ft_cleanstr_ext(str, ft_splsize(str));
	if (flag == 1)
		write(2, "Error\n", 6);
	//printf("all cleaned\n");
	return (0);
}
