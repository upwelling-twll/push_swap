/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_analysis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:41:11 by nmagdano          #+#    #+#             */
/*   Updated: 2024/02/23 18:41:06 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_sorted(tt_list *lst)
{
	tt_list	*head;

	//printf("check if sorted\n");
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
	//printf("check complited\n");
	return (1);
}

void	float_ra(tt_list **head, int position)
{
	while (position)
	{
		ra(head, NULL);
		write(1, "ra\n", 3);
		position--;
	}
}

void	float_rra(tt_list **head, tt_list *new_head, int position)
{
	position = ft_llstsize(*head) - position - 1;
	while ((*head)->data != new_head->data)
	{
		rra(head, NULL);
		write(1, "rra\n", 4);
	}
}

void	float_to_top(tt_list **head, tt_list *new_head)
{
	tt_list	*cplist;
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

void	min_to_top(tt_list **lst)
{
	tt_list	*min;

	min = get_min(*lst, ft_llstsize(*lst));
	float_to_top(lst, min);
}
