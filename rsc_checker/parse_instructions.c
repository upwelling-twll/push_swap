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

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (*(s1 + i) != '\0')
	{
		if (*(s1 + i) == *(s2 + i))
		{
			i++;
		}
		else if (*(s1 + i) > *(s2 + i))
			return (1);
		else if (*(s1 + i) < *(s2 + i))
			return (-1);
	}
	if (*(s1 + i) == *(s2 + i))
		return (0);
	if (*(s1 + i) > *(s2 + i))
		return (1);
	return (-1);
}

t_chins	*add_node_ins(t_chins *lst, char *ins)
{
	t_chins	*new;

	new = malloc(sizeof(t_chins));
	new->content = strdup(ins);
	new -> next = NULL;
	return (new);
}

char	*read_stdin(int fd, t_llist *st1, int flag)
{
	char	*str;
	char	*res;
	size_t	len;

	str = get_next_line(fd);
	if (str)
	{
		if (ft_strchr(str, '\n'))
		{
			res = malloc(sizeof(char) * ft_strlen(str));
			ft_strlcpy(res, str, ft_strlen(str));
			free(str);
			return (res);
		}
		else
		{
			free(str);
			return (NULL);
		}
	}
	return (other_str(str, st1, flag));
}

int	parse_instr(t_llist **lst, t_chins **oper)
{
	char	*ins;
	t_chins	*hoper;

	ins = read_stdin(0, *lst, 1);
	if (!ins)
		return (ft_exit(*lst, NULL, NULL, 2));
	else if (!(ft_strcmp(ins, "OK")))
		return (ft_exit(*lst, NULL, NULL, 3));
	*oper = add_node_ins(*oper, ins);
	hoper = *oper;
	while (ins != NULL)
	{
		free(ins);
		ins = read_stdin(0, *lst, 0);
		if (!ins)
			break ;
		(*oper)->next = add_node_ins(*oper, ins);
		*oper = (*oper)->next;
	}
	*oper = hoper;
	return (1);
}
