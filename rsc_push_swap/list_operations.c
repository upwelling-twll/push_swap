/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:41:11 by nmagdano          #+#    #+#             */
/*   Updated: 2024/02/29 11:43:10 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_llist	*init_list(int i)
{
	t_llist	*nlist;

	nlist = malloc(sizeof(t_llist) * 1);
	nlist -> prev = NULL;
	nlist -> data = i;
	nlist ->next = NULL;
	return (nlist);
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
