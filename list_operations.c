/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:41:11 by nmagdano          #+#    #+#             */
/*   Updated: 2024/02/23 18:00:20 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_llstsize(tt_list *lst)
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

tt_list	*ft_llstlast(tt_list *lst)
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

tt_list	*init_list(int i)
{
	tt_list	*nlist;

	nlist = malloc(sizeof(tt_list) * 1);
	nlist -> prev = NULL;
	nlist -> data = i;
	nlist ->next = NULL;
	return (nlist);
}

tt_list	*add_node(tt_list *nlist, int data)
{
	tt_list	*new;

	new = malloc(sizeof(tt_list));
	new -> prev = nlist;
	new -> data = data;
	new -> next = NULL;
	return (new);
}
