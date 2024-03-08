/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_supp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:41:11 by nmagdano          #+#    #+#             */
/*   Updated: 2024/03/08 14:42:28 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_if_sorted(t_llist *lst)
{
	t_llist	*head;

	if (!lst)
		return (0);
	head = lst;
	while (lst->next != head)
	{
		if (lst->data < lst->next->data)
		{
			if (lst->next != head)
				lst = lst->next;
			else
				return (1);
		}
		else
			return (0);
	}
	return (1);
}

int	ft_llstsize(t_llist *lst)
{
	int		i;
	int		head;

	if (!(lst))
		return (0);
	head = lst->data;
	i = 1;
	while (lst->next->data != head)
	{
		lst = lst -> next;
		i++;
	}
	return (i);
}

t_llist	*ft_llstlast(t_llist *lst)
{
	int	i;

	if (!lst)
		return (lst);
	i = ft_llstsize(lst);
	while (i > 1)
	{
		lst = lst->next;
		i--;
	}
	return (lst);
}

t_llist	*add_node(t_llist *nlist, int data)
{
	t_llist	*new;

	new = malloc(sizeof(t_llist));
	new -> prev = nlist;
	new -> data = data;
	new -> next = NULL;
	return (new);
}
