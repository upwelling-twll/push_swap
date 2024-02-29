/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:41:11 by nmagdano          #+#    #+#             */
/*   Updated: 2024/02/29 18:08:04 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fill_stack1_argv(char **str, t_llist **stack1)
{
	t_llist	*head;
	char	**str_h;
	t_llist	*new_last;
	t_llist	*old_last;

	head = *stack1;
	str_h = str;
	while (*str != NULL)
	{
		if ((!(verify_argv(head, *str))))
			return (0);
		old_last = ft_llstlast(*stack1);
		new_last = add_node(*stack1, ft_atoi(*str));
		old_last->next = new_last;
		new_last->next = *stack1;
		new_last->prev = old_last;
		(*stack1)->prev = new_last;
		str++;
	}
	str = str_h;
	ft_cleanstr_ext(str, ft_splsize(str));
	*stack1 = head;
	return (1);
}

int	split_parse_fill_argv(char *argv, t_llist **stack1)
{
	char	**str;

	str = ft_split(argv, ' ');
	if (!(str))
		return (ft_exit_ps(stack1, NULL, NULL, 1));
	if (!(fill_stack1_argv(str, stack1)))
		return (ft_exit_ps(stack1, NULL, str, 1));
	return (1);
}

int	more_args(int argc, char *argv[], t_llist **stack1)
{
	argc--;
	argv++;
	while (argc >= 2)
	{
		if (!(split_parse_fill_argv(*argv, stack1)))
			return (0);
		argc--;
		argv++;
	}
	return (1);
}

void	*check_frst_arg(int argc, char *argv[], t_llist **stack1)
{
	char	**str;

	if (argc < 2)
	{
		free(*stack1);
		return (0);
	}
	argv++;
	str = ft_split(*argv, ' ');
	if (!(str) || *str == NULL)
	{
		free(*stack1);
		write(2, "Error\n", 6);
		return (0);
	}
	return (str);
}
