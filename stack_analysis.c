/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_analysis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:41:11 by nmagdano          #+#    #+#             */
/*   Updated: 2024/02/29 11:46:04 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_sorted(t_llist *lst)
{
	t_llist	*head;

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

void	float_ra(t_llist **head, int position)
{
	while (position)
	{
		ra(head, NULL);
		write(1, "ra\n", 3);
		position--;
	}
}

void	float_rra(t_llist **head, t_llist *new_head, int position)
{
	position = ft_llstsize(*head) - position - 1;
	while ((*head)->data != new_head->data)
	{
		rra(head, NULL);
		write(1, "rra\n", 4);
	}
}

void	float_to_top(t_llist **head, t_llist *new_head)
{
	t_llist	*cplist;
	int		position;

	cplist = *head;
	position = 0;
	if (new_head == *head)
		return ;
	while (cplist != new_head)
	{
		cplist = cplist->next;
		position++;
	}
	if (position <= (ft_llstsize(*head) / 2))
		float_ra(head, position);
	else
		float_rra(head, new_head, position);
}

void	min_to_top(t_llist **lst)
{
	t_llist	*min;

	min = get_min(*lst, ft_llstsize(*lst));
	float_to_top(lst, min);
}
