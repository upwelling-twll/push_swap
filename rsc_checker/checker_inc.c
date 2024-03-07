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

int	ft_olstsize(t_chins *lst)
{
	int		i;
	t_chins	*next;

	if (lst == NULL)
		return (0);
	next = lst->next;
	i = 1;
	while (next != NULL)
	{
		next = next -> next;
		i++;
	}
	return (i);
}

void	print_list_ins(t_chins *lst)
{
	if (lst == NULL)
		return ;
	while (lst != NULL)
		lst = lst -> next;
}

char	*other_str(char *str, t_llist *st1, int flag)
{
	if (flag && (!str) && (ft_llstsize(st1) == 1 || check_if_sorted(st1)))
	{
		free(str);
		return ("OK");
	}
	free(str);
	return (NULL);
}

int	fill_str(t_llist **stack1, t_llist *head, char **str, char **str_h)
{
	if ((!(verify_argv(head, *str))))
	{
		ft_cleanstr_ext(str_h, ft_splsize(str_h));
		return (ft_exit(*stack1, NULL, NULL, 1));
	}
	(*stack1)->next = add_node(*stack1, ft_atoi(*str));
	head->prev = *stack1;
	*stack1 = (*stack1)->next;
	(*stack1)->next = head;
	return (1);
}
