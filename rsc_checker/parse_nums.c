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

#include "checker.h"

int	split_parse_fill_argv_ch(char *argv, t_llist **stack1)
{
	char	**str;

	str = ft_split(argv, ' ');
	if (!(str))
		return (ft_exit(*stack1, NULL, NULL, 1));
	if (!(fill_stack1_argv(str, stack1)))
	{
		ft_cleanstr_ext(str, ft_splsize(str));
		return (ft_exit(*stack1, NULL, NULL, 1));
	}
	return (1);
}

int	more_args_ch(int argc, char *argv[], t_llist **stack1)
{
	argc--;
	argv++;
	while (argc >= 2)
	{
		if (!(split_parse_fill_argv_ch(*argv, stack1)))
			return (0);
		argc--;
		argv++;
	}
	return (1);
}

int	fill_num_stack(char **str, t_llist **stack1)
{
	t_llist	*head;
	char	**str_h;

	str_h = str;
	(*stack1)->prev = *stack1;
	(*stack1)->data = ft_atoi(*str);
	(*stack1)->next = *stack1;
	head = *stack1;
	str++;
	while (*str != NULL)
	{
		if (!(fill_str(stack1, head, str, str_h)))
			return (0);
		str++;
	}
	head->prev = *stack1;
	(*stack1)->next = head;
	*stack1 = head;
	str = str_h;
	ft_cleanstr_ext(str, ft_splsize(str));
	return (1);
}

int	ft_parse_input_ch(int argc, char *argv[], t_llist **stack1)
{
	char	**str;

	str = (check_frst_arg(argc, argv, stack1));
	if (!(str))
	{
		free(str);
		str = NULL;
		return (0);
	}
	if ((!(verify_argv(NULL, *str))))
	{
		ft_cleanstr_ext(str, ft_splsize(str));
		free(*stack1);
		return (ft_exit(NULL, NULL, NULL, 1));
	}
	if (!fill_num_stack(str, stack1))
		return (0);
	argv++;
	if (!(more_args_ch(argc, argv, stack1)))
		return (0);
	return (1);
}
