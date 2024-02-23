/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbg_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:41:11 by nmagdano          #+#    #+#             */
/*   Updated: 2024/02/23 17:45:12 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_itarget(i_list *lst)
{
	printf("target_data:%i\n", lst->target);
	printf("s1_rotate_up:%i\n", lst->s1_rotate_up);
	printf("s1_rotate_down:%i\n", lst->s1_rotate_down);
	printf("s2_rotate_up:%i\n", lst->s2_rotate_up);
	printf("s2_rotate_down:%i\n", lst->s2_rotate_down);
	printf("mood:%i\n", lst->mood);
}

void	print_list(tt_list *lst)
{
	tt_list	*head;

	head = lst;
	if (lst == NULL)
	{
		printf("empty\n");
		return;
	}
	printf("data:%d\n", lst->data);
	lst = lst->next;
	while(lst != head)
	{
		printf("data:%i\n", lst->data);
		lst = lst -> next;
	}
}

int	check_if_sorted_final(tt_list *lst)
{
	int	head;

	head = lst->data;
	while (lst->next->data != head)
	{
		if (lst->data < lst->next->data)
			lst = lst->next;
		else
		{
			if (lst->next->data == head)
				return (1);
			else
				return (0);
		}
	}
	return (1);
}
